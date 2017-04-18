#include "copyright.h"
#include "system.h"
#include "producer.h"

void
produce(void* producer)
{
    // Reinterpret arg "name" as a string
    Producer *myProducer = (Producer*)producer;
    GlobalBuffer *globalBuffer = myProducer->globalBuffer;
    long long id = myProducer->id;
//    
//    for (int num = 0; num < 10; num++) {
//        //IntStatus oldLevel = interrupt->SetLevel(IntOff);
//	printf("*** thread %s looped %d times\n", threadName, num);
//	//interrupt->SetLevel(oldLevel);
//        //currentThread->Yield();
//    }
    
    while(1)
    {
        long long a, b, c, d, e;
        for ( a = 1; a <= rand(); a++ )
        {
            
        }
        globalBuffer->insert( id, id );
    }
}

Producer::Producer(long long id, GlobalBuffer *globalBuffer)
{
    this->id = id;
    this->globalBuffer = globalBuffer;
    char* threadname = new char[100];
    sprintf(threadname, "Producer %lld", id);
    Thread* newThread = new Thread (threadname);
    newThread->Fork (produce, (void*)this);
}