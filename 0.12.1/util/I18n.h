#pragma once

#include <string>
#include <vector>

class Localization;

class I18n {
    public:
    static void* currentLanguage;
    static void* languages;
    
    public:
    static void chooseLanguage(Localization const&);
    static void chooseLanguage(std::string const&);
    static std::string get(std::string const&, std::vector<std::string> const&);
    static void getCurrentLanguage();
    static void getLocaleFor(std::string const&);
    static void loadLanguages();
};
