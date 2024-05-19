#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> roman = {
    {0, 1, 2, 3, 1, 0, 1, 2, 3, 1}, 
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1} 
};

int main() {
    int N;
    cin >> N;

    vector<int> cnt(7);
    for (int i = 1; i <= N; i++) {
        int j = i, k = 0;
        while (j) {
            int d = j % 10;
            cnt[k] += roman[0][d];
            cnt[k+1] += roman[1][d];
            cnt[k+2] += roman[2][d];
            j /= 10;
            k += 2;
        }
    }

    string rom = "IVXLCDM";
    for (int i = 0; i < 7; i++) {
        if (cnt[i] > 0) {
            cout << rom[i] << ' ' << cnt[i] << '\n';
        }
    }

    return 0;
}