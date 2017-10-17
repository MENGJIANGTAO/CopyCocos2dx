#ifndef __REF_H__
#define __REF_H__

class Ref
{
public:
    void retain();
    void release();
    
    Ref* autorelease();
    unsigned int getReferenceCount() const;
protected:
    Ref();
public:
    virtual ~Ref();
protected:
    unsigned int _referenceCount;
};

#endif