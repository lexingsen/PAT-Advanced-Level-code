#include <bits/stdc++.h>
using namespace std;

struct node{
    int v;
    node *right, *left;
};


int widthOfBiTree(node* root){
    if(!root)
        return 0;
    int maxsize = 0;
    queue<node*> q;
    q.push(root);
    while(1){
        int len = q.size();
        if(len==0)break;
        while(len > 0){
            node* tmp = q.front();q.pop();
            len --;
            if(tmp->left)q.push(q->left);
            if(tmp->right)q.push(q->right);
        }
        maxsize = maxsize > q.size() ? maxsize : q.size();
    }
    return maxsize;
}



int main(){
    return 0;
}
