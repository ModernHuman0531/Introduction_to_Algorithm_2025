#include<bits/stdc++.h>
using namespace std;
int N,M;
class Edge{
    public:
        int ai;
        list<int> li;
        bool visited;
        Edge(){
            visited=false;
        }

};

vector<Edge> adj;
void addEdge(int v,int u){
    adj[v].li.push_back(u);
}
vector<int> topoOrder;
const int MAXN=200005;
long long dp[MAXN];
void DFS(int v){
    adj[v].visited=true;
    for(int u:adj[v].li){
        if(!adj[u].visited)
            DFS(u);
    }
    topoOrder.push_back(v);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>N>>M;
    adj.resize(N+1);
    for(int i=1;i<=N;++i){
        int a_i;
        cin>>a_i;
        adj[i].ai=a_i;
    }
    for(int i=0;i<M;++i){
        int v,u;
        cin>>v>>u;
        addEdge(v,u);
    }
    // first find reverse topological order
    for(int v=1;v<=N;++v){
        if(!adj[v].visited)
            DFS(v);
    }
    // Apply subtask3 dp formula
    long long ans=0;
    for(int v:topoOrder){
        dp[v]=adj[v].ai;
        for(int u:adj[v].li){
            // Only one elment in this list, because the whole graph 
            // are all linked-list
            dp[v]=dp[v]+dp[u];
        }
        ans=max(ans,dp[v]);
    }
    cout<<ans<<"\n";
    return 0;
}