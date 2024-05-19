#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = N * (N + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    sum /= 2;
    vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] += dp[i - 1][j - i];
            }
        }
    }
    cout << dp[N][sum] / 2 << endl;
    return 0;
}