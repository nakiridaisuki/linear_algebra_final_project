#ifndef __DEBUG__
#define __DEBUG__
#ifdef DEBUG
#include <assert.h>
#define deprint printf
#else
#define deprint ;
#endif
#endif