#ifndef GLOBAL_BUFFER_H
    #define GLOBAL_BUFFER_H

#include "copyright.h"
#include "thread.h"
#include "list.h"
#include "synch.h"


struct GlobalBuffer
{
    long long buf[99999];
    long long frontIdx, backIdx, siz;
    Lock *lock;
    Condition *full, *empty;
    GlobalBuffer();
    
    
    void insert(long long val, long long who);
    
    
    long long getNum( long long who );
    
};



#endif  // GLOBAL_BUFFER_H