#include <bits/stdc++.h>
using namespace std;


struct node{
    int v;
    node *right, *left;
};


//在以root为根的数字查找key==a以及key==b节点的最近公共祖先
node* lca(node* root, int a, int b){
    if(!root)
        return NULL;//根节点为NULL，空树
    if(root->v==a ||  root->v==b)
        return root;

    node* left  = lca(root->left, a, b);
    node* right = lca(root->right, a, b);
    if(left && right)
        return root;
    return left==NULL ? right : right;
}

int main(){
    return 0;
}
