#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>ballons)
{
    ballons.insert(ballons.begin(),1);
    ballons.push_back(1);
    int n=ballons.size();
    //dp[i][j] means cost of bursting ballons from i..j.
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int window=2;window<n;window++)
    {
        //vary the window size 
        for(int left=0;left<n-window;left++)
        {
            int right=left+window;
            for(int i=left+1;i<right;i++)
            {
                //[left.....right] is fixed 
                int points=0;
                if(left==0 && right==n-1)
                {
                    points=ballons[left]*ballons[right]*ballons[i];

                }
                else
                {
                    points=ballons[left]*ballons[right];
                }
                points=points+dp[left][i]+dp[i][right];
                dp[left][right]=std::max(dp[left][right],points);
               

            }
        }
    }
    return dp[0][n-1];




}
int main()
{
    int n;
    cin >>n;
    vector<int>ballons(n);
    for(int i=0;i<n;i++)
    cin >> ballons[i];
    cout <<solve(ballons)<<endl;
}