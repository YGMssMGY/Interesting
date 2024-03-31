#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    vector<pair<int, int>> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i].first >> times[i].second;
    }
    sort(times.begin(), times.end());

    int longest_milk = 0, longest_idle = 0;
    int start = times[0].first, end = times[0].second;
    for (int i = 1; i < N; i++) {
        if (times[i].first <= end) {
            end = max(end, times[i].second);
        } else {
            longest_milk = max(longest_milk, end - start);
            longest_idle = max(longest_idle, times[i].first - end);
            start = times[i].first;
            end = times[i].second;
        }
    }
    longest_milk = max(longest_milk, end - start);
    cout << longest_milk << " " << longest_idle << endl;
    return 0;
}