#include<bits/stdc++.h>
using namespace std;
class Point
{
    public:
    int x;
    int y;

};
class wormhole
{
    public:
    Point start;
    Point end;
    int cost;

};
class Node
{
    public:
    int id;
    int cost;
    Node()
    {

    }
    Node(int id,int cost)
    {
        this->id=id;
        this->cost=cost;
    }

};
int find_distance(Point &a,Point &b)
{
    return std::abs(a.x-b.x)+std::abs(a.y-b.y);
}
vector<vector<pair<int,int>>> build_adj_list(vector<wormhole>&wm_list,Point &src,Point &dest)
{
    int num_of_nodes=2*wm_list.size()+2;
    vector<Point> all_nodes(num_of_nodes);
    all_nodes[0]=src;
    all_nodes[1]=dest;
    for(int i=0;i<wm_list.size();i++)
    {
        all_nodes[2+2*i]=wm_list[i].start;
        all_nodes[2+2*i+1]=wm_list[i].end;    
    }
    vector<vector<pair<int,int>>>adj_list(num_of_nodes);
    for(int i=0;i<num_of_nodes;i++)
    {
        for(int j=i+1;j<num_of_nodes;j++)
        {
            int cost=find_distance(all_nodes[i],all_nodes[j]);
            adj_list[i].push_back({j,cost});
            adj_list[j].push_back({i,cost});
        }
    }
    for(int i=0;i<wm_list.size();i++)
    {
        int u=2+2*i;
        int v=2+2*i+1;
        int cost=wm_list[i].cost;
        adj_list[u].push_back({v,cost});
        adj_list[v].push_back({u,cost});
    }
    return adj_list;


}
struct compare_pq
{
    bool operator()(const Node &p,const Node &q)
    {
        return p.cost>q.cost;

    }

};
int dijkstra(vector<vector<pair<int,int>>>&adj_list,int src,int dest)
{
    int num_of_nodes=adj_list.size();
    vector<int>distance(num_of_nodes,INT_MAX);
    //Max-heap
    priority_queue<Node,vector<Node>,compare_pq>pq;
    Node node(0,0);
    pq.push(node);
    while(!pq.empty())
    {
        //pq has Node entities
        Node current=pq.top();
        pq.pop();

        if(current.id==dest)
        break;
        for(const auto& neighbors:adj_list[current.id])
        {
            //(id,cost)
            int new_distance=distance[current.id]+neighbors.second;
            if(new_distance<distance[neighbors.first])
            {
                //update the new distance
                Node temp_node(neighbors.first,new_distance);
                pq.push(temp_node);
                distance[neighbors.first]=new_distance;
            }

        }
    }
    return distance[dest];



    


}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        //n=Number of wormholes
        int n;
        cin>>n;
        Point src,dest;
        cin>>src.x>>src.y;
        cin>>dest.x>>dest.y;
        vector<wormhole>wormhole_list;
        for(int i=0;i<n;i++)
        {
            wormhole w;
            cin>>w.start.x>>w.start.y;
            cin>>w.end.x>>w.end.y;
            cin>>w.cost;
            wormhole_list.push_back(w);
        }
        //build the adj list
        vector<vector<pair<int,int>>>adj_list;
        adj_list=build_adj_list(wormhole_list,src,dest);
        int ans=dijkstra(adj_list,0,1);
        cout<<ans<<" "<<endl;
    }

}