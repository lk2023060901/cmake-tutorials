#include <iostream>

#include "config.h"

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " Version: " << ZEUS_VERSION_MAJOR;
    std::cout << "." << ZEUS_VERSION_MINOR << std::endl;

    std::cout << argv[0] << " Version: " << ZEUS_VERSION << std::endl;

    return 0;
}