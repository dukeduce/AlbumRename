# My Project: Album Rename

[![demo video](https://i.imgur.com/BoTYPW9.png)](https://i.imgur.com/Q86F470.mp4)

Click on image to view a short demo


This project is a simple tool for renaming album folders to "artist - album (year)".
This project uses The taglib library to read song metadata and does not change song metadata, or song file names.
Album Rename supports unicode folder names, and tags.


## Release

The tool is precompiled for use in windows x64 and x86. 
Other OS's may not work as intended with their file managers.


## Dependencies

- TagLib: [TagLib GitHub](https://github.com/taglib/taglib)
- Zlib: [Zlib Website](https://zlib.net/)

These dependencies are precompiled as x64-mingw-static and included in the `lib` and `include` directory.
Taglib 2.0.2
Zlib 1.3.1
utf8cpp 4.0.6


## Usage

Place the executable `AlbumRename.exe` in the directory of your album folders to rename them and double click the executable.


## License
This project falls under the MIT License - see the [LICENSE](LICENSE) file for details.
