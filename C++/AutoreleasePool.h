#ifndef __AUTORELEASEPOOL_H__
#define __AUTORELEASEPOOL_H__

#include <string>
#include <vector>
#include "Ref.h"

class AutoReleasePool
{
public:
    AutoReleasePool();
    AutoReleasePool(const std::string &name);
    ~AutoReleasePool();

    void addObject(Ref *object);
    void clear();
    bool isClearing() const { return _isClearing; };
    bool contains(Ref* object) const;
    void dump();

private:
    std::vector<Ref*> _managedObjectArray;
    std::string _name;
    bool _isClearing;
};

#endif