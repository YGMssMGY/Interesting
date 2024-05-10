#include <iostream>
#include <vector>
using namespace std;

int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}

int main() {
    int N, B, D;
    cin >> N >> B >> D;
    vector<int> codewords;
    codewords.push_back(0);
    for (int i = 1; i < (1 << B); i++) {
        bool valid = true;
        for (int j : codewords) {
            if (hammingDistance(i, j) < D) {
                valid = false;
                break;
            }
        }
        if (valid) {
            codewords.push_back(i);
            if (codewords.size() == N) {
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << codewords[i] << (i % 10 == 9 || i == N - 1 ? "\n" : " ");
    }
    return 0;
}