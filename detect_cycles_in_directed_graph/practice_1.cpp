#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int min_cycle_sum=INT_MAX;
int min_cycle_length=INT_MAX;
int ans[50];

void dfs(vector<vector<int>>&adj_list,int node,int parent,vector<int>&dfs_visited,vector<int>&sum)
{

    int num_of_nodes=adj_list.size();
    //calculate the rank
    dfs_visited[node]=dfs_visited[parent]+1;
    //update the sum
    sum[node]=node+sum[parent];
    for(int u:adj_list[node])
    {
        //traverse all the neighbors
        if(dfs_visited[u])
        {
            //cycle exist
            // u is the node where cycle has started
            //node is the last of the cycle
            int current_cycle_sum=sum[node]-sum[u]+u;
            if(current_cycle_sum<min_cycle_sum)
            {
                //update the sum
                min_cycle_sum=current_cycle_sum;
                //record the new cycle
                int index=0;
                for(int i=0;i<num_of_nodes;i++)
                {

                   if(sum[u]<=sum[i] && sum[i]<=sum[node])
                   {
                    ans[index++]=i;
                   
                   }


                }
                if(index<min_cycle_length)
                min_cycle_length=index;

            }

        }
        else 
        {
            //dfs
            dfs(adj_list,u,node,dfs_visited,sum);
        }
        
    }
    //finished traversing
    dfs_visited[node]=0;
    sum[node]=0;


    


}
int main()
{
    //n-->nodes
    //m-->edges
    int n,m;
    cin >> n >>m;
    //adj list
    vector<vector<int>>adj_list(n+1);
    //a visited list to maintain the list of the visited
    vector<bool>visited(n+1,false);
    //to hold the rank
    vector<int>dfs_visited(n+1,0);
    //calculate the sum
    vector<int>sum(n+1,0);
    //building the graph
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >>v;

        adj_list[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfs_visited[i])
        {
            dfs(adj_list,i,0,dfs_visited,sum);

        }
    }
    for(int i=0;i<min_cycle_length;i++)
    cout<<ans[i]<<" ";
    cout<<endl;


}