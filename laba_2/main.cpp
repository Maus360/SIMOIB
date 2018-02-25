#include <iostream>
#include <fstream>

std::string propis = "abcdefghijklmnopqrstuvwxyz";
std::string strochnie = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string code(std::string& str, int n){
    std::string result;
    for (char i : str) {
        if (i != ' '){
            if (propis.find(i) < 27) result += propis[(propis.find(i) + n) % 26];
            else result += strochnie[(strochnie.find(i) + n) % 26];
        }
        else result += i;

    }
    return result;
}

void decode(std::string& str){
    for (int i = 1; i < 26; i++){
        std::string result;
        for (char j : str) {
            if (j != ' '){
                if (propis.find(j) < 27) result += propis[(propis.find(j) + i) % 26];
                else result += strochnie[(strochnie.find(j) + i) % 26];
            }
            else result += j;
        }
        std::cout << result << std::endl;
    }
}

int main() {
    std::ifstream in;
    std::string s, s1;
    in.open("data");
    while (not in.eof()){
        in >> s;
        s1 += " " + s;
    }
    s1 = s1.substr(1, s1.length());
    std::cout << s1 << std::endl;
    std::string res = code(s1, 1);
    std::cout << res << std::endl;
    std::cout << "=================" << std::endl;
    decode(res);
    std::cout << propis.find('i');
    return 0;
}

