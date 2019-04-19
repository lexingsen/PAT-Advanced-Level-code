#include <bits/stdc++.h。
using namespace std;


struct node{
    int val;
    node *left, *right;
};


//求解二叉树某层节点的个数
//depth的范围[0,height-1] 其中height为树高
int count(node* root, int depth, int &cnt){
    if(!root || depth<0)
        return;
    if(depth==0){
        cnt ++;
        return 1;
    }
    else
        return count(root->left, depth-1, cnt) + count(root->right, depth-1, cnt);
}

int main(){
    return 0;
}
