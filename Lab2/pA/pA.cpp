#include <bits/stdc++.h>
using namespace std;
// #define int long long
int a,b,c;
long long F1,F2;
vector<long long> fib_nums;
long long fib(int n){
    if(n==1) return F1;
    if(n==2) return F2;
    if(n<=fib_nums.size()) return fib_nums[n-1];
    long long fn=a*fib(n-1)+b*fib(n-2)+c;
    fib_nums.push_back(fn);
    return fn;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin>>n>>a>>b>>c>>F1>>F2;
    fib_nums.push_back(F1);
    fib_nums.push_back(F2);
    long long fib_n=fib(n);
    cout<<fib_n<<"\n";
    return 0;

}