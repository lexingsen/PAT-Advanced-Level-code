#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

struct node{
    char v;
    node *left, *right;
};

int post[maxn];
int in[maxn];
int pre[maxn];
int n;

node* build(int postL, int postR, int inL, int inR){
    if(postL > postR)
        return NULL;
    node* root = new node;
    root->v = post[postR];
    int k;
    for(k=inL; k<=inR; ++k){
        if(in[k]==post[postR])
            break;
    }
    int numLeft = k-inL;
    root->right = build(postL+numLeft, postR-1, k+1, inR);
    root->left  = build(postL, postL+numLeft-1, inL, k-1);
    return root;
}

int cnt = 0;
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();q.pop();
        printf("%d ", tmp->v);
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
    }
}

int idx = 0;
void preorder(node* root){
    if(root){
        pre[idx ++] = root->v;
        preorder(root->left);
        preorder(root->right);
    }
}

int preidx = 0, inidx = 0, postidx = 0;
void preK(node* root, int k){
    if(root){
        if(preidx++==k){
            printf("preorder %d-th val is %d\n", k, root->v);
            return;
        }
        preK(root->left, k);
        preK(root->right, k);
    }
}


void inK(node* root, int k){
    if(root){
        inK(root->left, k);
        if(inidx++==k){
            printf("inorder %d-th val is %d\n", k, root->v);
            return;
        }
        inK(root->right, k);
    }
}

void postK(node* root, int k){
    if(root){
        postK(root->left, k);
        postK(root->right, k);
        if(postidx++==k){
            printf("postorder %d-th val is %d\n", k, root->v);
            return;
        }
    }
}


int main(){
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)cin>>post[i];
    for(int i=0; i<n; ++i)cin>>in[i];
    node* root = build(0,n-1,0,n-1);
    preorder(root);
    for(int i=0; i<n; ++i)printf("%d ",pre[i]);
    cout<<endl;
    preK(root, n-1);
    for(int i=0; i<n; ++i)printf("%d ",in[i]);
    cout<<endl;
    inK(root, n-1);
    for(int i=0; i<n; ++i)printf("%d ",post[i]);
    cout<<endl;
    postK(root, n-1);
    return 0;
}
