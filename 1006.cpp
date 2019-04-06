#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct people{
    string id, sign_in, sign_out;
    people(string id, string sign_in, string sign_out){
        this->id = id;
        this->sign_in = sign_in;
        this->sign_out = sign_out;
    }
};

vector<people> v;

bool cmpin(people a, people b) {return a.sign_in < b.sign_in;}
bool cmpout(people a, people b){return a.sign_out > b.sign_out;}
void print(people a){
    cout<<a.id<<" "<<a.sign_in<<" "<<a.sign_out<<endl;
} 

int main(){
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string id,sign_in,sign_out;
    for(int i=0; i<n; ++i){
        cin>>id>>sign_in>>sign_out;
        v.push_back(people(id, sign_in, sign_out));
    }
    for_each(v.begin(), v.end(), print);
    sort(v.begin(), v.end(), cmpin);
    cout<<v[0].id<<" ";
    sort(v.begin(), v.end(), cmpout);
    cout<<v[0].id<<endl;
    return 0;
}
