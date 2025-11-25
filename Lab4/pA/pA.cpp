#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
const int MAXW=100;
const long long INF=MAXN*1000000000ll;

long long dp[MAXW];
int ai[MAXN],bi[MAXN],ci[MAXN];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;++i){
        cin>>ai[i]>>bi[i]>>ci[i];
    }
    // Initialization, dp[0][0] means put nothing in it, the current used space is 0
    dp[0]=0;
    // 0 item can't have i size
    for(int i=1;i<=w;++i){
        dp[i]=-INF;
    }
    int now=1;
    for(int i=1;i<=n;++i){
        for(int j=w;j>=ai[i];--j){
            dp[j]=max(dp[j],dp[j-ai[i]]+bi[i]);
        }
    }
    // Choose the maximum value consider the first n element
    cout<<*max_element(dp,dp+w+1)<<"\n";
    return 0;
}