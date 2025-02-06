#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 int gate_combination[][3]={
        {0,1,2},
        {0,2,1},
        {1,0,2},
        {1,2,0},
        {2,0,1},
        {2,1,0}  
    };
int position_of_gates[3];
int men_in_gates[3];
int check_left(int start_pos,vector<bool>&visited)
{
    int dist=0;
    for(int i=start_pos;i>=0;i--)
    {
        dist++;
        if(visited[i]==false) return dist;

    }
    return INT_MAX;

}
int check_right(int start_pos,vector<bool>&visited)
{
    int dist=0;
    int n=visited.size();
    for(int i=start_pos;i<n;i++)
    {
        dist++;
        if(visited[i]==false) return dist;

    }
    return  INT_MAX;
}
int find_distance(int comb_numb,int gate_no,vector<bool>&visited)
{
    int gate_index=gate_combination[comb_numb][gate_no];
    // cout<<"combination no : "<<comb_numb<<" gate no "<<gate_no<<endl;
    //1 based index
    int gate_position=position_of_gates[gate_index]-1;
    int num_of_men=men_in_gates[gate_index];
    int dis=0;
    for(int i=0;i<num_of_men;i++)
    {
        //if exactly that position is available
        if(visited[gate_position]==false)
        {
        //vertical distance
        dis++;
        visited[gate_position]=true;

        }
        else
        {
            //check on the left
            int left_available=check_left(gate_position-1,visited);
            // cout<<" left "<<left_available<<endl;
            //check on the right
            int right_available=check_right(gate_position+1,visited);
            // cout<<" right "<<right_available<<endl;
            if(left_available<right_available)
            {
                dis=dis+1+left_available;
                visited[gate_position-left_available]=true;

            }
            else
            {
                dis=dis+1+right_available;
                visited[gate_position+right_available]=true;

            }
        }
    }
    return dis;


}
int solve(int index,int n)
{

    //trying combination number index
    int total_dist=0;
    //for this particular combination of index
    //we will examine the gates accordingly
    //each call of find_distance works wiht one gate
    vector<bool>visited(n,false);

    for(int i=0;i<3;i++)
    {
        total_dist+=find_distance(index,i,visited);

    }
    return total_dist;



}

int main()
{
    int n;
    cin >> n;
    
    for(int i=0;i<3;i++)
    cin >> position_of_gates[i];
    for(int i=0;i<3;i++)
    cin >> men_in_gates[i];
    int ans=INT_MAX;
   
    for(int i=0;i<6;i++)
    {
        //try with each gate combination to find the best
        int t=solve(i,n);
        ans=std::min(ans,t);
        //print each
        // cout << t <<" ";
    }
    cout << ans << endl;
    return 0;



}