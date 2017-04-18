// Last Update:2017-03-30 15:03:36
/**
 * @file get_all_ip_addrs.c
 * @so far, it is just for ipv4 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2017-03-30
 */

#include<stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
#include <net/if.h>
#include <ifaddrs.h>
#include<unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include<errno.h>

int totemip_sockaddr_to_totemip_convert(const struct sockaddr_storage *saddr,
                char *ip_addr)
{
    int ret = -1;

    if (saddr->ss_family == AF_INET) {
        const struct sockaddr_in *sin = (const struct sockaddr_in *)saddr;
        char * tmp = inet_ntoa(sin->sin_addr);
        strncpy(ip_addr, tmp, strlen(tmp));
        ret = 0;
    }

    if (saddr->ss_family == AF_INET6) {
        const struct sockaddr_in6 *sin = (const struct sockaddr_in6 *)saddr;

        memcpy(ip_addr, &sin->sin6_addr, sizeof(struct in6_addr));

        ret = 0;
    }
    return ret;
}


int main(void)
{
    struct ifaddrs *ifap, *ifa;
    char * ip_addr = malloc(256);
    char* mask_addr= malloc(256);
    if(ip_addr == NULL || mask_addr == NULL)
    {
        printf("failed to malloc\n");
        return -1;
    }
    memset(ip_addr, 0, 256);
    memset(mask_addr, 0, 256);
    if(getifaddrs(&ifap) != 0)
    {
        printf("failed to get addr:%s\n", strerror(errno));
        return -1;
    }
    for (ifa = ifap; ifa; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL || ifa->ifa_netmask == NULL)
            continue;
        if(totemip_sockaddr_to_totemip_convert((const struct sockaddr_storage *)ifa->ifa_addr, ip_addr) == -1)
            strncpy(ip_addr, "0.0.0.0", strlen("0.0.0.0"));
        if (totemip_sockaddr_to_totemip_convert((const struct sockaddr_storage *)ifa->ifa_netmask, mask_addr) == -1)
            strncpy(mask_addr, "0.0.0.0", strlen("0.0.0.0"));
        printf("interface_up:%d,\ninterface_num:%d,\nname:%s,\nip_addr:%s,\nmask_addr=\n", ifa->ifa_flags & IFF_UP, if_nametoindex(ifa->ifa_name), ifa->ifa_name, ip_addr);
    }
    return 0;
}

