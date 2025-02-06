#include<iostream>
#include<climits>
#include<vector>
#include<queue>

using namespace std;
//a class to hold the positions
int up(int i)
{
    if(i==1 || i==2 || i==4 || i==7) return true;
    else
    return false;

}
int down(int i)
{
    if(i==1 || i==2 || i==5 || i==6)
    return true;
    else
    return false;

}
int left(int i)
{
    if(i==1 || i==3 || i==6 || i==7) return true;
    else
    return false;

}
int right(int i)
{
    if(i==1 || i==3 || i==4 || i==5) return true;
    else
    return false;

}
int solve(vector<vector<int>>&grid,int start_x,int start_y,int endo_len)
{

    //----------------base case-------------------------
    if(endo_len==1) return 1;
    if(grid[start_x][start_y]==0) return 1;

    int height=grid.size();
    int width=grid[0].size();
    //visited array
    vector<vector<bool>>visited(height,vector<bool>(width,false));
    //queue for bfs
    queue<pair<pair<int,int>,int>>pq;
    pq.push({{start_x,start_y},1});
    visited[start_x][start_y]=true;
    //directions
    int dir_x[4]={0,0,-1,1};
    int dir_y[4]={-1,1,0,0};
    //d==0 ---> left
    //d=1 --> right
    //d==2 -->up
    //d=3  -->down
    //run the bfs
    int explored_pipe=0;
    while(!pq.empty())
    {
       pair<pair<int,int>,int> it=pq.front();
       pq.pop();
       int curr_x=it.first.first;
       int curr_y=it.first.second;
       int curr_cost=it.second;
       //check all the conditions
       if(curr_cost>endo_len) continue;
       explored_pipe++;

//----------------------dir chech--------------------
       for(int d=0;d<4;d++)
       {
        int new_x=curr_x+dir_x[d];
        int new_y=curr_y+dir_y[d];
        //check if the new position is valid
        if(new_x>=0 && new_x<height && new_y>=0 && new_y<width && visited[new_x][new_y]==false)
        {
    //--------------valid---------------------
    int current_pipe=grid[curr_x][curr_y];
    int next_pipe=grid[new_x][new_y];
        if(d==0)
        {
            if(left(current_pipe) && right(next_pipe))
            {
                pq.push({{new_x,new_y},curr_cost+1});
                visited[new_x][new_y]=true;

            }
           
           

        }
        else if(d==1)
        {
            if(right(current_pipe) && left(next_pipe))
            {
                pq.push({{new_x,new_y},curr_cost+1});
                visited[new_x][new_y]=true;

            }

        }
        else if(d==2)
        {
            if(up(current_pipe) && down(next_pipe))
            {
                pq.push({{new_x,new_y},curr_cost+1});
                visited[new_x][new_y]=true;


            }


        }
        else
        {
            if(down(current_pipe) && up(next_pipe))
            {
                pq.push({{new_x,new_y},curr_cost+1});
                visited[new_x][new_y]=true;


            }

        }
        }
    //-------------------valid-------------------

       }
//----------------------------------dir check ending-------------------

    }
    return explored_pipe;




}
int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        int endo_len=0;
        //x means height/vertical
        //y means width/horizontal
        int x,y;
        cin >> x >> y >>endo_len;
        //solve
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin >> grid[i][j];
        }
        cout<<"testcase: # "<<T<<endl;
        cout<< solve(grid,x,y,endo_len)<<endl;



    }
}
