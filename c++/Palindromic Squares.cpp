#include <bits/stdc++.h>
using namespace std;
string toBaseB(int num, int B) {
    string res = "";
    while (num > 0) {
        int digit = num % B;
        if (digit < 10) res += digit + '0';
        else res += digit - 10 + 'A';
        num /= B;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isPalindrome(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    return str == rev;
}

int main() {
    int B;
    cin >> B;
    for (int N = 1; N < 301; N++) {
        string square = toBaseB(N * N, B);
        if (isPalindrome(square)) {
            cout << toBaseB(N, B) << " " << square << endl;
        }
    }
    return 0;
}