#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int solve(vector<int>&nums)
{
    //resize the vector to handle edge cases
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int window=2;window<n;window++)
    {
        //so work for this window
        for(int l=0;l<n-window;l++)
        {
            int r=l+window;
            for(int pos=l+1;pos<r;pos++)
            {
                int points=0;
                //so In this [left..right] window,for each pos where left<pos<right
                //we will consider we will burst the position ballon last
                if(l==0 && r==n-1)
                {
                    //special case
                    points=nums[l]*nums[r]*nums[pos];
                }
                else{
                    //normal case
                    points=nums[l]*nums[r];

                }
                points+=dp[l][pos]+dp[pos][r];
                dp[l][r]=std::max(dp[l][r],points);
            }

        }

    }
    //
    return dp[0][n-1];

}
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    cout<<solve(nums)<<endl;

}