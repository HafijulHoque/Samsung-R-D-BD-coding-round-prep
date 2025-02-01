#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {

    int t ;
    cin>>t;
    
    while(t--){
        
        int n,m,x,y,l;
        cin>>n>>m>>x>>y>>l;
        
        vector<vector<int>>graph(n*m), mat(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                cin>>mat[i][j];
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                
                int pipe = mat[i][j];
                int aa = (i)*(m) +  j;
                
                if(pipe==0)continue;
                
                int a = -1 , b = -1 , c = -1 , d = -1;
                
                if(i != 0){
                    a = (i-1)*m+j;
                }
                if(j != 0 ){
                    b = i*m+(j-1);
                }
                if(j != m-1){
                    c = i*m+(j+1);   
                }
                if(i != n-1 ){
                    d = (i+1)*m+j;
                }
                
                if(pipe==1){
                    
                    if(a!=-1 && (mat[i-1][j]==1 || mat[i-1][j]==2 || mat[i-1][j]==5 || mat[i-1][j]==6))graph[aa].push_back(a);
                    if(b!=-1 && (mat[i][j-1]==1 || mat[i][j-1]==3 || mat[i][j-1]==4 || mat[i][j-1]==5))graph[aa].push_back(b);
                    if(c!=-1 && (mat[i][j+1]==1 || mat[i][j+1]==3 || mat[i][j+1]==6 || mat[i][j+1]==7))graph[aa].push_back(c);
                    if(d!=-1 && (mat[i+1][j]==1 || mat[i+1][j]==2 || mat[i+1][j]==4 || mat[i+1][j]==7))graph[aa].push_back(d);
                }
                else if(pipe==2){
                    if(a!=-1 && (mat[i-1][j]==1 || mat[i-1][j]==2 || mat[i-1][j]==5 || mat[i-1][j]==6))graph[aa].push_back(a);
                    if(d!=-1 && (mat[i+1][j]==1 || mat[i+1][j]==2 || mat[i+1][j]==4 || mat[i+1][j]==7))graph[aa].push_back(d);
                }
                else if(pipe==3){
                    if(b!=-1 && (mat[i][j-1]==1 || mat[i][j-1]==3 || mat[i][j-1]==4 || mat[i][j-1]==5))graph[aa].push_back(b);
                    if(c!=-1 && (mat[i][j+1]==1 || mat[i][j+1]==3 || mat[i][j+1]==6 || mat[i][j+1]==7))graph[aa].push_back(c);
                }
                else if(pipe==4){
                    if(a!=-1 && (mat[i-1][j]==1 || mat[i-1][j]==2 || mat[i-1][j]==5 || mat[i-1][j]==6))graph[aa].push_back(a);
                    if(c!=-1 && (mat[i][j+1]==1 || mat[i][j+1]==3 || mat[i][j+1]==6 || mat[i][j+1]==7))graph[aa].push_back(c);
                }
                else if(pipe==5){
                    if(d!=-1 && (mat[i+1][j]==1 || mat[i+1][j]==2 || mat[i+1][j]==4 || mat[i+1][j]==7))graph[aa].push_back(d);
                    if(c!=-1 && (mat[i][j+1]==1 || mat[i][j+1]==3 || mat[i][j+1]==6 || mat[i][j+1]==7))graph[aa].push_back(c);
                }
                else if(pipe==6){
                    if(b!=-1 && (mat[i][j-1]==1 || mat[i][j-1]==3 || mat[i][j-1]==4 || mat[i][j-1]==5))graph[aa].push_back(b);
                    if(d!=-1 && (mat[i+1][j]==1 || mat[i+1][j]==2 || mat[i+1][j]==4 || mat[i+1][j]==7))graph[aa].push_back(d);
                }
                else if(pipe==7){
                    if(b!=-1 && (mat[i][j-1]==1 || mat[i][j-1]==3 || mat[i][j-1]==4 || mat[i][j-1]==5))graph[aa].push_back(b);
                     if(a!=-1 && (mat[i-1][j]==1 || mat[i-1][j]==2 || mat[i-1][j]==5 || mat[i-1][j]==6))graph[aa].push_back(a);
                }
            }
        }

        int pos = x*m+y;
                   
        vector<int> visited(n*m,0);
        int ans = 0;
                   
        queue<pair<int,int>>bfs;
        bfs.push({pos,1});
        while(!bfs.empty()){
            
            int node = bfs.front().first;
            int depth = bfs.front().second;
            bfs.pop();
            if(!visited[node] && depth <= l){
                visited[node] = 1;
                
                if(graph[node].size()>0){
                    ans++;
                    for(auto x : graph[node])if(x!=-1)bfs.push({x,depth+1});
                }
            }
            
        }
                   
        cout<<ans<<'\n';
        
    }
                   
    return 0;
}

