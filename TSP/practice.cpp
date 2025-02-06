#include<iostream>
#include<climits>
#include<vector>
using namespace std;
#define N 13
#define INF 1e9
int matrix[N][N];
int solve(int n)
{
    //bitmasking with dp
    //dp[mask][i] means for visited cities in mask we will end up at i
    vector<vector<int>>dp(1<<n,vector<int>(n,INF));
    //base case
    dp[1][0]=0;
    int total_mask=1<<n;
    for(int mask=1;mask<total_mask;mask+=2)
    {
        for(int last=0;last<n;last++)
        {
            //last city has to be visited
            if(!(mask & (1<<last))) continue;
            for(int next=0;next<n;next++)
            {
                //next city should not be visited
                if(mask & (1<<next)) continue;
                int new_mask=mask | (1<<next);
                dp[new_mask][next]=std::min(dp[new_mask][next],dp[mask][last]+matrix[last][next]);
            }
        }

    }
    int ans=INT_MAX;
    int full_mask=total_mask-1;
    for(int last=0;last<n;last++)
    {
        ans=std::min(ans,dp[full_mask][last]+matrix[last][0]);
    }
    return ans;



}
int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int n;
        cin >>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
              cin >> matrix[i][j];
            }
        }
        cout<<solve(n)<<endl;

        
    }

}