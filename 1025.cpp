#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 110;

struct people{
    string name;
    int score;
};

struct stu{
    string name;
    int group;
    int score;
    int groupRank;

    stu(string name, int group, int score, int groupRank){
        this->name = name;
        this->group = group;
        this->score = score;
        this->groupRank = groupRank;
    }
};

vector<people> arr[maxn];
vector<stu> v;

bool cmp(people a, people b){
    if(a.score != b.score)return a.score > b.score;
    else return a.name < b.name;
}

bool cmp1(stu a, stu b){
    if(a.score != b.score)return a.score > b.score;
    else return a.name < b.name;
}


int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &m);
        people p;
        string name;
        int score;
        for(int j=0; j<m; ++j){
            cin>>name;
            scanf("%d", &score);
            p.name = name;
            p.score = score;
            arr[i].push_back(p);
        }
        sort(arr[i].begin(), arr[i].end(), cmp);
        int rank = 0, pre=-1;
        for(int k=0; k<arr[i].size(); ++k){
            if(arr[i][k].score != pre)rank = k+1;
            pre = arr[i][k].score;
            v.push_back(stu(arr[i][k].name, i+1, arr[i][k].score, rank));
        }
    }
    int cnt = 0;
    for(int i=0; i<n; ++i){
        cnt += arr[i].size();
    }
    printf("%d\n", cnt);
    sort(v.begin(), v.end(), cmp1);
    int rank=0,pre=-1;
    for(int i=0; i<v.size(); ++i){
        if(v[i].score!=pre)rank = i+1;
        pre = v[i].score;
        printf("%s %d %d %d\n", v[i].name.c_str(), rank, v[i].group, v[i].groupRank);
    }
    return 0;
}
