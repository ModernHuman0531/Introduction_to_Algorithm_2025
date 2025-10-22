#include <bits/stdc++.h>
using namespace std;
long long poly(long long N,long long X){
    long long ans=0;
    for(int i=N;i>=1;--i){
        long long x_i=i;
        for(int j=N;j>i;--j){
            x_i*=X;
        }
        ans+=x_i;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;++i){
        long long N,X,M;
        cin>>N>>X>>M;
        long long ans=poly(N,X)%M;
        cout<<ans<<"\n";
    }
    return 0;
}
