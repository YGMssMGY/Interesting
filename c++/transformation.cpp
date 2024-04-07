#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotate90(vector<vector<char>> arr) {
    int N = arr.size();
    vector<vector<char>> res(N, vector<char>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            res[j][N-i-1] = arr[i][j];
    return res;
}

vector<vector<char>> reflect(vector<vector<char>> arr) {
    int N = arr.size();
    for(int i = 0; i < N; i++)
        reverse(arr[i].begin(), arr[i].end());
    return arr;
}

int main() {
    int N;
    cin >> N;
    vector<vector<char>> original(N, vector<char>(N)), transformed(N, vector<char>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> original[i][j];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> transformed[i][j];
    if(rotate90(original) == transformed)
        cout << 1;
    else if(rotate90(rotate90(original)) == transformed)
        cout << 2;
    else if(rotate90(rotate90(rotate90(original))) == transformed)
        cout << 3;
    else if(reflect(original) == transformed)
        cout << 4;
    else if(rotate90(reflect(original)) == transformed || rotate90(rotate90(reflect(original))) == transformed || rotate90(rotate90(rotate90(reflect(original)))) == transformed)
        cout << 5;
    else if(original == transformed)
        cout << 6;
    else
        cout << 7;
    return 0;
}