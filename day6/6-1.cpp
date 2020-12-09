#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main () {

    string line;
    string current_group = "";
    ifstream input_file ("in.txt");

    int count = 0;

    if (input_file.is_open()){
        while ( getline (input_file,line) ){
            current_group += line;

            if(line == ""){
                set<char> sec (begin(current_group), end(current_group));
                count += sec.size();
                current_group = "";
            }
        }
        input_file.close();
    }

    cout << count << endl;

    return 0;
}