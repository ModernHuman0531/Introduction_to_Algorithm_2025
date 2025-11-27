#include<bits/stdc++.h>
using namespace std;

class group{
    public:
        long long li,ri,wi;
        group(long long _li,long long _ri,long long _wi):li{_li},ri{_ri},wi{_wi}{}
};

bool cmp(const group &a,const group &b){
    return a.ri<b.ri;
}
const int MAXN=500001;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin>>n;

    // vector to sort with finish time
    vector<group> vec;

    for(int i=1;i<=n;++i){
        long long li,ri,wi;
        cin>>li>>ri>>wi;
        vec.push_back(group(li,ri,wi));
    }
    // Sort the vector with ascending order of finish time
    sort(vec.begin(),vec.end(),cmp);
    
    long long ans=0;
    // Greedily choose the group with earliest finish time that does not conflict with previous chosen group
    
    long long last_ri=-1;
    for(int i=0;i<n;++i){
        if(vec[i].li>last_ri){
            ans+=vec[i].wi;
            last_ri=vec[i].ri;
        }
    }
    cout<<ans<<"\n";
    return 0;
}