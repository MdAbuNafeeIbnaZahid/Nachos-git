// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create several threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustrate the inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.
//
// Parts from Copyright (c) 2007-2009 Universidad de Las Palmas de Gran Canaria
//

#include "copyright.h"
#include "system.h"
//#include <bits/stdc++.h>
#include "synch.h"
#include "globalBuffer.h"

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 10 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"name" points to a string with a thread name, just for
//      debugging purposes.
//----------------------------------------------------------------------

//struct GlobalBuffer
//{
//    long long buf[9999];
//    long long frontIdx, backIdx, siz;
//    Lock *lock;
//    Condition *full, *empty;
//    GlobalBuffer()
//    {
//        frontIdx = backIdx = siz = 0;
//        lock = new Lock("bufLock");
//        full = new Condition("full", lock );
//        empty = new Condition("full", lock);
//    }
//    
//    void insert(long long val, long long who)
//    {
//        lock->Acquire();
//        if ( siz == 10 )
//        {
//            full->Wait();
//        }
//        buf[ ++siz ] = val;
//        printf("%lld inserted %lld in idx %lld\n\n", who, val, siz);
//        empty->Signal();
//        lock->Release();
//    }
//    
//    long long getNum( long long who )
//    {
//        long long ret;
//        lock->Acquire();
//        if ( siz == 0 )
//        {
//            empty->Wait();
//        }
//        ret = buf[ siz-- ];
//        printf("%lld removed %lld from idx %lld\n\n", who, ret, siz+1);
//        full->Signal();
//        lock->Release();
//        return ret;
//    }
//};

void
SimpleThread(void* name)
{
    // Reinterpret arg "name" as a string
    char* threadName = (char*)name;
    
    // If the lines dealing with interrupts are commented,
    // the code will behave incorrectly, because
    // printf execution may cause race conditions.
    for (int num = 0; num < 10; num++) {
        //IntStatus oldLevel = interrupt->SetLevel(IntOff);
	printf("*** thread %s looped %d times\n", threadName, num);
	//interrupt->SetLevel(oldLevel);
        //currentThread->Yield();
    }
    //IntStatus oldLevel = interrupt->SetLevel(IntOff);
    printf(">>> Thread %s has finished\n", threadName);
    //interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between several threads, by launching
//	ten threads which call SimpleThread, and finally calling 
//	SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");

    GlobalBuffer *globalBuffer = new GlobalBuffer();
    
    printf("globalBuffer->siz = %lld\n\n", globalBuffer->siz );
    
    for ( int k=1; k<=10; k++) {
      char* threadname = new char[100];
      sprintf(threadname, "Hilo %d", k);
      Thread* newThread = new Thread (threadname);
      newThread->Fork (SimpleThread, (void*)threadname);
    }
    
    SimpleThread( (void*)"Hilo 0");
}

