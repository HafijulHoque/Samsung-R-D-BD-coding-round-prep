#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dp(vector<vector<int>>& hill, vector<vector<bool>>& visited, int x, int y, int diff, int jump) {
    
    if (y >= (int)hill[0].size() || y < 0 || x < 0 || x >= (int)hill.size() || visited[x][y]) {
        return INT_MAX;
    }
    if (hill[x][y] == 3) {
        return max(diff, jump);
    }
    
    visited[x][y] = true;
    
    int ans = INT_MAX;
    if (hill[x][y] == 1) {
        
        if (jump != 0) {
            diff = max(diff, jump);
            jump = 0;
        }
        if (y + 1 < (int)hill[0].size() && (hill[x][y + 1] == 1||hill[x][y + 1] == 3)) {
            ans = min(ans, dp(hill, visited, x, y + 1, diff, jump));
        }
        if (y - 1 >= 0 && (hill[x][y - 1] == 1||hill[x][y - 1] == 3)) {
            ans = min(ans, dp(hill, visited, x, y - 1, diff, jump));
        }
        
    }
    ans = min(ans, dp(hill, visited, x + 1, y, diff, jump + 1));
    ans = min(ans, dp(hill, visited, x - 1, y, diff, jump + 1));
    
    visited[x][y] = false;
    
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> hill(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> hill[i][j];
        }
    }
    
    int result = dp(hill, visited, n - 1, 0, 0, 0);
    
    cout << result << endl;
    
    
    return 0;
}
