#include<iostream>
using namespace std;
int solve(string str,int k)
{
    int curr_level=-1;
    int n=str.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(') curr_level++;
        else if(str[i]==')') curr_level--;
        else if(str[i]>='0' && str[i]<='9')
        {
            if(curr_level==k)
            {
                int num=0;
                while(i<n && str[i]!='(' && str[i]!=')')
                {
                    num=(num*10)+(str[i]-'0');
                    i++;

                }
                ans=ans+num;
                i--;
            }

        }
    }
    return ans;
}
int main()
{
    int k;
    string str;
    cin >> k;
    cin>>str;
    cout<<solve(str,k)<<endl;

}