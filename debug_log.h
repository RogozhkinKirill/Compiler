#ifndef __DEBUG_LOG_H__
#define __DEBUG_LOG_H__

//debug_log.h
	#ifdef DEBUG
		#include <stdio.h>
		#define debug_print(...) printf(__VA_ARGS__)
	#else
		#define debug_print(...)
    #endif

#ifdef DEBUG_CREATOR
    #include <stdio.h>
    #define  debug_creator_print(...) printf(__VA_ARGS__)
#else
    #define  debug_creator_print(...)
#endif

#endif // __DEBUG_LOG_H__
