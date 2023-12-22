#include <iostream>
#include <getmac.hpp>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: lambdanet <interface>" << std::endl;
        return 0;
    }

    getMACAddress(argv[1]);
}
