/*
Zeus TF2 Basehook
Copyright (C) 2009 Xeno123

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


class CVMTHook
{
public:
	DWORD Hook ( DWORD new_Function, PDWORD pClass, int index )
	{
		m_NewFunction = new_Function;
		m_FunctionIndex = index;
		m_ClassTable = *( PDWORD* )pClass;
		m_OriginalFunction = m_ClassTable[ m_FunctionIndex ];
		m_FunctionPointer = &m_ClassTable[ m_FunctionIndex ];
		ReHook();
		return FunctionAddress();
	}

	void UnHook ( void )
	{
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery( ( LPVOID )m_FunctionPointer, &mbi, sizeof( mbi ) );
		VirtualProtect( ( LPVOID )mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect );
		m_ClassTable[ m_FunctionIndex ] = m_OriginalFunction;
		VirtualProtect( ( LPVOID )mbi.BaseAddress, mbi.RegionSize, mbi.Protect, NULL );
		FlushInstructionCache( GetCurrentProcess(), ( LPCVOID )m_FunctionPointer, sizeof( DWORD ) );
	}

	void ReHook ( void )
	{
		MEMORY_BASIC_INFORMATION mbi;
		VirtualQuery( ( LPVOID )m_FunctionPointer, &mbi, sizeof( mbi ) );
		VirtualProtect( ( LPVOID )mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect );
		m_ClassTable[ m_FunctionIndex ] = m_NewFunction;
		VirtualProtect( ( LPVOID )mbi.BaseAddress, mbi.RegionSize, mbi.Protect, NULL );
		FlushInstructionCache( GetCurrentProcess(), ( LPCVOID )m_FunctionPointer, sizeof( DWORD ) );
	}

	DWORD FunctionAddress ( void )
	{
		return m_OriginalFunction;
	}

private:
	// Member variables
	int m_FunctionIndex;
	PDWORD m_ClassTable;
	PDWORD m_FunctionPointer;
	DWORD m_NewFunction;
	DWORD m_OriginalFunction;
};