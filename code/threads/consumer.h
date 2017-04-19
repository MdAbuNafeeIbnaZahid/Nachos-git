#ifndef CONSUMER_H
    #define CONSUMER_H

#include "globalBuffer.h"

struct Consumer
{
    long long id;
    GlobalBuffer *globalBuffer;
    Consumer(long long id, GlobalBuffer *globalBuffer);
   
};


#endif // CONSUMER_H