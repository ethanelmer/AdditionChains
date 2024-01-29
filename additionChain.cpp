#include <iostream>
#include <vector>
#include <bitset>

std::string decimalToBinary(int decimalNumber) {
    return std::bitset<32>(decimalNumber).to_string().substr(std::bitset<32>(decimalNumber).to_string().find("1"));
}

int main() {

    int userNumber = 0;
    std::cout << "Enter a number: ";
    std::cin >> userNumber;

    std::string binaryNumber = decimalToBinary(userNumber);

    std::cout <<"Binary Number: "<< binaryNumber << std::endl;

    std::vector<int> additionChain;

    additionChain.push_back(1);
    for(int i=1; i<binaryNumber.length(); i++){
        int last = additionChain.back();
        additionChain.push_back(last + last);
        if(binaryNumber[i] == '1'){
            additionChain.push_back((last+last)+1);
        }
    }

    std::cout << "Addition Chain: ";
    for(int i=0; i<additionChain.size(); i++){
        std::cout << additionChain[i] << " ";
    }

    return 0;
}