#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> A(9), B(8);
    for (int i = 0; i < 9; i++) cin >> A[i];
    for (int i = 0; i < 8; i++) cin >> B[i];

    int total_A = accumulate(A.begin(), A.end(), 0);
    int total_B = accumulate(B.begin(), B.end(), 0);

    int runs_needed = max(0, total_A - total_B + 1);
    cout << runs_needed << endl;

    return 0;
}