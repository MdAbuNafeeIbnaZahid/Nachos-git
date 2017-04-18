#ifndef PRODUCER_H
    #define PRODUCER_H

#include "globalBuffer.h"

struct Producer
{
    long long id;
    GlobalBuffer *globalBuffer;
    Producer(long long id, GlobalBuffer *globalBuffer);
   
};


#endif // PRODUCER_H