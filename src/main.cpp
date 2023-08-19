#include <vector>
#include <string>
#include <iostream>
using namespace std;

class LargeFactorial {
public:
    LargeFactorial(long large_num = 1) : _num({1}) {
        while (large_num > 1) {
            mul(large_num);
            --large_num;
        }
    }
    void print() {
        string s;
        cout << _num.back();
        for (int i = _num.size() - 2; i >= 0; --i) {
            s = "000000000";
            int x = _num[i];
            int idx = 8;
            while (x) {
                s[idx--] = (x % 10 + '0');
                x /= 10;
            }
            cout << s;
        }
        cout << endl;
    }

private:
    void mul(int64_t x) {
        if (x <= 1) return;
        int64_t prefix = 0;
        for (int64_t& digit : _num) {
            digit = digit * x + prefix;
            prefix = digit / _MOD;
            digit = digit % _MOD;
        }
        while (prefix) {
            _num.push_back(prefix % _MOD);
            prefix /= _MOD;
        }
    }
    long _MOD = 1e9;
    vector<int64_t> _num;
};

int main(int argc, char** argv)
{
    long large_num = 65536;
    if (argc > 1) large_num = atoi(argv[1]);
    LargeFactorial large_factorial(large_num);
    large_factorial.print();
    return 0;
}
