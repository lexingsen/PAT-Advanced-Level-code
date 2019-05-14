#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* dummyNode = new ListNode(0);//设置虚拟节点
    ListNode* cur = dummyNode;//工作指针
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    if(!l1)
        cur->next = l2;
    else
        cur->next = l1;
    return dummyNode->next;
}

int main(){
    return 0;
}
