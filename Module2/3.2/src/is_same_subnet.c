#include "main.h"

int is_same_subnet(const char *ip_address, const char *gateway, const char *subnet_mask) {
    struct in_addr addr, gw, mask;
    inet_pton(AF_INET, ip_address, &addr);
    inet_pton(AF_INET, gateway, &gw);
    inet_pton(AF_INET, subnet_mask, &mask);

    return (addr.s_addr & mask.s_addr) == (gw.s_addr & mask.s_addr);
}