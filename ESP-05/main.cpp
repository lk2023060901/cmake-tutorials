#include <iostream>

#include "config.h"

int add(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[])
{
#ifdef USE_MATHLIB
    std::cout << "USE_MATHLIB: " << zeusmath::add(1, 2) << std::endl;
#else
    std::cout << add(1, 2) << std::endl;
#endif

    return 0;
}