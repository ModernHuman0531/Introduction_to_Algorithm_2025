#include <bits/stdc++.h>
using namespace std;
long long a,b,p;
long long my_exp(long long a,long long b,long long p){
    if(b==0) return 1;
    if(b==1) return a%p;
    long long exp_n=(b%2?my_exp(a,b-1,p)*my_exp(a,1,p):my_exp(a,b/2,p)*my_exp(a,b/2,p))%p;
    return exp_n;
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>a>>b>>p;
    long long ans=my_exp(a,b,p);
    cout<<ans<<"\n";
    return 0;
}