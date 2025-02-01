#include<iostream>
using namespace std;
int to_number(string str)
{
    int num=0;
    for(char ch:str)
    {
        num=num*10+(ch-'0');
    }
    return num;
}
int main()
{
    int k;
    string str;
    cin>>k;
    cin>>str;
    int current_level=-1;
    int sum=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        current_level++;
        else if(str[i]==')')
        current_level--;
        else if(current_level==k)
        {
            string tmp;
            while(i<str.size() && str[i]!='(' && str[i]!=')')
            {
                tmp+=str[i];
                i++;
            }
            i--;
            int t=to_number(tmp);
            sum+=t;

        }
    }
    cout<<sum<<endl;
}