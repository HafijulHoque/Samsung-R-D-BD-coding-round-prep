#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define INF 1E9
int solve(vector<vector<int>>&grid)
{
    //dp with bitmasking
    int n=grid.size();
    //2^n possible combination
    int total_mask=1<<n;
    //dp[mask][i] means we have visited mask cities in such a way
    //that ended in ith city..dp holds the cost
    //start point set=0th city
    //110 means visited 2nd 1st city and didn't visited 0th city
    vector<vector<int>>dp(total_mask,vector<int>(n,INF));
    //base case
    dp[1][0]=0;
    //RUNTIME:::::O(2^N)
    for(int mask=1;mask<total_mask;mask=mask+2)
    {
        for(int last=0;last<n;last++)
        {
            if(!(mask & (1<<last))) continue;
            for(int next=0;next<n;next++)
            {
                if(mask & (1<<next)) continue;
                //dp relation
                int new_mask=mask | (1<<next);
                dp[new_mask][next]=std::min(dp[new_mask][next],
                dp[mask][last]+grid[last][next]
                );

            }
        }

    }
    //SO dp[11...1][i] contains starting from 0th city we have reached all the cities and now resting at ith
    int min_cost=INT_MAX;
    int full_mask=total_mask-1;
    for(int i=0;i<n;i++)
    {
        min_cost=std::min(min_cost,dp[full_mask][i]+grid[i][0]);
    }
    return min_cost;



}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<vector<int>>grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin >> grid[i][j];
        }
        cout<< solve(grid)<<endl;
    }
}