#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

bool match_regex(string str){
    const regex byr(".*byr:(19[2-8][0-9]|199[0-9]|200[0-2]).*");
    const regex iyr(".*iyr:(201[0-9]|2020).*");
    const regex eyr(".*eyr:(202[0-9]|2030).*");
    const regex hcl(".*hcl:#(([0-9]|[a-f]){6}).*");
    const regex ecl(".*ecl:(amb|blu|brn|gry|grn|hzl|oth).*");
    const regex pid(".*pid:(\\d{9}) .*");
    const regex hgt("(.*hgt:(1[5-8][0-9]|19[0-3])cm.*)|(.*hgt:(59|6[0-9]|7[0-6])in.*)");
    return regex_match(str, byr) 
        && regex_match(str, iyr)
        && regex_match(str, eyr)
        && regex_match(str, hcl)
        && regex_match(str, ecl)
        && regex_match(str, pid)
        && regex_match(str, hgt);
}

int main () {
    string line;
    ifstream input_file ("in.txt");

    string required[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    string curret_check = "";

    int present = 0;
    int valid = 0;

    if (input_file.is_open()){
        while ( getline (input_file,line) ){
            curret_check += " ";
            curret_check += line;
            if(line == ""){
                bool passed = true;

                for(int i = 0; i < 8; i++){
                    size_t found = curret_check.find(required[i]);
                    if (found==string::npos && required[i] !="cid"){
                        passed = false;
                        break;
                    }
                }
                if(passed){
                    present++;
                    if( match_regex(curret_check)){
                        valid++;
                    }                    
                }
                curret_check = "";
            }
        }
        input_file.close();
    }

    cout << valid << endl;

    return 0;
}