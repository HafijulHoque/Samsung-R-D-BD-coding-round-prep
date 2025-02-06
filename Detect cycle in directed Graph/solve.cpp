#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

void dfs(int node, vector<vector<int>>&graph, vector<int>&visited, vector<int>&path, vector<vector<int>>&st){
    
    
    visited[node] = 1;
    path.push_back(node);
    for(auto i : graph[node]){
        if(visited[i]==0){
            dfs(i, graph, visited, path,st);
        }
        else if(visited[i]==1){
            
            vector<int>cycle;int match = 0;
            for(int j = 0 ; j < (int)path.size() ; j++){
                if(path[j] == i){
                    match = j ;break;
                }
            }
            for(int j = match ; j < (int)path.size() ; j++)cycle.push_back(path[j]);
            st.push_back(cycle);
            
        }
    }
    
    visited[node] = 0;
    path.pop_back();
    
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, e;
    cin>>n>>e;
    
    vector<vector<int>>graph(n+1);
    
    for(int i =0 ; i < e ; i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
    }
    
    vector<int>visited(n+1,0);
    vector<int>path;
    
    vector<vector<int>>st;
    
    for(int i = 1 ; i <= n ; i++){
        
        if(!visited[i])dfs(i, graph, visited, path,st);
    }
    int min_sum = INT_MAX, ans = 0;
    for(int i =  0 ; i < (int)st.size() ; i++){
        int sum = 0 ;
        for(int j = 0 ; j <(int)st[i].size() ; j++){
            
            sum+=st[i][j];
        }
        if(sum < min_sum)ans = i;
    }
    sort(st[ans].begin(), st[ans].end());
    for(int i = 0 ; i  < (int)st[ans].size() ; i++)cout<<st[ans][i]<<" ";
    return 0;
}

