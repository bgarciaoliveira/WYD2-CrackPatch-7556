/*
Copyright (C) 2015 bgarcia and agateownz
Contact: fb.com/bruunooliveira.2 or brunogarcia212@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but withouy any warranty.
*/

#include "tmpch.h"

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		if (!TMSRV::Initialize())
		{
			MessageBox(0, "N�o foi poss�vel carregar a Dll", "Error", MB_OK);
			ExitProcess(1);	
			return FALSE;
		}		
	}

	else if (dwReason == DLL_PROCESS_DETACH)
	{
		for (auto i = 0; i < MAX_USER; i++)
		{
			SaveUser(i, false);
		}

		FreeLibrary(hInstance);
	}

	return TRUE;
}