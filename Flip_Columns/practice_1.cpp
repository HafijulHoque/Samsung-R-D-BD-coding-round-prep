#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<map>
#include<unordered_map>
using namespace std;
int solve(vector<vector<int>>&grid,int k)
{
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;
    //group the similar rows together
    unordered_map<string,int>dict;
    for(int i=0;i<n;i++)
    {
        string curr="";
        for(int j=0;j<m;j++)
        {
            if(grid[i][j])
            curr+='1';
            else
            curr+='0';

        }
        dict[curr]++;
    }
    for(const auto it:dict)
    {
        string str=it.first;
        int row_count=it.second;
        int zero_count=0;
        for(char ch:str)
        {
            if(ch=='0') zero_count++;
        }
        if(zero_count<=k && (k-zero_count)%2==0)
        {
            ans=std::max(ans,row_count);
        }
        
    }


    
    return ans;

}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin >> grid[i][j];
    }
    cout<<solve(grid,k)<<endl;

}