#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>


int main()
{
    srand(time(NULL));

    bool running  = true;
    std::string a = "";

    std::cin >> a;
    std::cout << a;

    while(running)
    {
        //Game here
    }

    return 0;
}