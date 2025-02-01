#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//TSP-PROBLEM
//Bitmasking dp
//time complexity:O(2^N*N^2)
const int INF=1e9;
int solve_TSP(vector<vector<int>>&M,int N)
{
    //represent a mask where all cities have been visited
    int total_mask=1<<N;
    int full_mask=total_mask-1;
    //dp[mask][i]=visited mask cities and now ended up at ith city
    
    vector<vector<int>>dp(total_mask,vector<int>(N,INF));
    //base case
    dp[1][0]=0;
    for(int mask=1;mask<total_mask;mask=mask+2)
    {
        for(int last=0;last<N;last++)
        {
            //check consideration for last cities
            if( !(mask & (1<<last))) continue;
            for(int next=0;next<N;next++)
            {
                if(mask & (1<<next)) continue;
                //calculate new mask by setting the next city as visited
                int newmask=mask | (1<<next);
                dp[newmask][next]=std::min(dp[newmask][next],dp[mask][last]+M[last][next]);
             
            }
        }
    }
    int res=INF;
    for(int last=0;last<N;last++)
    {
        res=std::min(res,dp[full_mask][last]+M[last][0]);
    }
    return res;
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >>N;
        vector<vector<int>>M(N,vector<int>(N));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
            
        }
        int ans;
        ans=solve_TSP(M,N);
        cout<<ans<<endl;
        
//           for(int i=0;i<N;i++)
//         {
//             for(int j=0;j<N;j++)
//             {
//                 cout<<M[i][j]<<" ";
//             }
//               cout<<endl;
            
//         }
        
    }
    return 0;
}
