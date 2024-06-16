#include<bits/stdc++.h>
using namespace std;
const int MOD = 9901;

int dp[205][105];

int main() {
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for(int j = 0; j <= k; j++) dp[1][j] = 1; 
    for(int i = 1; i <= n; i += 2) {
        for(int j = 2; j <= k; j++) { 
            for(int t = 1; t < i; t += 2) { 
                int left = t, right = i - t - 1;
                dp[i][j] += (dp[left][j-1] * dp[right][j-1]) % MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    int result = (dp[n][k] - dp[n][k-1] + MOD) % MOD; 
    cout << result << endl;
    return 0;
}