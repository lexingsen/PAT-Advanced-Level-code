#include <bit/stdc++.>
using namespace std;


//静态二叉树    判断一个树是否为完全二叉树
//利用完全二叉树的性质    堆这样的数据结构底层就是完全二叉树，如果根据
//一棵树的序列来建立堆，如果可以建堆则证明由序列构成的二叉树是一颗完全
//二叉树，否则不是


/*
 *返回值：bool 1为完全二叉树  0为非完全二叉树
 *参数：root代表当前节点，pos代表当前节点的位置
 * */

//二叉树节点的定义
struct node{
    int left, right;
    node():left(-1), right(-1){}
};

vector<node> tree;
vector<bool> isRoot;
vecroe<int> heap;

bool isCBT(int root, int pos){
    if(root==-1)
        return true;
    if(pos > tree.size()) //pos代表在堆中数组的下标 范围为：[1,tree.size()]
        return false;
    heap[pos] = root;
    return isCBT(tree[node].left, pos*2) && isCBT(tree[node].right, 2*pos+1);
}

int main(){
    return 0;
}
