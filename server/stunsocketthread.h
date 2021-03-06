/*
   Copyright 2011 John Selbie

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/



#ifndef STUNSOCKETTHREAD_H
#define	STUNSOCKETTHREAD_H

#include "stunsocket.h"


class CStunServer;


class CStunSocketThread
{
    
public:
    CStunSocketThread();
    ~CStunSocketThread();
    
    HRESULT Init(std::vector<CRefCountedStunSocket>& listSockets, IStunResponder* pResponder, IStunAuth* pAuth);
    HRESULT Start();

    HRESULT SignalForStop(bool fPostMessages);
    HRESULT WaitForStopAndClose();
    
    /// returns back the index of the socket _socks that is ready for data, otherwise, -1
    int WaitForSocketData();
    
private:
    
    // this is the function that runs in a thread
    void Run();
    
    static void* ThreadFunction(void* pThis);
    
    std::vector<CRefCountedStunSocket> _socks;
    bool _fNeedToExit;
    CStunThreadMessageHandler _handler;
    pthread_t _pthread;
    bool _fThreadIsValid;
    
    int _rotation;
};




#endif	/* STUNSOCKETTHREAD_H */

