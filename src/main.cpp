#include <iostream>
#include <filesystem>       // passing paths as args and renaming folders
#include <taglib/fileref.h> // external; reading song tags
#include <conio.h>          // _getch() "Press any key to exit"
#include <windows.h>        // Console unicode rendering
#include <locale>           // UTF-8 interpretation in wcout
namespace fs = std::filesystem;

void renameAlbum(const fs::path& folderPath, const fs::path& rootPath) {
    std::wstring parentPath{folderPath.parent_path().generic_wstring()};
    std::wstring newFolderName{};
    std::wstring oldFolderName{folderPath.filename().wstring()};

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_directory()) {
            renameAlbum(entry.path(), rootPath); // Recursively process subdirectories
            continue;
        }

        if (!entry.is_regular_file()){
            continue;
        } // Not a song file, continue to next file

        TagLib::FileRef f(entry.path().c_str());
        if (!f.isNull() && f.audioProperties()) {
            TagLib::Tag* tag = f.tag();
            std::wstring artist = tag->artist().toWString();
            std::wstring album = tag->album().toWString();
            std::wstring year = std::to_wstring(tag->year());

            if (year == L"0" || artist.empty() || album.empty()){
                std::wcout << L"Folder: " << folderPath.generic_wstring() << " does not have complete tags" << std::endl;
            }else{
                // Format the folder name as "artist - album (year)"
                newFolderName = artist + L" - " + album + L" (" + year + L")";
            }
            break;
        }
    }

    if (!newFolderName.empty() && (newFolderName != oldFolderName)) {
        fs::path newFolderPath = folderPath.parent_path() / newFolderName;
        try {
            fs::rename(folderPath, newFolderPath);
            if (folderPath.parent_path() != rootPath){   // if root folder or album subdirectory
                std::wcout << L"Renamed: " << parentPath << "/" << oldFolderName << L" -> " << newFolderName << std::endl;
            }else{
                std::wcout << L"Renamed: " << oldFolderName << L" -> " << newFolderName << std::endl;
            }
        } catch (const std::exception& e) {
            std::wcerr << L"Error: cannot rename folder: " << e.what() << std::endl;
        }
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);  // Set console output to UTF-8
    SetConsoleCP(CP_UTF8);        // Set console input to UTF-8
    std::setlocale(LC_ALL, "en_US.UTF-8");
    // std::wcout << L"Testing Unicode: Æ, ☺, 漢字" << std::endl;

    int repeat {1};
    while(repeat != 0) {
        std::wstring pathString;
        std::wcout << L"Enter [.] to rename all albums in the folder OR Specify a folder path: ";
        
        std::getline(std::wcin, pathString);  // Read the input as a wide string

        // fs::path to std::wstring
        fs::path path {pathString};

        if (fs::is_directory(path)) {
            if (path != ".") {
                renameAlbum(path, path); // Process the given folder
            } else {
                for (const auto& folder : fs::directory_iterator(path)) {
                    if (folder.is_directory()) {
                        renameAlbum(folder.path(), path);
                    }
                }
            }
        } else {
            std::wcerr << L"Error: The specified path is invalid or not a directory!" << std::endl;
        }

        // Clear the input buffer to avoid leftover newline
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n'); 

        // Ask for repeat choice and make sure to consume the leftover newline
        std::wcout << L"Enter 0 to quit, or any other key to continue: ";
        std::wcin >> repeat;

        // Clear the input buffer again after reading the number
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    }
    
    return 0;
}
