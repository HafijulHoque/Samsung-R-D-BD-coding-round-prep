#include<bits/stdc++.h>
using namespace std;
//RUNTIME:O(N*M)
int solve(vector<vector<int>>&matrix,int n,int m,int k)
{
    unordered_map<string,int>dict;
    for(int i=0;i<n;i++)
    {
        string current="";
        for(int j=0;j<m;j++)
        {
            current=current+std::to_string(matrix[i][j]);
        }
        dict[current]++;
    }
    int max_rows=0;
    for(const auto &str:dict)
    {
        string pattern=str.first;
        int count=str.second;
        int count_zero=0;
        for(char ch:pattern)
        {
            if(ch=='0')
            count_zero++;

        }
        if(count_zero<=k && !((k-count_zero) & 1) )
        max_rows=std::max(max_rows,count);

    }
    return max_rows;

}
int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int>>matrix(N,vector<int>(M,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int ans=solve(matrix,N,M,K);
    cout<<ans<<endl;

}