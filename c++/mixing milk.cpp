#include <bits/stdc++.h>
using namespace std;

struct Farmer {
    int price, amount;
};

bool compare(Farmer a, Farmer b) {
    return a.price < b.price;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Farmer> farmers(M);
    for (int i = 0; i < M; i++) cin >> farmers[i].price >> farmers[i].amount;
    sort(farmers.begin(), farmers.end(), compare);
    int cost = 0;
    for (int i = 0; i < M && N > 0; i++) {
        int amount = min(N, farmers[i].amount);
        cost += amount * farmers[i].price;
        N -= amount;
    }
    cout << cost << endl;
    return 0;
}