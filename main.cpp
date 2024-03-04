#include <iostream>

struct IpAddress : public std::error_code {
    std::string firstSubnet;
    std::string secondSubnet;
    std::string thirdSubnet;
    std::string fourthSubnet;
};

IpAddress parseIp (std::string ip) {
    IpAddress result;
    int dotCount = 0;

    for (char symbol: ip) {

        if (symbol == '.') {
            dotCount++;
            continue;
        }
        if (dotCount == 0) {
            result.firstSubnet += symbol;
        }
        if (dotCount == 1) {
            result.secondSubnet += symbol;
        }
        if (dotCount == 2) {
            result.thirdSubnet += symbol;
        }
        if (dotCount == 3) {
            result.fourthSubnet += symbol;
        }

    }
    return result;

}

int main() {
    std::string ip;
    std::cout << "Enter IP: " << std::endl;
    std::cin >> ip;
    std::cout << parseIp(ip);

}
