#ifndef _QPS_H_
#define _QPS_H_
#include "proc.h"

// 프로세스 목록을 적당히 가공해서 출력한다.
int viewProc();

// 각프로세스의 CPU 사용율을 얻어온다. 
int getcputime(ulong utime, ulong stime, ulong starttime, int seconds);

// OS의 uptime(부팅후 지금까지의 가동시간)을 얻어온다.  
int uptime();
#endif
