#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main () {

    string line;
    string current_group = "";
    ifstream input_file ("in.txt");

    char a = 97;
    int count = 0;
    int ppl = 0;

    int letters[30] = {0};

    if (input_file.is_open()){
        while ( getline (input_file,line) ){
            current_group += line;
            ppl++;

            if(line == ""){
                for(int i = 0; i < current_group.size(); i++){
                    int pos = (int)current_group[i] - a;
                    if(++letters[pos] == ppl-1){
                        count++;
                    }
                }
                fill(letters, letters + 30, 0);
                current_group = "";
                ppl = 0;
            }
        }
        input_file.close();
    }

    cout << count << endl;

    return 0;
}