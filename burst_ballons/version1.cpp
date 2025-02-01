#include <bits/stdc++.h>
using namespace std;

class BalloonShooter {
private:
    void printDP(const vector<vector<int>>& dp) {
        for(size_t i = 0; i < dp.size(); i++) {
            for(size_t j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

public:
    int maxPoints(vector<int>& balloons) {
        // Handle empty input
        if(balloons.empty()) return 0;
        
        // Create padded array with 1's at boundaries
        vector<int> nums;
        nums.push_back(1);  // Left boundary
        for(int balloon : balloons) {
            if(balloon > 0) {  // Only include positive values
                nums.push_back(balloon);
            }
        }
        nums.push_back(1);  // Right boundary
        
        int n = nums.size();
        // Initialize dp table with zeros
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // For all possible window sizes
        for(int window = 2; window < n; window++) {
            // For all possible left boundaries
            for(int left = 0; left < n - window; left++) {
                int right = left + window;
                
                // Try each balloon as the last one to burst
                for(int i = left + 1; i < right; i++) {
                    int points;
                    if(left == 0 && right == n-1) {
                        // Case when bursting the last remaining balloon
                        points = nums[left] * nums[i] * nums[right];
                    } else {
                        // Regular case: multiply adjacent values
                        points = nums[left] * nums[right];
                    }
                    
                    // Add points from left and right subarrays
                    points += dp[left][i] + dp[i][right];
                    
                    // Update maximum points possible
                    dp[left][right] = max(dp[left][right], points);
                }
                
                // Uncomment to debug dp table after each iteration
                // printDP(dp);
            }
        }
        
        // Return maximum points possible
        return dp[0][n-1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> balloons(n);
    for(int i = 0; i < n; i++) {
        cin >> balloons[i];
    }
    
    BalloonShooter solver;
    cout << solver.maxPoints(balloons) << "\n";
    
    return 0;
}