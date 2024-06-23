#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, N;
    cin >> V >> N;
    vector<int> coins(V);
    for (int i = 0; i < V; ++i) {
        cin >> coins[i];
    }
    vector<long long> dp(N + 1, 0);
    dp[0] = 1; 
    for (int i = 0; i < V; ++i) {
        for (int j = coins[i]; j <= N; j++) {
            dp[j] += dp[j - coins[i]]; 
        }
    }
    cout << dp[N] << endl; 

    return 0;
}