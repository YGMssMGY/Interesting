#include<bits/stdc++.h>
using namespace std;
    int N;
int main() {
    cin >> N;
    vector<int> hills(N);
    for (int i = 0; i < N; i++) cin >> hills[i];

    int min_cost = INT_MAX;
    for (int i = 0; i + 17 <= 100; i++) {
        int cost = 0;
        for (int j = 0; j < N; j++) {
            if (hills[j] < i) cost += (i - hills[j]) * (i - hills[j]);
            else if (hills[j] > i + 17) cost += (hills[j] - i - 17) * (hills[j] - i - 17);
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;

    return 0;
}