#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
bool valid(int x, int y, int n, int m)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else
        return false;
}
bool move_left(int i)
{
    if (i == 1 || i == 3 || i == 6 || i == 7)
        return true;
    else
        return false;
}
bool move_right(int i)
{
    if (i == 1 || i == 3 || i == 4 || i == 5)
        return true;
    else
        return false;
}
bool move_up(int i)
{
    if (i == 1 || i == 2 || i == 4 || i == 7)
        return true;
    else
        return false;
}
bool move_down(int i)
{
    if (i == 1 || i == 2 || i == 5 || i == 6)
        return true;
    else
        return false;
}

int solve(vector<vector<int>> &grid, int endo_len, int start_x, int start_y)
{
    // base case
    //the endoscope start position doesnot contain any pipes
    if (grid[start_x][start_y] == 0)
        return 1;
    //for endo_len=1 return 1
    if(endo_len==1) return 1;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    // BFS
    //(Position(x,y),step_size)
    queue<pair<pair<int, int>, int>> pq;
    pq.push({{start_x, start_y}, 1});
    visited[start_x][start_y]=true;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int explored_pipes = 0;
    while (!pq.empty())
    {
        auto it = pq.front();
        pq.pop();
        // x position
        int x = it.first.first;
        // y position
        int y = it.first.second;
        // current step size
        int current_step = it.second;
        // exceeds the endoscope length
        if (current_step > endo_len)
            continue;
        explored_pipes++;
        cout<<"x pos : "<<x<<" y pos "<<y<<endl;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (valid(nx, ny, n, m) && visited[nx][ny] == false)
            {
                // nx,ny can be explored
                if (dir == 0)
                {
                    // means left
                    // move-->left and <---right
                    if (move_left(grid[x][y]) && move_right(grid[nx][ny]))
                    {
                        visited[nx][ny] = true;
                        pq.push({{nx, ny}, current_step + 1});
                    }
                }
                else if (dir == 1)
                {
                    // means right
                    if (move_right(grid[x][y]) && move_left(grid[nx][ny]))
                    {
                        visited[nx][ny] = true;
                        pq.push({{nx, ny}, current_step + 1});
                    }
                }
                else if (dir == 2)
                {
                    // means up
                    if (move_up(grid[x][y]) && move_down(grid[nx][ny]))
                    {
                        visited[nx][ny] = true;
                        pq.push({{nx, ny}, current_step + 1});
                    }
                }
                else
                {
                    // means down
                    if (move_down(grid[x][y]) && move_up(grid[nx][ny]))
                    {
                        visited[nx][ny] = true;
                        pq.push({{nx, ny}, current_step + 1});
                    }
                }
            }
        }
    }
    return explored_pipes;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        int start_x, start_y,endo_len;
        cin >> start_x >>start_y>> endo_len;
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> grid[i][j];


            }
        }
            cout<<solve(grid,endo_len,start_x,start_y)<<endl;

    }
}