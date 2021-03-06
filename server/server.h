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


#ifndef STUN_SERVER_H
#define	STUN_SERVER_H

#include "stunsocket.h"
#include "stunsocketthread.h"
#include "stunauth.h"




class CStunServerConfig
{
public:
    bool fHasPP; // PP: Primary ip,   Primary port
    bool fHasPA; // PA: Primary ip,   Alternate port
    bool fHasAP; // AP: Alternate ip, Primary port
    bool fHasAA; // AA: Alternate ip, Alternate port

    bool fMultiThreadedMode;  // if true, one thread for each socket

    CSocketAddress addrPP; // address for PP
    CSocketAddress addrPA; // address for PA
    CSocketAddress addrAP; // address for AP
    CSocketAddress addrAA; // address for AA

    CStunServerConfig();
};






class CStunServer :
public CBasicRefCount,
public CObjectFactory<CStunServer>,
public IStunResponder
{
private:
    CRefCountedStunSocket _arrSockets[4];

    // when we support multithreaded servers, this will change to a list

    std::vector<CStunSocketThread*> _threads;

    CStunServer();
    ~CStunServer();

    friend class CObjectFactory<CStunServer>;

    
    CRefCountedPtr<IStunAuth> _spAuth;


public:

    HRESULT Initialize(const CStunServerConfig& config);
    HRESULT Shutdown();

    HRESULT Start();
    HRESULT Stop();


    // IStunResponder
    virtual HRESULT SendResponse(SocketRole roleOutput, const CSocketAddress& addr, CRefCountedBuffer& spResponse);
    virtual bool HasAddress(SocketRole role);
    virtual HRESULT GetSocketAddressForRole(SocketRole role, /*out*/ CSocketAddress* pAddr);
    
    

    ADDREF_AND_RELEASE_IMPL();
};



#endif	/* SERVER_H */

