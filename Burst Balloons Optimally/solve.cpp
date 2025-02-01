#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int dp(vector<int>&ballon, int i, int j, vector<vector<int>>&mem){
    
    if(mem[i][j]>0)return mem[i][j];
    if(i>j)return 0;

    for(int k = i ; k <= j ; k++){
            int x = dp(ballon, i, k-1, mem )+dp(ballon, k+1, j,mem) ;
            if(i==1 && j==(int)ballon.size()-2){
                x += ballon[k];
            }
            else{
                x += ballon[i-1]*ballon[j+1];
            }
            mem[i][j] = max(mem[i][j], x);
    }
    
    return mem[i][j];
    
}

int main() {
    int n;
    cin>>n;
    
    vector<int>ballon(n+2,1);
    for(int i = 1 ; i <= n ; i++){
        cin>>ballon[i];
    }
    
    vector<vector<int>>mem(n+2, vector<int>(n+2,0));
    
    cout<<dp(ballon,1,n,mem);
    
    
    return 0;
}

