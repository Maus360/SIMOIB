#include <iostream>
#include <cmath>

unsigned long degree(long a, long b) {
    unsigned long sum=1;
    for(int i=0;i<b;i++)
        sum*=a;
    return sum;
}

int func_phi(int n) {
    int ret = 1;
    for (int i = 2; i * i <= n; ++i) {
        int p = 1;
        while (n % i == 0) {
            p *= i;
            n /= i;
        }
        if ((p /= i) >= 1) ret *= p * (i - 1);
    }
    return --n ? n * ret : ret;
}

int PrimitiveRoot(int g, int m) {
    int phi = func_phi(m);
    auto *arr = new char[phi];
    int s = 123;
    int size = 0;
    bool b = true;

    for (int i = 0; (i <= phi - 1 && b); i++) {
        auto j = static_cast<unsigned int>(std::pow(g, i));
        unsigned int num = (j % m);
        for (int u = 0; u < size; u++) {
            if (arr[u] == num)
                b = false;
        }
        arr[size] = static_cast<char>(num);
        size++;
    }
    if (g == s)
        std::cout << "Is number " << g << " is a primitive root modulo " << m << ": " << "1" << std::endl;
    else
        std::cout << "Is number " << g << " is a primitive root modulo " << m << ": " << "0" << std::endl;
    return s;
}

class user{
    private:
        unsigned long j;
        unsigned long key;
        unsigned long x{};
    public:

        explicit user(unsigned long x){
            this->x = x;
            this->p = 3877;
        }
        unsigned long p;
        unsigned long a = 2;

        unsigned long generate_token(){
            j = degree(a, this->x) % p;
            std::cout << j << std::endl;
            return j;
        }

        unsigned long generate_union_token(unsigned long y){
            key = degree(y, this->x) % p;
            return key;
        }
    };

int main() {
    user Alice(9), Bob(7);
    unsigned long b = Bob.generate_token();
    unsigned long a = Alice.generate_token();
    //    std::cout << Alice.x << " " << Bob.x << std::endl;

    unsigned long c = Alice.generate_union_token(b);
    unsigned long d = Bob.generate_union_token(a);
    std::cout << c << " " << d << std::endl;

    return 0;
}

