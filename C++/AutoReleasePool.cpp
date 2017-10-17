#include "AutoreleasePool.h"

AutoReleasePool::AutoReleasePool()
:_name("")
,_isClearing(false)
{
    _managedObjectArray.reserve(150);
    PoolManager::getInstance()->push(this);
}

AutoReleasePool::AutoReleasePool(const std::string &name)
:_name(name)
,_isClearing(false)
{
    _managedObjectArray.reserve(150);
    PoolManager::getInstance()->push(this);
}

AutoReleasePool::~AutoReleasePool()
{
    clear();
    PoolManager::getInstance()->pop();
}

void AutoReleasePool::addObject(Ref* object)
{
    _managedObjectArray.push_back(object);
}

void AutoReleasePool::clear()
{
    _isClearing = true;

    std::vector<Ref*> releasings;
    releasings.swap(_managedObjectArray);
    for(const auto &obj : releasings)
    {
        obj->release();
    }
    _isClearing = false;
}

bool AutoReleasePool::contains(Ref* object) const
{
    for (const auto &obj : _managedObjectArray)
    {
        if (obj == object)
            return true;
    }
    return false;
}

void AutoReleasePool::dump()
{
    
}