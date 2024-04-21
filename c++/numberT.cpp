#include<bits/stdc++.h>
using namespace std;

const int MAX_R = 1000;
int R;
int a[MAX_R+1][MAX_R+1];
int dp[MAX_R+1][MAX_R+1];

int main() {
    cin >> R;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= i; j++)
            if (j == 1)
                dp[i][j] = dp[i-1][j] + a[i][j];
            else if (j == i)
                dp[i][j] = dp[i-1][j-1] + a[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];

    int ans = 0;
    for (int j = 1; j <= R; j++)
        ans = max(ans, dp[R][j]);

    cout << ans << endl;

    return 0;
}