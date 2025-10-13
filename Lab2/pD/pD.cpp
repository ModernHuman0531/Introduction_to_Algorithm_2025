#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
void Update(int p,int x);
void Query(int l,int r);
void operation(int i,int j,int k){
    // i is operation,j and k are the input of Update/Query
    if(i==1) return Update(j,k);
    if(i==2) return Query(j,k);

}
void Update(int p,int x){
    vec[p]=x;
    return;
}
void Query(int l,int r){
    long long sum=vec[l];
    for(int i=l+1;i<=r;++i){
        sum=sum^vec[i];
    }
    cout<<sum<<"\n";
}
int main(){
    int n,q;
    cin>>n;
    vec.push_back(0);// Let the position start from 1
    // Input handle
    for(int i=0;i<n;++i){
        long long input;
        cin>>input;
        vec.push_back(input);
    }
    cin>>q;
    for(int i=0;i<q;++i){
        int op,j,k;
        cin>>op>>j>>k;
        operation(op,j,k);
    }
    return 0;
}