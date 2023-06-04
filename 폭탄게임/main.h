#ifndef __STDIO_H__ //__STDIO_H__ 라는 매크로가 정의되어있지 않다면
#define __STDIO_H__ //__STDIO_H__를 정의

#include<stdio.h> //이 부분은 한 번만 컴파일 됨

#endif //ifndef 종료

//중복 선언 방지


#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include<windows.h>

#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include<stdlib.h>

#endif

#ifndef __TIME_H__
#define __TIME_H__

#include<time.h>

#endif