#include "copyright.h"
#include "system.h"
#include "producer.h"
#include "thread.h"
#include "consumer.h"

void
consume(void* consumer)
{
    
    Consumer *myConsumer = (Consumer*)consumer;
    GlobalBuffer *globalBuffer = myConsumer->globalBuffer;
    long long id = myConsumer->id;
    while(1)
    {
        long long a, b, c, d, e;
        for ( a = 1; a <= rand(); a++ )
        {
            
        }
        globalBuffer->getNum( id );
    }
}

Consumer::Consumer(long long id, GlobalBuffer *globalBuffer)
{
    this->id = id;
    this->globalBuffer = globalBuffer;
    char* threadname = new char[100];
    sprintf(threadname, "Consumer %lld", id);
    Thread* newThread = new Thread (threadname);
    newThread->Fork (consume, (void*)this);
}