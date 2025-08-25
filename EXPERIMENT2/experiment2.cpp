#include <iostream>
using namespace std;

class Experiment2Code {
public:
    static long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;

        long long half = power(base, exp / 2);

        if (exp % 2 == 0) {
            return half * half; 
        } else {
            return base * half * half; 
        }
    }
};

int main() {
    long long base = 2;
    long long exp = 10;

    cout << base << "^" << exp << " = " << Experiment2Code::power(base, exp) << endl;

    return 0;
}
