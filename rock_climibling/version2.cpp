#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
bool solve(vector<vector<int>>&grid,int diff,int n,int m)
{
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    queue<pair<int,int>>pq;
    //start from left bottom
    pq.push({n-1,0});
    visited[n-1][0]=true;
    //(0,1) means moving to the right
    //(0,-1) means moving to the left
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    while(!pq.empty())
    {
        auto it=pq.front();
        pq.pop();
        int x=it.first;
        int y=it.second;
        if(grid[x][y]==3) return true;
        for(int i=0;i<2;i++)
        {
            //for horizontal movement
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==false)
            {
                if(grid[nx][ny]!=0)
                {
                    //can visit and already not visited
                    pq.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        //for vertical movement
        for(int vt=1;vt<=diff;vt++)
        {
            int up=x-vt;
            int down=x+vt;
            if(up>=0 && visited[up][y]==false )
            {
                if(grid[up][y]!=0)
                {
                    visited[up][y]=true;
                    pq.push({up,y});
                }
            }
            if(down<n && !visited[down][y] )
            {
                if(grid[down][y]!=0)
                {
                    visited[down][y]=true;
                    pq.push({down,y});
                }
            }
        }


    }
    return false;


}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    //perform the binary search
    int left=0,right=n;
    int ans=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(solve(grid,mid,n,m))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }

    }
    if(ans!=-1)
    cout<<ans<<endl;
    else
    cout<<"-1"<<endl;
    return 0;
}
