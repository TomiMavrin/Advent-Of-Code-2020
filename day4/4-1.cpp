#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::string line;
    std::ifstream input_file ("in.txt");

    std::string required[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    std::string curret_check = "";

    int count = 0;

    if (input_file.is_open()){
        while ( getline (input_file,line) ){
            curret_check += line;
            if(line == ""){
                bool passed = true;
                for(int i = 0; i < 8; i++){
                    std::size_t found = curret_check.find(required[i]);
                    if (found==std::string::npos && required[i] !="cid"){
                        passed = false;
                        break;
                    }
                }
                if(passed){
                    count++;
                }
                curret_check = "";
            }
        }
        input_file.close();
    }

    std::cout << count << std::endl;

    return 0;
}