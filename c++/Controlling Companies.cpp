#include<bits/stdc++.h>
using namespace std;
int n = 0; 
int a[110][110], f[110];
bool v[110]; 
bool c[110]; 

void dfs(int k) {
    v[k] = true;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            f[i] += a[k][i];
            if (f[i] > 50) {
                c[i] = true;
                dfs(i);
            }
        }
    }
}

int main() {
    int t, x, y, z;
    scanf("%d", &t);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= t; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = z; 
        n = max(n, max(x, y));
    }

    for (int i = 1; i <= n; i++) {
        memset(v, false, sizeof(v));
        memset(c, false, sizeof(c));
        memset(f, 0, sizeof(f));
        dfs(i);
        for (int j = 1; j <= n; j++) {
            if (c[j] && i != j) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}