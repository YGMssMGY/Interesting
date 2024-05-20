#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isRunaroundNumber(int num) {
    string str = to_string(num);
    int len = str.size();
    vector<int> visited(len, 0);
    int i = 0;
    do {
        i = (i + str[i] - '0') % len;
        if (visited[i]) return false;
        visited[i] = 1;
    } while (i != 0);
    return count(visited.begin(), visited.end(), 1) == len;
}

int main() {
    int M;
    cin >> M;
    while (!isRunaroundNumber(++M));
    cout << M << endl;
    
    return 0;
}
