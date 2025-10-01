#include <bits/stdc++.h>
using namespace std;

class Applicant{
    public:
        int id;
        vector<int> grades;
        Applicant(int id, vector<int> grades):id(id), grades(grades){}
};

vector<int> orders;
bool cmp(const Applicant& s1, const Applicant& s2){
    for(const auto& order: orders){
        if(s1.grades[(order-1)]!=s2.grades[(order-1)])
            return s1.grades[(order-1)]>s2.grades[(order-1)];
    }
    return s1.id<s2.id;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    vector<Applicant> Applicants;
    for(int i=1;i<=N;++i){
        // N applicants
        vector<int> grades;
        for(int j=1;j<=M;++j){
            // M subjects
            int grade;
            cin>>grade;
            grades.push_back(grade);
        }
        Applicant student(i,grades);
        //grades.clear();
        Applicants.push_back(student);
    }
    // Subject priority input
    for(int i=0;i<M;++i){
        int order;
        cin>>order;
        orders.push_back(order);
    }
    sort(Applicants.begin(),Applicants.end(),cmp);
    // Print the id
    for(const auto& Applicant: Applicants){
        cout<<Applicant.id<<" ";
    }
    cout<<"\n";
    return 0;

}