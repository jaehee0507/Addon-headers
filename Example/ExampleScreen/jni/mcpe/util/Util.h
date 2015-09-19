#pragma once

#include <string>
#include <stdarg.h>
#include <vector>

class Util {
    public:
    static std::string EMPTY_STRING;
    
    public:
    static void base64_decode(std::string const&);
    static void base64_encode(unsigned char const*, unsigned int);
    static bool compareNoCase(std::string const&, std::string const&);
    static void countWordOccurrences(std::string const&, std::string const&);
    static bool endsWith(std::string const&, std::string const&);
    static void format(char const*, ...);
    static void formatTickDuration(int);
    static void freeStringMemory(std::string&);
    static void getDirectory(std::string const&);
    static void getExtension(std::string const&);
    static void getFileName(std::string const&);
    static void hashCode(std::string const&);
    static bool isValidPath(std::string const&);
    static void removeAll(std::string&, char const**, int);
    static void removeIllegalChars(std::string const&);
    static void simpleFormat(std::string const&, std::vector<std::string>);
    static std::vector<std::string> split(std::string const&, char);
    static void split(std::string const&, std::vector<std::string> const&, bool);
    static void splitString(std::string const&, char, std::vector<std::string>&);
    static bool startsWith(std::string const&, std::string const&);
    static bool stringContains(std::string const&, char);
    static void stringReplace(std::string&, std::string const&, std::string const&, int);
    static void stringTrim(std::string const&);
    static void stringTrim(std::string const&, std::string const&, bool, bool);
    static void to_hex(char);
    static void toInt(std::string const&, int&);
    static void toInt(std::string const&, int&, int, int);
    static void toLower(std::string const&);
    static std::string toNiceString(int);
    static std::string toString(float);
    static std::string toString(int);
    static void toString(std::basic_string<wchar_t, std::char_traits<wchar_t>> const&);
    static void toWideString(std::string const&);
    static void utf8len(std::string const&);
    static void utf8substring(std::string const&, int, int);
};
