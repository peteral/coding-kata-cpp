// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32
    #include "targetver.h"
#endif

#include <stdio.h>


// TODO: reference additional headers your program requires here

//Adding required boost header
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <tuple>