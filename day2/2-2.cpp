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

        if(password[min-1] == letter && password[max-1] != letter || password[min-1] != letter && password[max-1] == letter ){
            correct++;
        }
    }

    std::cout << correct << std::endl;

    return 0;
}