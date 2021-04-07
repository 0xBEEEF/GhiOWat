#include <stdio.h>
#include <stdlib.h>

typedef struct teststruct
{
    int a;
    int b;
    float f;
} TestStruct;


int __watcall  registerCallingConvention(int a, int b, int c, int d, int e, int f, int g);
int __watcall stackCallingConvention(int a, int b, int c, ...);
TestStruct * __watcall registerCallingConvention2(int a, int b, char * name, float f);

int __syscall sysCallConvention(int a, int b, int c , int d, int e, int f, int g);
int __stdcall standardCallConvention(int a, int b, int c, int d, int e, int f, int g, int h, int i);
int __pascal pascalCallConvention(int a, int b, int c, int d, int e);
int __cdecl cdeclCallConvention(int a, int b, int c, int d, int e, int f, int g, int h, int i);

void __watcall testStruct1(int a, int b, float f, TestStruct * str);
void __syscall testStruct2(int a, int b, float f, TestStruct * str);
void __stdcall testStruct3(int a, int b, float f, TestStruct * str);
void __pascal testStruct4(int a, int b, float f, TestStruct * str);
void __cdecl testStruct5(int a, int b, float f, TestStruct * str);
void __watcall PrintStruct(TestStruct * str);

void main( )
{
    TestStruct * t;
    printf("MainFunction");
    registerCallingConvention(1,2,3,4,5,6,7);
    stackCallingConvention(1,2,3,4,5,6,7,8,9,10);
    t = registerCallingConvention2(10,20,"Test",1.23456);
    sysCallConvention(10,20,30,40,50,60,70);
    standardCallConvention(5,10,15,20,25,30,35,40,45);
    pascalCallConvention(20,40,60,80,100);
    cdeclCallConvention(-10, -15, -20, -25, -30, -35, -40, -45, -50);
    testStruct1(10,20,1.2345,t);
    PrintStruct(t);
    testStruct2(30,40,2.3456,t);
    PrintStruct(t);
    testStruct3(50,60,3.4567,t);
    PrintStruct(t);
    testStruct4(70,80,4.5678,t);
    PrintStruct(t);
    testStruct5(90,100,5.6789,t);
    PrintStruct(t);
}

void __watcall PrintStruct(TestStruct * str)
{
    printf("%d %d %f \r\n",str->a, str->b, str->f);
}

int __watcall  registerCallingConvention(int a, int b, int c, int d, int e, int f, int g)
{
    return a + b + c + d + e + f + g;
}

int __watcall stackCallingConvention(int a, int b, int c, ...)
{
    return 0;
}

TestStruct * __watcall registerCallingConvention2(int a, int b, char * name, float f)
{
    TestStruct* t = malloc(sizeof(TestStruct));
    t->a = a;
    t->b = b;
    t->f = f;
    return t;
}

int __syscall sysCallConvention(int a, int b, int c , int d, int e, int f, int g)
{
    return g + f + e + d + c + b + a;
}

int __stdcall standardCallConvention(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    int test;
    int test2;

    test = a + c + e + g;
    test2 = b + d + f + h;

    return test * test2;
}

int __pascal pascalCallConvention(int a, int b, int c, int d, int e)
{
    return a + c + e;
}

int __cdecl cdeclCallConvention(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    return a + c + e + f + h;
}

void __watcall testStruct1(int a, int b, float f, TestStruct * str)
{
    str->a = a;
    str->b = b;
    str->f = f;
}

void __syscall testStruct2(int a, int b, float f, TestStruct * str)
{
    str->a = a;
    str->b = b;
    str->f = f;
}

void __stdcall testStruct3(int a, int b, float f, TestStruct * str)
{
    str->a = a;
    str->b = b;
    str->f = f;
}

void __pascal testStruct4(int a, int b, float f, TestStruct * str)
{
    str->a = a;
    str->b = b;
    str->f = f;
}
void __cdecl testStruct5(int a, int b, float f, TestStruct * str)
{
    str->a = a;
    str->b = b;
    str->f = f;
}
