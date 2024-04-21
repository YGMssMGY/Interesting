#include<bits/stdc++.h>
using namespace std;

int N;

int dist(int a, int b) {
    int d = abs(a - b);
    return min(d, N - d);
}

int main() {
    int a[3], b[3];    
    int total = 0;
    cin >> N;
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];


    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if ((dist(i, a[0]) <= 2 && dist(j, a[1]) <= 2 && dist(k, a[2]) <= 2) ||
                    (dist(i, b[0]) <= 2 && dist(j, b[1]) <= 2 && dist(k, b[2]) <= 2))
                    total++;

    cout << total << endl;

    return 0;
}