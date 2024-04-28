#include <iostream>
#include <vector>

using namespace std;

const int N = 55;
int n, m;
int castle[N][N];
int parent[N * N], roomSize[N * N];

int findParent(int x) {
    if (x != parent[x]) {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> castle[i][j];
        }
    }

    for (int i = 0; i < n * m; i++) {
        parent[i] = i;
        roomSize[i] = 1;
    }

    int totalRooms = n * m, maxRoomSize = 1;
    int dx[] = {-1, 0}, dy[] = {0, 1}, wall[] = {2, 4};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                if (castle[i][j] & wall[k]) continue;
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;

                int u = findParent(i * m + j), v = findParent(x * m + y);
                if (u != v) {
                    parent[u] = v;
                    roomSize[v] += roomSize[u];
                    --totalRooms;
                    maxRoomSize = max(maxRoomSize, roomSize[v]);
                }
            }
        }
    }

    cout << totalRooms << endl << maxRoomSize << endl;

    maxRoomSize = 0;
    int roomX, roomY, wallToRemove;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 2; k++) {
                if (!(castle[i][j] & wall[k])) continue;
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;

                int u = findParent(i * m + j), v = findParent(x * m + y);
                if (u != v) {
                    int newSize = roomSize[u] + roomSize[v];
                    if (newSize > maxRoomSize) {
                        maxRoomSize = newSize;
                        roomX = i + 1;
                        roomY = j + 1;
                        wallToRemove = k;
                    }
                }
            }
        }
    }

    cout << maxRoomSize << endl << roomX << " " << roomY << " " << (wallToRemove ? 'E' : 'N') << endl;

    return 0;
}