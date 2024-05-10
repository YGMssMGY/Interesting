#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
const int MAXG = 15;
const int INF = 1e9;
int dp[MAXN+1][1<<MAXG];
int vit[MAXN+1];
int feed[MAXG+1][MAXN+1];
int v, g;

int ans[MAXG+1];
int c[MAXG+1];
int minn = INF;

bool pd(int x) {
    for(int i = 1; i <= v; i++) {
        int sum = 0;
        for(int j = 1; j <= x; j++)
            sum += feed[c[j]][i];
        if(sum < vit[i]) return false;
    }
    return true;
}

void search(int t, int s) {
    if(t > g) {
        if(pd(s)) {
            if(s < minn) {
                minn = s;
                for(int i = 1; i <= minn; i++)
                    ans[i] = c[i];
            }
        }
        return;
    }
    c[s+1] = t;
    search(t+1, s+1);
    c[s+1] = 0;
    search(t+1, s);
}

int main() {
    cin >> v;
    for(int i = 1; i <= v; i++) cin >> vit[i];
    cin >> g;
    for(int i = 1; i <= g; i++) {
        for(int j = 1; j <= v; j++) cin >> feed[i][j];
    }

    search(1, 0);

    cout << minn << " ";
    sort(ans+1, ans+minn+1);
    for(int i = 1; i <= minn; i++)
        cout << ans[i] << (i == minn ? "\n" : " ");

    return 0;
}