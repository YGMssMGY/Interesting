#include <bits/stdc++.h>
using namespace std;

int N;
int john[3], master[3];

int dist(int a, int b) {
    int d = abs(a - b);
    return min(d, N - d);
}

int valid(int a, int b) {
    return dist(a, b) <= 2;
}

int count(int combo[3]) {
    int total = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if (valid(i, combo[0]) && valid(j, combo[1]) && valid(k, combo[2]))
                    total++;
    return total;
}

int main() {
    cin >> N;
    for (int i = 0; i < 3; i++) cin >> john[i];
    for (int i = 0; i < 3; i++) cin >> master[i];

    int total = count(john) + count(master);

    int overlap = 1;
    for (int i = 0; i < 3; i++)
        overlap *= max(0, 5 - dist(john[i], master[i]));

    cout << total - overlap << "\n";

    return 0;
}