#include <stdio.h>

int foo1();
int foo2();
int foo3();
int foo4();
int foo5();
int foo6();
int foo7();
int foo8();

int main()
{
    printf("%d\n", foo1() + foo2() + foo3() + foo4() +
                foo5() + foo6() + foo7() + foo8());
    return 0;
}
