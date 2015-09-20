#pragma once

#include <string>
#include <functional>

class stat;

class File {
    public:
    static void cleanPath(std::string const&);
    static void copy(std::string const&, std::string const&);
    static void copyDirectoryRecursive(std::string const&, std::string const&);
    static void createFolder(std::string const&);
    static void deleteDirectory(std::string const&, bool);
    static void deleteEmptyDirectory(std::string const&);
    static bool exists(std::string const&);
    static void forEachIn(std::string const&, bool, std::function<void (std::string const&, stat const&)> const&);
    static int getRemainingSize(__sFILE*);
    static int getSize(std::string const&);
    static bool isDirectory(stat const&);
	static void splitPath(std::string const&);
};
