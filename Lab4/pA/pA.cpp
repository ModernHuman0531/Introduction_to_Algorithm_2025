#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
const int MAXW=100;
const long long INF=MAXN*1000000000ll;

long long dp[MAXN][MAXW];
int ai[MAXN],bi[MAXN],ci[MAXN];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;++i){
        cin>>ai[i]>>bi[i]>>ci[i];
    }

    // Initialization, dp[0][0] means put nothing in it, the current used space is 0
    dp[0][0]=0;
    // 0 item can't have i size
    for(int i=1;i<=w;++i){
        dp[0][i]=-INF;
    }

    for(int i=1;i<=n;++i){
        // If current space can't put item i, then don't put it, the state stay the same
        for(int j=0;j<ai[i];++j){
            dp[i][j]=dp[i-1][j];
        }
        // If current space can put item i, we choose the maximum value of put or not put
        for(int j=ai[i];j<=w;++j){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-ai[i]]+bi[i]);
        }
    }

    // Choose the maximum value consider the first n element
    cout<<*max_element(dp[n],dp[n]+w+1)<<"\n";
    return 0;
}