#include <stdio.h>
#include <cs50.h>

#define IP4_LENGTH 32

unsigned int subnetMask = 0;
unsigned int ipAddress = 0;
unsigned int gateAway = 0;

int getSubnetMask(int vlsm);
bool validateIp4Format(const string adress);
int parseIp4(const string adress);
bool sameNetworkAddress(unsigned int address1, unsigned int address2, unsigned int mask);

int main(int argc, string argv[])
{
    if (argc != 4)
    {
        printf("usage: IProuting <vlsm> <address> <gateaway>\n");
        return 1;
    }
    int vlsm = atoi(argv[1]);
    if (!(0 <= vlsm && vlsm <= IP4_LENGTH
        && validateIp4Format(argv[2])
        && validateIp4Format(argv[3])))
    {
        printf("Invalid parameters specified\n");
        return 2;
    }
    subnetMask = getSubnetMask(vlsm);
    ipAddress = parseIp4(argv[2]);
    gateAway = parseIp4(argv[3]);
    
    if (sameNetworkAddress(ipAddress, gateAway, subnetMask))
    {
        printf("Config is OK\n");
    }
    else
    {
        printf("IP addresses are in the different networks\n");
    }
}

int getSubnetMask(int vlsm)
{
    unsigned int subnetmask = 0;
    return (~subnetmask) << (IP4_LENGTH - vlsm);
}

bool validateIp4Format(const string adress)
{
    // valid IP address is <0-255>.<0-255>.<0-255>.<0-255>
    int _1, _2, _3, _4;
    int valid = sscanf(adress, "%d.%d.%d.%d", &_1, &_2, &_3, &_4);
    return valid != EOF
        && valid == 4
        && 0 <= _1 && _1 <=255
        && 0 <= _2 && _2 <=255
        && 0 <= _3 && _3 <=255
        && 0 <= _4 && _4 <=255;
}

int parseIp4(const string adress)
{
    // valid IP address is <0-255>.<0-255>.<0-255>.<0-255>
    int _1, _2, _3, _4;
    sscanf(adress, "%d.%d.%d.%d", &_1, &_2, &_3, &_4);
    return (_1 << 24) | (_2 << 16) | (_3 << 8) | (_4);
}

bool sameNetworkAddress(unsigned int address1, unsigned int address2, unsigned int mask)
{
    return (address1 & mask) == (address2 & mask);
}