#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> a;

// Function to check if the destination (cell with 3) is reachable with given step size l
bool canReach(int l) {
    vector<vector<int>> v(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    
    q.push({n - 1, 0}); // Start from bottom-left
    v[n - 1][0] = 1;

    int dx[] = {0, 0, -1, 1}; // Left, Right, Up, Down
    int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (a[x][y] == 3) return true; // Found target

        // Normal movement
        for (int d = 0; d < 2; d++) { // Left & Right
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !v[nx][ny] && (a[nx][ny] == 1 || a[nx][ny] == 3)) {
                q.push({nx, ny});
                v[nx][ny] = 1;
            }
        }

        // Vertical jumps with distance `l`
        for (int h = 1; h <= l; h++) {
            int up = x - h, down = x + h;
            if (up >= 0 && !v[up][y] && (a[up][y] == 1 || a[up][y] == 3)) {
                q.push({up, y});
                v[up][y] = 1;
            }
            if (down < n && !v[down][y] && (a[down][y] == 1 || a[down][y] == 3)) {
                q.push({down, y});
                v[down][y] = 1;
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    a.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int left = 0, right = n, ans = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canReach(mid)) {
            ans = mid;  // Store result
            right = mid - 1; // Try to minimize `l`
        } else {
            left = mid + 1; // Increase `l`
        }
    }

    if (ans != -1)
        cout << ans << endl;
    else
        cout << "-1" << endl; // If no valid `l` found

    return 0;
}
