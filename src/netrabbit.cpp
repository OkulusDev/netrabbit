#include <iostream>
#include <string.h>
#include <getmac.hpp>
#include <sniffer.hpp>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "Usage: netrabbit <sniffer/getmac>" << std::endl;
        return 0;
    }

	if (strcmp(argv[1], "sniffer") == 0) {
		sniffingPackets();
	} else if (strcmp(argv[1], "getmac") == 0) {
		if (argc < 3) {
		    std::cout << "Usage: netrabbit getmac <interface>" << std::endl;
		} else {
			getMACAddress(argv[2]);
		}
	}

	return 0;
}
