#pragma once

#include <functional>
#include <vector>
#include <string>

class Token;

class ServerCommandParser {
    public:
    //Size : 32
    class Command {
        public:
        char filler1[32];
        
        public:
        Command(std::function<std::string (std::vector<Token> const&)> const&, std::string const&);
        void checkParameters(std::vector<Token> const&);
    };
    
    public:
    void addCommand(std::string const&, std::string const&, std::function<std::string (std::vector<Token> const&)> const&);
    void executeCommand(std::string const&, std::string);
    void result(std::string const&);
};
