/*
===============================================================================
The MIT License
Copyright (C) 1994-2015 simawei<simawei@qq.com>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================================================
*/
#pragma once


#include "SelectIOServer.h"
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

	#include "../luabuffer.h"
}


/************************************************************************/
/* 
   主Server服务端类
*/
/************************************************************************/

class Server
{
	//PacketHandler m_PacketHandler;//消息处理 

 

	Server(void);
	 
	bool g_bTerminate;//退出标志

	lua_State * L;
	//初始化lua
	void init_Lua();
	void Shutdown_Lua(   ) ;
	void Update_Lua(   ) ;

	bool Server::call_lua(const char* fun);

 
public:
	~Server(void);
	 
	static Server& GetInstance(){
		static Server s;
		return s;
	};

	bool Init();

	void Run();

	void OnRecvData2Lua(int idx , char * pMsg, WORD wSize ); 

	void OnClose2Lua(  int idx   );

	void Terminate(){g_bTerminate=true;};
};
