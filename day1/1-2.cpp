#include <iostream>
#include <stdlib.h>

int main(){
    int numbers[1000];
    int count = 0;
    for(int i = 0; i < 1000; ++i){
        std::cin >> numbers[i];
        if(numbers[i] == -1){
            break;
        }
        count++;
    }

    for(int i = 0; i < count; ++i){
        if(numbers[i] > 2020) continue;
        for(int j = 0; j < count; ++j){
            if(numbers[i] + numbers[j] > 2020) continue;
            for(int k = 0; k < count; ++k)
                if(numbers[i] + numbers[j] + numbers[k] == 2020){
                    std::cout << numbers[i] << " " << numbers[j] << " " << numbers[k] << " " << numbers[i] + numbers[j] + numbers[k] << std::endl;     
                    std::cout << numbers[i] * numbers[j] * numbers[k] << std::endl;   
                    exit(0);
                }
        }
    }

    return -1;
}