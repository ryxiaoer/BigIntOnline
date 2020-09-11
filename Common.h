#pragma once

#include <iostream>
#include <assert.h>
#include <time.h>
#include <windows.h>
using namespace std;

typedef unsigned char u_char;
#define ERR_EXIT(m)\
	do\
	{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)
