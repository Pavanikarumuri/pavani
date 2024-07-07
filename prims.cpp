#PRIMS
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> prims(int n,vector<vector<pair<int,int>>> adj)
{
    vector<int> visited(n,0);
            
   priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    vector<pair<int,int>> edges;
    pq.push({{0,0},-1});
    int ans=0;
    while(!pq.empty())
    {
        auto x=pq.top();
        pq.pop();
        int weight=x.first.first;
        int cur=x.first.second;
        int parent=x.second;
        if(!visited[cur])
        {
            visited[cur]=1;
            ans += weight;
            if(parent!= -1)
            {
                edges.push_back({parent,cur});
            }
            for(auto k:adj[cur])
            {
                int neighbour=k.first;
                int dist=k.second;
                if(!visited[neighbour])
                {
                    pq.push({{dist,neighbour},cur});
                }
            }
           
        }
    }
    return edges;
}
int main() {
   int n,e,i;
   cin>>n>>e;
   vector<vector<pair<int,int>>> adj(n);
   for(i=1;i<=e;i++)
   {
       int a,b,c;
       cin>>a>>b>>c;    
       adj[a].push_back(make_pair(b,c));
       adj[b].push_back(make_pair(a,c));
   }
   vector<pair<int,int>> edges=prims(n,adj);
   for(auto k:edges)
   {
       cout<<k.first<<" "<<k.second<<endl;
   }
   return 0;
}
