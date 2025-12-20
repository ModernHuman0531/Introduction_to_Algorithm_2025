#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
class Edge{
    public:
        int vi, wi;
        Edge(int _vi,int _wi):vi{_vi}, wi{_wi}{}
};

vector<list<Edge>> adj;
void addEdge(int vi,int ui,int wi){
    adj[vi].push_back(Edge(ui,wi));
    adj[ui].push_back(Edge(vi,wi));
}

void Dijkstra(){
    // Let distance other than start point be 0
    const long long inf=LLONG_MAX/4;
    vector<long long> d(n+1,inf);

    d[s]=0;
    // Create priority queue for store the distance of reachable neighbors
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    // Push the first already known point and distance into pq
    pq.push({0,s});
    while(!pq.empty()){
        // pop the smallest distance out
        auto [dis, vertex]=pq.top();
        pq.pop();

        if(vertex==t){
            cout<<d[t]<<"\n";
            return;
        }

        for(auto [v,w]:adj[vertex]){
            if(d[v]>d[vertex]+w){
                d[v]=d[vertex]+w;
                pq.push({d[v], v});
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin>>n>>m>>s>>t;
    adj.resize(n+1);
    for(int i=1;i<=m;++i){
        int ui,vi,wi;
        cin>>ui>>vi>>wi;
        addEdge(ui,vi,wi);
    }
    Dijkstra();
    return 0;
}