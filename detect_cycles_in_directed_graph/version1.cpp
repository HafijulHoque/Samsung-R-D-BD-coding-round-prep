#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//Max Number of Node is 10
int cycle[15];
int sum[15];
int min_cycle_sum=INT_MAX;
int cycle_len;
int N;
void dfs(int node,int parent,vector<vector<int>>&adj_list,vector<bool>&visited,vector<int>&dfs_visited)
{
    //dfs visited thus store the order in which node have been visited

    dfs_visited[node]=dfs_visited[parent]+1;
    //The sum of the nodes visited in a path
    sum[node]+=(node+sum[parent]);
    visited[node]=true;
    for(int neighbors:adj_list[node])
    {
        if(dfs_visited[neighbors])
        {
            //cycle
            int current_cycle_sum=sum[node]-sum[neighbors]+neighbors;
            if(current_cycle_sum<min_cycle_sum)
            {
                //update the cycle
                int index=0;
                for(int i=1;i<=N;i++)
                {
                    if(dfs_visited[i]>=dfs_visited[neighbors] && dfs_visited[i]<=dfs_visited[node])
                    {
                        cycle[index++]=i;

                    }
                }
                min_cycle_sum=current_cycle_sum;
                cycle_len=index;
            }

        }
        else
        {
            dfs(neighbors,node,adj_list,visited,dfs_visited);

        }
    }
    dfs_visited[node]=0;
    sum[node]=0;



}
int main()
{
    int n,m;
    cin>>n>>m;
    N=n;
    vector<vector<int>>adj_list(n+1);
    vector<bool>visited(n+1,false);
    vector<int>dfs_visited(n+1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        dfs(i,0,adj_list,visited,dfs_visited);
    }
    //print the cycle
    for(int i=0;i<cycle_len;i++)
    cout<<cycle[i]<<" ";
    cout<<endl;



   
}