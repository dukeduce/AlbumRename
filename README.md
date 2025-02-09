# My Project: Album Rename
Click on video to view a short demo
[![demo video](https://i.imgur.com/iLJmsMA.png)](https://i.imgur.com/obJ3trG.mp4)

This project is a simple x64 tool for renaming album folders based on their metadata into my preferred format "artist - album (year)".
This project uses The taglib library to read song metadata and does not change song metadata, or song file names.
Album Rename supports unicode folder names by the use of #include <windows.h> and #include <locale> library.

## Building

1. **Download and Extract** the project files.
2. **Have MINGW** installed on your system.
3. **Run `build.cmd`**

## Dependencies

- TagLib: [TagLib GitHub](https://github.com/taglib/taglib)
- Zlib: [Zlib Website](https://zlib.net/)

These dependencies are precompiled as x64-mingw-static and included in the `lib` and `include` directory.


## Usage

After building the project, you can place the executable `AlbumRename.exe` in the directory of your album folders to rename them.


## License
This project falls under the MIT License - see the [LICENSE](LICENSE) file for details.
