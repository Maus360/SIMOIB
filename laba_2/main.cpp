#include <iostream>
#include <fstream>

std::string propis = "abcdefghijklmnopqrstuvwxyz";
std::string strochnie = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string encrypt(std::string &str, int n){
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

void decrypt(std::string &str){
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

using namespace std;

int main() {
    std::ifstream in("data");
    std::string s, s1;
    while (!in.eof()){
        getline(in, s);
        s1 += s;
    }
    in.close();

    //s1 = s1.substr(0, s1.length());
    std::cout << s1 << std::endl;
    std::string res = encrypt(s1, 1);
    std::cout << res << std::endl;
    std::cout << "=================" << std::endl;
    decrypt(res);
    std::cout << propis.find('i');
    return 0;
}

