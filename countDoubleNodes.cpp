#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *right, *left;
};

int countDNodes(node* root){
    if(!root)
        return 0;
    else if(root->left && root->right)
        return 1+countDNodes(root->left)+countDNodes(root->right);
    else if(!root->left && !root->right)
        return 0;
    else return countDNodes(root->left) + countDNodes(root->right);
}

int main(){
    return 0;
}
