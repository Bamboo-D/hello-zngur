#include <iostream>

#include "zgenerated.h"

using namespace rust::crate;

int main()
{
    std::cout << "Hello, Zngur!" << std::endl;

    hello_rust();

    return 0;
}
