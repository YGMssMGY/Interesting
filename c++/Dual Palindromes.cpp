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
    int N, S;
    cin >> N >> S;
    int count = 0;
    for (int num = S + 1; count < N; num++) {
        int baseCount = 0;
        for (int B = 2; B <= 10; B++) {
            if (isPalindrome(toBaseB(num, B))) {
                baseCount++;
            }
            if (baseCount >= 2) {
                cout << num << endl;
                count++;
                break;
            }
        }
    }
    return 0;
}