#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
struct Complex{

        long long r,i;
        Complex(long long _r,long long _i):r{_r}, i{_i}{}
};

Complex multiply(Complex a, Complex b){
    long long real=(a.r*b.r%M-a.i*b.i%M+M)%M;
    long long img=(a.r*b.i%M+a.i*b.r%M)%M;
    return {real, img};
}

void solve(){
    long long a,b,k;
    cin>>a>>b>>k;
    Complex res={1,0};
    Complex base={a,b};
    while(k>0){
        if(k%2==1){
            res=multiply(res, base);
            k--;
        }
        else{
            base=multiply(base,base);
            k/=2;
        }
    }
    cout<<res.r<<" "<<res.i<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
