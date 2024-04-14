#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, S, C;
    cin >> M >> S >> C;
    vector<int> stalls(C);
    for (int i = 0; i < C; i++) cin >> stalls[i];
    sort(stalls.begin(), stalls.end());
    vector<int> gaps(C - 1);
    for (int i = 0; i < C - 1; i++) gaps[i] = stalls[i + 1] - stalls[i] - 1;
    sort(gaps.begin(), gaps.end());
    int total = 0;
    for (int i = 0; i < C - M; i++) total += gaps[i];
    cout << total + C << endl;
    return 0;
}