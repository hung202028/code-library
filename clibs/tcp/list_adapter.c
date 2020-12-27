#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>


int main(int argc, char const *argv[])
{
    struct ifaddrs *addresses = NULL;

    if (getifaddrs(&addresses) == -1) {
        printf("%s\n", "getifaddrs call failed");
        return -1;
    }

    struct ifaddrs *addr_t = addresses;
    while (addr_t) {
        int family = addr_t -> ifa_addr -> sa_family;

        if (family == AF_INET || family == AF_INET6) {
            bool inet = family == AF_INET;

            printf("%s\t ", addr_t -> ifa_name);
            printf("%s\t", inet ? "IpV4" : "IpV6");

            char ap[100];

            const size_t family_size = inet ?
                sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(addr_t -> ifa_addr, family_size, ap, sizeof(ap),
                0, 0, NI_NUMERICHOST);
            printf("\t%s\n", ap);
        }

        addr_t = addr_t -> ifa_next;
    }

    free(addresses);
    return 0;
}