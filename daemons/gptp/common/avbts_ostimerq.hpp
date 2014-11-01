/******************************************************************************

  Copyright (c) 2009-2012, Intel Corporation 
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
  
   1. Redistributions of source code must retain the above copyright notice, 
      this list of conditions and the following disclaimer.
  
   2. Redistributions in binary form must reproduce the above copyright 
      notice, this list of conditions and the following disclaimer in the 
      documentation and/or other materials provided with the distribution.
  
   3. Neither the name of the Intel Corporation nor the names of its 
      contributors may be used to endorse or promote products derived from 
      this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#ifndef AVBTS_OSTIMERQ_HPP
#define AVBTS_OSTIMERQ_HPP

typedef void (*ostimerq_handler) (void *);

class IEEE1588Clock;

class OSTimerQueue {
protected:
	virtual bool init() { return true; }
	OSTimerQueue() {}
public:
	virtual bool addEvent
	(unsigned long micros, int type, ostimerq_handler func,
	 event_descriptor_t * arg, bool dynamic, unsigned *event) = 0;
	virtual bool cancelEvent(int type, unsigned *event) = 0;
	virtual ~OSTimerQueue() = 0;
};

inline OSTimerQueue::~OSTimerQueue() {}

class OSTimerQueueFactory {
public:
	virtual OSTimerQueue *createOSTimerQueue( IEEE1588Clock *clock ) = 0;
	virtual ~OSTimerQueueFactory() = 0;
};

inline OSTimerQueueFactory::~OSTimerQueueFactory() {}

#endif