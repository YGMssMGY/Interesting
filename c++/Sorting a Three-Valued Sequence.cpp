#include<bits/stdc++.h>
using namespace std;

vector<int> a, flag;
int times_1 = 0, times_2 = 0, times_3 = 0, ans = 0, n;

void draw() {
    for(int i = 0; i < times_1; i++)
        flag[i] = 1;
    for(int i = times_1; i < times_2 + times_1; i++)
        flag[i] = 2;
    for(int i = times_2 + times_1; i < n; i++)
        flag[i] = 3;
}

void Find() {
    for(int i = 0; i < n; i++){
        if(a[i] == 1) times_1++;
        else if(a[i] == 2) times_2++;
        else if(a[i] == 3) times_3++;
    }
    draw();
}

int main() {
    int swap1 = 0, swap2 = 0;
    cin >> n;
    a.resize(n);
    flag.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    Find();
    for(int i = 0; i < n; i++){
        if(flag[i] == 1 && a[i] != 1)
            ans++;
        if(flag[i] == 2 && a[i] != 2)
            ans++;
        if(flag[i] == 1 && a[i] == 2)
            swap1++;
        if(flag[i] == 2 && a[i] == 1)
            swap2++;
    }
    ans -= min(swap1, swap2);
    cout << ans;
    return 0;
}