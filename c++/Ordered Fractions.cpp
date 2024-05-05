#include <bits/stdc++.h>
using namespace std;

int N; 
vector<string> result;

void DFS(int l1, int l2, int r1, int r2) {
    if(l2 > N || r2 > N)
        return;

    DFS(l1, l2, l1 + r1, l2 + r2);
    if(l2 + r2 <= N)
        cout<<(to_string(l1 + r1) + "/" + to_string(l2 + r2))<<endl;
    DFS(l1 + r1, l2 + r2, r1, r2);
}

int main() {
    cin >> N;
    cout<<("0/1")<<endl;
    DFS(0, 1, 1, 1);
    cout<<("1/1")<<endl;
    return 0;
}