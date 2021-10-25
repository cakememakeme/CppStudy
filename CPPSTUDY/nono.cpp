#include "stdafx.h"

#include <iostream>


void fn1()
{
    //assert(0);
    *(int*)0 = 3;       //
}

void fn()
{
    fn1();
}


int main()
{
    
    fn();

    return 0;
}