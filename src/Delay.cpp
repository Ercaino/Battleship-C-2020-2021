#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <chrono>
#include <thread>
#include <ctype.h>

void delay(clock_t a){
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}

/* Si poteva fare uso della libreria dos.h */