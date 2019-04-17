#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
};


bool isCBT(node* root){
    if(!root)
        return true;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();q.pop();
        if(!tmp)break;
        q.push(tmp->left);
        q.push(tmp->right);
    }
    while(!q.empty()){
        node* tmp = q.front();q.pop();
        if(tmp)
            return false;
    }
    return true;
}


int main(){
    return 0;
}
