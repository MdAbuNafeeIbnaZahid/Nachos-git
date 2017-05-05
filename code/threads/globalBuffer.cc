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
    
    //Faulty implementation
//    if ( siz == 10 )
//    {
//        full->Wait();
//    }
    
    
    while(1)
    {
        if ( siz >= 10 )
        {
            full->Wait();
        }
        else
        {
            break;
        }
    }
    
    buf[ ++siz ] = val;
    printf("producer %lld inserted %lld in idx %lld\n\n", who, val, siz);
    empty->Signal();
    lock->Release();
}
    
long long GlobalBuffer::getNum( long long who )
{
    long long ret;
    lock->Acquire();
    
    // Faulty implementation
//    if ( siz == 0 )
//    {
//        empty->Wait();
//    }
    
    while(1)
    {
        if ( siz <= 0 )
        {
            empty->Wait();
        }
        else
        {
            break;
        }
    }
    
    ret = buf[ siz-- ];
    printf("consumer %lld removed %lld from idx %lld\n\n", who, ret, siz+1);
    full->Signal();
    lock->Release();
    return ret;
}
