#include <sys/ioctl.h>
#include <linux/if.h>
#include <netinet/ether.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include <iostream>

void getMACAddress(char interface[64]) {	
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    struct ifreq ifr{};
    
    strcpy(ifr.ifr_name, interface);
    ioctl(fd, SIOCGIFHWADDR, &ifr);
    close(fd);

    char mac[18];
    strcpy(mac, ether_ntoa((ether_addr *) ifr.ifr_hwaddr.sa_data));

    std::cout << "MAC Address (" << interface << "): " << mac << std::endl;
}
