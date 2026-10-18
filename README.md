# ViceBounce

Make Vice City bounce to your music.

<p align="center">
  <img src="docs/demo.gif" width="420" alt="Vice City bouncing to the beat">
</p>

<p align="center">
  <a href="https://github.com/tek-95/ViceBounce/releases/latest/download/ViceBounce-0.11.zip">
    <img src="https://img.shields.io/badge/Download-ViceBounce_0.11_·_Windows_x64-2ea44f?style=for-the-badge" alt="Download ViceBounce 0.11">
  </a>
  <br>
  <sub><a href="https://github.com/tek-95/ViceBounce/releases">all releases</a></sub>
</p>

Squash and stretch cars, bikes, boats, aircraft and people — including Tommy, passengers and cutscene actors.

## Install

Requires **classic GTA Vice City Steam**, **Windows 10/11 x64** and an **ASI loader** that loads plugins from `scripts`.

Download the ZIP from [Releases](https://github.com/tek-95/ViceBounce/releases), close the game and copy its `scripts` contents into the game's `scripts` folder. Keep your existing `ViceBounce.ini` when updating.

Other game versions are currently unsupported.

## Music

Press **F11** and select your own **MP3, FLAC, WAV or OGG**. The importer analyzes the beat and prepares looping playback locally. No Python installation needed. Music is not included or uploaded.

Use **F9** to adjust alignment by ear. Automatic beat detection can make mistakes.

## Controls

| Key | Action |
| --- | --- |
| F6 | Cars and cutscenes |
| F8 | Bikes, boats and aircraft |
| F10 | Everyone, including Tommy |
| F11 | Import music |
| F7 | Reload settings |
| F9 | Align the beat |
| Page Up / Down | Manual BPM ±5; disables beat map |
| Home / End | Amplitude ±0.025 |

Settings save automatically. Ctrl+Shift+F11 stays available for OBS.

## Support me

[Buy me a coffee](https://buymeacoffee.com/tek95) · [Support from Russia · CloudTips](https://pay.cloudtips.ru/p/b0d7d75d)

## Credits

Inspired by [CarbonBounce](https://github.com/giovannosaur/CarbonBounce). Built with [Plugin-SDK](https://github.com/DK22Pac/plugin-sdk).

[MIT license](LICENSE.txt). Dependencies retain their own licenses. [Importer build instructions](importer/BUILD.md).
