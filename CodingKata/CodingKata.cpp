// CodingKata.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CodingKata.h"


// This is an example of an exported variable
CODINGKATA_API int nCodingKata=0;

// This is an example of an exported function.
CODINGKATA_API int fnCodingKata(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see CodingKata.h for the class definition
CCodingKata::CCodingKata()
{
    return;
}
