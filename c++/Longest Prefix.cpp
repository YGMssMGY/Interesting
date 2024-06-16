#include <bits/stdc++.h>
using namespace std;
int dp[200005];
set<string> s[11]; 
int main() {
    string temp, S;
    int m = 0;
    while (cin >> temp && temp != ".") {
        s[temp.size()].insert(temp);
        m = max(m, int(temp.size()));
    }
    string line;
    while (cin >> line) {
        S += line;
    }
    int ans = 0;
    dp[0] = 1; 

    for (int i = 1; i <= S.length(); ++i) {
        for (int j = 1; j <= min(i, m); ++j) {
            if (dp[i - j]) {
                string sub = S.substr(i - j, j);
                if (s[j].find(sub) != s[j].end()) {
                    dp[i] = 1;
                    ans = i; 
                    break; 
                }
            }
        }
    }
    cout << ans << endl; 
    return 0;
}