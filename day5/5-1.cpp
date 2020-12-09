#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getMiddle(char top, char bot, int max, string line){
    int min = 0;

    for(int i = 0; i < line.length(); i++){
        int pres = (max - min) % 2;
        int mid = (max - min) / 2 + pres ;
        if(line[i] == bot){
            max -= mid;
        } else if (line[i] == top){
            min += mid;
        }
    }
    return min;
}

int main () {
    string line;
    ifstream input_file ("in.txt");

    int maxID = 0;

    if (input_file.is_open()){
        while ( getline (input_file,line) ){
            int row = getMiddle('B', 'F', 127, line.substr(0,7));
            int col = getMiddle('R', 'L', 8, line.substr(7,3));

            int id = row * 8 + col;
            if(id > maxID){
                maxID = id;
            }
        }
        input_file.close();
    }

    cout << maxID << endl;

    return 0;
}