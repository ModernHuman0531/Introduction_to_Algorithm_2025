#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> vec;
vector<long long> prefix_sum;
void prefix_cal(int n);
void Update(int p,int x);
void Query(int l,int r);
void operation(int i,int j,int k){
    // i is operation,j and k are the input of Update/Query
    if(i==1) return Update(j,k);
    if(i==2) return Query(j,k);

}
void Update(int p,int x){
    vec[p]=x;
    prefix_cal(n);
    return;
}
void Query(int l,int r){
    long long ans=prefix_sum[r]^prefix_sum[l-1];
    cout<<ans<<"\n";
}
void prefix_cal(int n){
    prefix_sum.clear();
    prefix_sum.push_back(0); // prefix_sum[0] = 0
    long long sum=0;
    for(int i=1;i<=n;++i){
        sum=sum^vec[i];
        prefix_sum.push_back(sum);
    }
}
int main(){
    int q;
    cin>>n;
    vec.push_back(0);// Let the position start from 1
    // Input handle
    for(int i=0;i<n;++i){
        long long input;
        cin>>input;
        vec.push_back(input);
    }
    // 初始計算 prefix sum
    prefix_cal(n);
    
    cin>>q;
    for(int i=0;i<q;++i){
        int op,j,k;
        cin>>op>>j>>k;
        operation(op,j,k);
    }
    return 0;
}