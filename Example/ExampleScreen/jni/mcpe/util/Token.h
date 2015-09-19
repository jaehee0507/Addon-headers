#pragma once

#include <string>

//Size : 16
class Token {
    public:
    enum Type {
        
    };
    
    public:
    char filler1[8];            //0
    Token::Type type;           //8
    char filler2[4];            //12
    
    public:
    Token(std::string const&);
    void _parseRandom();
    bool compatibleWith(Token::Type) const;
    bool getBool(bool) const;
    std::string const& getText(std::string const&) const;
    int getValue(int) const;
    Token tokenize(std::string const&);
};
