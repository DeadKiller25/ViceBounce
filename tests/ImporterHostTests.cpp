#include "../src/MusicImporter.h"
#include "../src/BeatMap.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
void Require(bool ok,const char* message){if(!ok)throw std::runtime_error(message);}
void Finish(vicebounce::MusicImporter& importer) {
    const auto deadline=GetTickCount64()+60000;
    while(GetTickCount64()<deadline) {
        const int result=importer.Poll();
        if(result>=0){Require(result==0,"child importer failed");return;}
        Sleep(20);
    }
    throw std::runtime_error("child importer timeout");
}
int wmain(int argc,wchar_t** argv){try{
    Require(argc==3,"usage: ImporterHostTests scripts-folder source-file");
    const auto folder=std::filesystem::absolute(argv[1]);
    const auto source=std::filesystem::absolute(argv[2]);
    const auto directory=folder.wstring()+L"\\";
    vicebounce::MusicImporter importer;
    importer.Configure(source.wstring(),true);
    Require(importer.Start(directory),"background CreateProcessW failed");
    Require(importer.Running(),"child process not tracked");Finish(importer);
    const auto ini=(folder/L"ViceBounce.ini").wstring();
    wchar_t path[1024]{};char bpm[64]{};
    GetPrivateProfileStringA("ViceBounce","BPM","",bpm,64, (folder/"ViceBounce.ini").string().c_str());
    Require(std::abs(std::strtod(bpm,nullptr)-135)<.1,"game ANSI scalar read failed for Unicode INI");
    GetPrivateProfileStringW(L"ViceBounce",L"MusicBeatMapFile",L"",path,1024,ini.c_str());
    std::ifstream stream(folder/path);vicebounce::BeatMap map;
    Require(map.Load(stream)&&map.Size()>200,"game could not load imported beat map");
    WritePrivateProfileStringW(L"ViceBounce",L"MusicSyncOffsetMs",L"27.5",ini.c_str());
    Require(importer.Start(directory),"second startup check failed");Finish(importer);
    GetPrivateProfileStringW(L"ViceBounce",L"MusicSyncOffsetMs",L"",path,1024,ini.c_str());
    Require(std::wstring(path)==L"27.5","startup check overwrote user calibration");
    std::cout<<"PASS: game-side child launch/poll, Unicode INI, beat map load and cache calibration preservation\n";
    return 0;
}catch(const std::exception& error){std::cerr<<"FAIL: "<<error.what()<<'\n';return 1;}}
