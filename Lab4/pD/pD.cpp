#include<bits/stdc++.h>
using namespace std;

const int MAXN=200001;

// Build adjacent list for tree's child implementation
vector<list<int>> adj;
int w[MAXN]={0};
int p[MAXN];
long long size_a[MAXN]={0LL};
long long sum_a[MAXN]={0LL};

void dfs1(int v){
    sum_a[v]+=w[v];
    size_a[v]+=1;
    for(auto u:adj[v]){
        dfs1(u);
        sum_a[v]+=sum_a[u];
        size_a[v]+=size_a[u];
    }
    return;
}

bool cmp(const int a,const int b){
    return sum_a[a]*size_a[b] < sum_a[b]*size_a[a];
}

int w_now=1;
void dfs2(int v){
    p[v]=w_now;
    w_now++;
    for(auto u:adj[v]){
        dfs2(u);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin>>n;

    adj.resize(n+1);
    for(int i=1;i<=n;++i){
        int wi;
        cin>>wi;
        w[i]=wi;
    }
    // Build adjacent list
    for(int i=2;i<=n;++i){
        int fi;
        cin>>fi;
        adj[fi].push_back(i);
    }
    dfs1(1);
    // Loop through all the adjacent node to sort the order of child
    for(int i=1;i<=n;++i){
        adj[i].sort(cmp);
    }
    dfs2(1);

    // Calculate the max sum
    long long ans=0;
    for(int i=1;i<=n;++i){
        // int * int will overflow, so cast one to long long first to avoid overflow
        ans+=(long long)w[i]*p[i]; 
    }

    cout<<ans<<"\n";
    return 0;

}