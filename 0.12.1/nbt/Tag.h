#pragma once

#include <string>

class PrintStream;
class IDataInput;
class IDataOutput;

class Tag {
    public:
    //void** vtable;
    
    public:
    Tag(std::string const&);
    virtual ~Tag();
    virtual void deleteChildren();
    virtual void write(IDataOutput&) const = 0;
    virtual void load(IDataInput&) = 0;
    virtual std::string toString() const = 0;
    virtual int getId() const = 0;
    virtual bool equals(Tag const&) const;
    virtual void print(PrintStream&) const;
    virtual void print(std::string const&, PrintStream&) const;
    virtual void setName(std::string const&);
    virtual std::string getName() const;
    virtual Tag* copy() const = 0;
    std::string getTagName(char);
    void readNamedTag(IDataInput&, std::string&);
    void writeNamedTag(std::string const&, Tag const&, IDataOutput&);
    
    public:
    static Tag* newTag(char, std::string const&);
};