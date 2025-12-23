#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int N;
    cin>>N;
    // Define container
    vector<long long> odd_A,odd_B,even_A, even_B;

    
    for(int i=1;i<=N;++i){
        long long xi,yi;
        cin>>xi>>yi;
        // Divide the input by (ui-vi)%2 is odd or even, only same mod can calculate distance
        if((xi+yi)%2){
            odd_A.push_back(xi+yi);
            odd_B.push_back(xi-yi);
        }
        else{
            even_A.push_back(xi+yi);
            even_B.push_back(xi-yi);
        }
    }
    sort(odd_A.begin(), odd_A.end());
    sort(odd_B.begin(), odd_B.end());
    sort(even_A.begin(),even_A.end());
    sort(even_B.begin(),even_B.end());


    // Calculate the final answer
    long long ans=0;
    long long current_sum=0;
    for(int i=0;i<odd_A.size();++i){
        ans+=(long long)i*odd_A[i]-current_sum;
        current_sum+=odd_A[i];
    }
    current_sum=0;
    for(int i=0;i<odd_B.size();++i){
        ans+=(long long)i*odd_B[i]-current_sum;
        current_sum+=odd_B[i];
    }
    current_sum=0;
    for(int i=0;i<even_A.size();++i){
        ans+=(long long)i*even_A[i]-current_sum;
        current_sum+=even_A[i];
    }
    current_sum=0;
    for(int i=0;i<even_B.size();++i){
        ans+=(long long)i*even_B[i]-current_sum;
        current_sum+=even_B[i];
    }
    ans/=2;
    cout<<ans<<"\n";
    return 0;

}