#pragma once

class MemoryTracker {
    public:
    //void** vtable;
	
    public:
    MemoryTracker(std::string const&, MemoryTracker*);
    virtual ~MemoryTracker();
    virtual void getStats() const = 0;
    void memoryStats();
};
