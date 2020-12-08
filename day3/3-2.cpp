#include <iostream>

int met(int xp, int yp, char map[323][31]){
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
                y += yp;
                x += xp;
            }
        }
    }

    return count;
}

int main(){
    char map[323][31];
    for(int i = 0; i < 323; i++){
        for(int j = 0; j < 31; j++){
            std::cin >> map[i][j]; 
        }
    }

    long res11 = met(1, 1, map);
    long res31 = met(3, 1, map);
    long res51 = met(5, 1, map);
    long res71 = met(7, 1, map);
    long res12 = met(1, 2, map);
    

    std::cout << res11 * res31 * res51 * res71 * res12 << std::endl;


    return 0;
}