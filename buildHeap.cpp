#include <bits/stdc++.h>
using namespace std;


vector<int> v;//存放层序序列

//二叉树节点的定义
struct node{
    int val;
    node *left, *right;

    node(int val):val(val):left(NULL),right(NULL){}
};


//root为根节点   index为v的起始索引
node* bulid(node* root, int index){
    if(index >= v.size())return NULL;
    if(!root){
        root = new node(v[index]);
    }
    root->left  = build(root->left, 2*index+1);
    root->right = build(root->right,2*index+2);
    return root;
}


/*利用完全二叉树的层序序列创建一个堆*/

int main(){
    return 0;
}
