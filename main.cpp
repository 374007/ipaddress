#include <iostream>

bool valid_octet (std::string octet) {
    bool result = true;
    if (octet.length() <= 3 && !octet.empty()) {
        for (int i = 0; i < octet.length(); i++) {
            if (octet[i] < '0' || octet[i] > '9') {
                result = false;
                break;
            }
        }
        if (result) {
            if (std::stoi(octet) == 0 && octet.length() > 1 || std::to_string(std::stoi(octet)).length() != octet.length()  || std::stoi(octet) < 0 || std::stoi(octet) > 255) {
                result = false;
            }
        }
    }
    else result = false;
    return result;
}

std::string get_address_part (std::string ip, int i) {
    int index = 0;
    std::string octet;
    for (int j = 0; j < ip.length(); j++ ) {
        if (ip[j] >= '0' && ip[j] <= '9') {
            octet += ip[j];
        }
        else if (ip[j] == '.') {
            if ( j == 0 || index == 3 || octet == "" ) {
                octet = "";
                break;
            }
            if (index == i) break;
            else {
              index++ ;
              octet = "";
            }
        }
        else {
            octet = "";
            break;
        }
    }
    valid_octet (octet) ? octet : octet = "";
    return octet;

}

int main() {
    std::string ip;
    bool valid = true;
    std::cout << "Input IP Address!" << std::endl;
    std::cin >> ip;
    for (int i = 1; i < 4 ; i++) {
        if (get_address_part(ip, i).empty()) {
            valid = false;
            break;
        }
    }
    valid ? std::cout << "VALID!!!"<<"\n" : std::cout << "NOT VALID!!!"<<"\n";
    return 0;
}
