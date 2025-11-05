#include<bits/stdc++.h>
using namespace std;
int N,M;
class Edge{
    public:
        int ai;
        list<int> li;
        Edge(){
        }
};

const int MAXN=200005;
// Graph
vector<Edge> Graph;
vector<Edge> reverse_graph;
vector<bool> visited;

// SCC
vector<int> scc_id; //Specify vertex in which scc
stack<int> scc_order;
int scc_count=0;

// DAG made by SCC
vector<vector<int>> DAG;
vector<long long> scc_value;
vector<int> in_degree; //Specify SCC's in degree, since dp start from the SCC have 0 in_degree

void addEdge(int v,int u){
    Graph[v].li.push_back(u);
    reverse_graph[u].li.push_back(v);
}

// Build SCC
void dfs1(int v){
    visited[v]=true;
    for(int u:Graph[v].li){
        if(visited[u]==false){
            visited[u]=true;
            dfs1(u);
        }
    }
    scc_order.push(v);

}
void dfs2(int v,int scc_num){
    scc_id[v]=scc_num;
    scc_value[scc_num]+=Graph[v].ai;

    for(int u:reverse_graph[v].li){
        if(scc_id[u]==-1){ //When the vertex haven't been visited, the scc_id[u]=-1
            dfs2(u,scc_num);
        }
    }
}

void build_scc(){
    // Do the first DFS to find order
    for(int i=1;i<=N;++i){
        if(visited[i]==false)
            dfs1(i);
    }

    // Do the second DFS to find SCC's
    while(!scc_order.empty()){
        int v=scc_order.top();
        scc_order.pop();

        if(scc_id[v]==-1){
            dfs2(v,scc_count);
            scc_count++;
        }
    }
}

// Build DAG composed by SCC's
void build_DAG(){
    set<pair<int,int>> edges;
    for(int v=1;v<=N;++v){
        for(int u:Graph[v].li){
            int scc_v=scc_id[v];
            int scc_u=scc_id[u];

            if(scc_v!=scc_u&&edges.find({scc_v,scc_u})==edges.end()){
                DAG[scc_v].push_back(scc_u);
                in_degree[scc_u]++;
                edges.insert({scc_v,scc_u});
            }
            
        }
    }


}
long long dp[MAXN];
void topoDp(){
    // All the in-order=0's vertex can be start point ,kahn alogorithm
    queue<int> topoOrder;
    for(int i=0;i<scc_count;++i){
        if(in_degree[i]==0){
            topoOrder.push(i);
            // In-order=0's vertex at least can get iteslf's award
            dp[i]=scc_value[i];
        }
    }
    while(!topoOrder.empty()){
        int v=topoOrder.front();
        topoOrder.pop();
        for(int u:DAG[v]){
            dp[u]=max(dp[u],dp[v]+scc_value[u]);
            in_degree[u]--;
            if(in_degree[u]==0){
                topoOrder.push(u);
            }

        }
    }
    // Find all SCC's maximum value
    long long ans=0;
    for(int i=0;i<scc_count;++i){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>N>>M;
    Graph.resize(N+1);
    reverse_graph.resize(N+1);
    for(int i=1;i<=N;++i){
        int ai;
        cin>>ai;
        Graph[i].ai=ai;
    }
    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }


    visited.resize(N+1,false);
    scc_id.resize(N+1,-1);

    scc_value.resize(N+1,0);
    build_scc();
    DAG.resize(scc_count);
    
    in_degree.resize(scc_count,0);

    
    build_DAG();
    topoDp();

    return 0;
}