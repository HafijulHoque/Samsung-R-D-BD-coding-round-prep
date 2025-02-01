#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
const int INF=1e9;
int find_distance(pair<int,int>a,pair<int,int>b)
{
    return std::abs(a.first-b.first)+std::abs(a.second-b.second);
}
int solve_tsp(vector<pair<int,int>>&customer,pair<int,int>&office,pair<int,int>&home,int n)
{
    //dynamic programming with bit masking
    int total_mask=(1<<n);
    //dp[mask][i]=visited mask customers and ended at ith customer
    vector<vector<int>>dp(total_mask,vector<int>(n,INF));
    //base case
    //for the 1st customer the base case will be [1][0]=distance from office to his home
    //for the second customer the base case will be [10][1]=distance from office to his home
    for(int i=0;i<n;i++)
    dp[1<<i][i]=find_distance(customer[i],office);

    //solve the dp table
    for(int mask=1;mask<total_mask;mask=mask+1)
    {
        for(int last=0;last<n;last++)
        {
            if( !(mask & (1<<last))) continue;
            for(int next=0;next<n;next++)
            {
                if(mask & (1<<next)) continue;
                //calculate the new mask
                int newmask=mask | (1<<next);

                dp[newmask][next]=std::min(dp[newmask][next],dp[mask][last]+find_distance(customer[last],customer[next]));

            }
        }

    }
    int result=INF;
    int full_mask=total_mask-1;
    for(int i=0;i<n;i++)
    {
        result=std::min(result,dp[full_mask][i]+find_distance(customer[i],home));
    }
    return result;


}
int main()
{
    int T;
    T=10;
    int index=1;
    while(T--)
    {
        int n;
        cin>>n;
        //n means the number of customers
        pair<int,int>office;
        pair<int,int>home;
        vector<pair<int,int>>customer(n);
        //office location
        cin>>office.first>>office.second;
        cin>>home.first>>home.second;
        for(int i=0;i<n;i++)
        cin>>customer[i].first>>customer[i].second;

        int ans=solve_tsp(customer,office,home,n);
        cout<<"# "<<index<<" "<<ans<<endl;
        index++;


        
    }
    return 0;
}