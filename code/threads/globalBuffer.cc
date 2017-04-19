#include "globalBuffer.h"

GlobalBuffer::GlobalBuffer()
{
    frontIdx = backIdx = siz = 0;
    lock = new Lock("bufLock");
    full = new Condition("full", lock );
    empty = new Condition("empty", lock);
}
    
void GlobalBuffer::insert(long long val, long long who)
{
    lock->Acquire();
    if ( siz == 10 )
    {
        full->Wait();
    }
    buf[ ++siz ] = val;
    printf("%lld inserted %lld in idx %lld\n\n", who, val, siz);
    empty->Signal();
    lock->Release();
}
    
long long GlobalBuffer::getNum( long long who )
{
    long long ret;
    lock->Acquire();
    if ( siz == 0 )
    {
        empty->Wait();
    }
    ret = buf[ siz-- ];
    printf("%lld removed %lld from idx %lld\n\n", who, ret, siz+1);
    full->Signal();
    lock->Release();
    return ret;
}
