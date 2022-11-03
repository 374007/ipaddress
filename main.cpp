#include <iostream>
bool valid_octet (std::string octet) {
    if ( int octet )
}
std::string get_address_part (std::string ip, int i) {
    int index = 0;
    std::string octet = "" ;
    for (int j = 0; j < ip.length(); j++ )
    {
        if (ip[j] >= '0' && ip[j] <= '9') {
            octet += ip [j];
        }
        else if ( ip[j] == '.') {
           if ( j==0 || j == ip.length()-1 ) {
               octet = "";
               break;
           }
           if (index == i) break;
           else {
               index++;
               octet = "";
           }
        }
        else {
           octet = "" ;
           break;
        }
    }

    return octet;
}
int main() {
    std::string ip;
    std::cout << "Input IP Address!" << std::endl;
    std::cin >> ip;
    std::cout << get_address_part(ip,0)<<"\n";
    std::cout << get_address_part(ip,1)<<"\n";
    std::cout << get_address_part(ip,2)<<"\n";
    std::cout << get_address_part(ip,3)<<"\n";
    return 0;
}
