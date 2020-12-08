#include <iostream>

int main(){
    char map[323][31];

    int x = 0;
    int y = 0;

    int count = 0;

    for(int i = 0; i < 323; i++){
        for(int j = 0; j < 31; j++){
            std::cin >> map[i][j]; 
            if(y == i && x % 31 == j ){
                if(map[i][j] == '#'){
                    count ++;
                }
                y++;
                x += 3;
            }
        }
    }

    std::cout << count << std::endl;


    return 0;
}