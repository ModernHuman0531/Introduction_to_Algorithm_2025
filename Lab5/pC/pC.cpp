#include<bits/stdc++.h>
using namespace std;
#define lc 2*id
#define rc 2*id+1
int Q;
long long M;
vector<long long> seg;
void build(int L,int R, int id){
    if(L==R){
        seg[id]=1;
        return;
    }
    int mid=(L+R)/2;
    build(L,mid,lc);
    build(mid+1,R,rc);
    seg[id]=(seg[lc]%M*seg[rc]%M)%M;
}

long long query(int l,int r,int L,int R,int id){
    if(l<=L&&R<=r){
        return seg[id];
    }
    int mid=(L+R)/2;
    if(r<=mid){
        return query(l,r,L,mid,lc);
    }
    else if(l>mid){
        return query(l,r,mid+1,R,rc);
    }
    else{
        return (query(l,r,L,mid,lc)%M*query(l,r,mid+1,R,rc)%M)%M;
    }
}

void modify(int x, int v,int L,int R,int id){
    if(L==R){
        seg[id]=v;
        return;
    }
    int mid=(L+R)/2;
    if(x<=mid){
        modify(x,v,L,mid,lc);
    }
    else{
        modify(x,v,mid+1,R,rc);
    }
    seg[id]=(seg[lc]%M*seg[rc]%M)%M;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>Q>>M;
    seg.resize(4*Q+1,1);
    build(1,Q,1);
    for(int i=1;i<=Q;++i){
        int op, x;
        cin>>op>>x;
        if(op==1){
            modify(i,x%M,1,Q,1);
        }
        else if(op==2){
            modify(x,1,1,Q,1);
        }
        long long ans = seg[1];
        cout<<ans<<"\n";
    }
    return 0;
}