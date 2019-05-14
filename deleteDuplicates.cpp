#include <iostream>
using namespace std;

ListNode* deleteDuplicates(ListNode* head){
    if(!head)
        return NULL;
    ListNode* fast = head->next;//快指针  指向第二个节点
    ListNode* slow = head;//满指针  指向第一个节点
    while(fast){
        if(fast->val == slow->val){
            slow->next = fast->next;
        }
        else{
            slow = slow->next;
        }
        fast = fast->next;
    }
    return head;
}


int main(){
    return 0;
}
