#include <iostream>
#include <stdlib.h>

int main(){
    char tmp;
    int min, max;
    char letter;
    std::string password;

    int correct = 0;

    for(int i = 0; i < 1000; i++){
        std::cin >> min >> tmp >> max >> letter >> tmp >> password;

        int count = 0;
        for(int j = 0; j < password.length(); j++){
            if(password[j] == letter){
                count++;
            }
        }
        if(count >= min && count <= max){
            correct++;
        }
    }

    std::cout << correct << std::endl;

    return -1;
}