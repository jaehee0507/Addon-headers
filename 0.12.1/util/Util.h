#pragma once

#include <string>
#include <stdarg.h>
#include <vector>

class Util {
    public:
    static std::string EMPTY_STRING;
    
    public:
    void base64_decode(std::string const&);
    void base64_encode(unsigned char const*, unsigned int);
    bool compareNoCase(std::string const&, std::string const&);
    void countWordOccurrences(std::string const&, std::string const&);
    bool endsWith(std::string const&, std::string const&);
    void format(char const*, ...);
    void formatTickDuration(int);
    void freeStringMemory(std::string&);
    void getDirectory(std::string const&);
    void getExtension(std::string const&);
    void getFileName(std::string const&);
    void hashCode(std::string const&);
    bool isValidPath(std::string const&);
    void removeAll(std::string&, char const**, int);
    void removeIllegalChars(std::string const&);
    void simpleFormat(std::string const&, std::vector<std::string>);
    void split(std::string const&, char);
    void split(std::string const&, std::vector<std::string> const&, bool);
    void splitString(std::string const&, char, std::vector<std::string>&);
    void startsWith(std::string const&, std::string const&);
    bool stringContains(std::string const&, char);
    void stringReplace(std::string&, std::string const&, std::string const&, int);
    void stringTrim(std::string const&);
    void stringTrim(std::string const&, std::string const&, bool, bool);
    void to_hex(char);
    void toInt(std::string const&, int&);
    void toInt(std::string const&, int&, int, int);
    void toLower(std::string const&);
    std::string toNiceString(int);
    std::string toString(float);
    std::string toString(int);
    void toString(std::basic_string<wchar_t, std::char_traits<wchar_t>> const&);
    void toWideString(std::string const&);
    void utf8len(std::string const&);
    void utf8substring(std::string const&, int, int);
};
