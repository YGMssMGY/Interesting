#include<bits/stdc++.h>
using namespace std;

int A, B, C;
bool vis[21][21][21];
set<int> ans;

void dfs(int a, int b, int c) {
    if (vis[a][b][c]) return;
    vis[a][b][c] = true;
    if (a == 0) ans.insert(c);
    if (a > 0) {
        if (b < B) dfs(max(0, a - (B - b)), min(B, b + a), c); 
        if (c < C) dfs(max(0, a - (C - c)), b, min(C, c + a)); 
    }
    if (b > 0) {
        if (a < A) dfs(min(A, a + b), max(0, b - (A - a)), c); 
        if (c < C) dfs(a, max(0, b - (C - c)), min(C, c + b)); 
    }
    if (c > 0) {
        if (a < A) dfs(min(A, a + c), b, max(0, c - (A - a))); 
        if (b < B) dfs(a, min(B, b + c), max(0, c - (B - b))); 
    }
}

int main() {
    cin >> A >> B >> C;
    dfs(0, 0, C);
    for (int c : ans) cout << c << " ";
    cout<<endl;
    return 0;
}