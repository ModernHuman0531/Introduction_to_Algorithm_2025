#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> score;
long long countkthnum(int mid){
    // Count one dish
    long long count=0;
    int n=score.size();
    for(int i=0;i<n;++i){// mid>= at least have k, for kth number
        if(score[i]*2>=mid)
            count+=1;
    }
    // Use double pointer to enumerate combo dishes
    int l=0,r=n-1;
    int r_start=r;
    for(;l<n;++l){
        int sum=(score[l]+score[r]);
        while(sum>=mid&&r>l){
            sum-=score[r];
            r-=1;
            sum+=score[r];
        }
        count+=(r_start-max(l,r));
    }

    //cout<<"mid="<<mid<<",count="<<count<<"\n";
    return count;
}
int binary_search(long long k){
    // Return wi that is the kth large score
    int n=score.size();
    int l=score[0]*2,r=score[n-1]*2+2;
    while(r>l+1){
        int mid=(l+r)/2;
        long long count=countkthnum(mid);
        if(count>=k){
            l=mid;
        }
        else
            r=mid;
        //cout<<"l="<<l<<",r="<<r<<"\n";
    }
    return l;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    long long k;
    cin>>n>>k;
    int p,q;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        score.push_back(num);
    }
    sort(score.begin(),score.end());
    int temp=binary_search(k);
    if(temp%2==0)
        cout<<temp/2<<"\n"<<"1"<<"\n";
    else
        cout<<temp<<"\n"<<"2"<<"\n";
    return 0;
}
   
