#include <iostream>
#include <stdlib.h>

int main(){
    int numbers[1000];
    for(int i = 0; i < 1000; ++i){
        std::cin >> numbers[i];
        if(numbers[i] == -1){
            break;
        }
    }

    for(int i = 0; i < 1000; ++i){
        for(int j = 0; j < 1000; ++j){
            if(numbers[i] + numbers[j] == 2020){
                std::cout << numbers[i] * numbers[j] << std::endl;     
                exit(0);
            }
        }
    }

    return -1;
}