/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr){return nullptr;}
        if(head->next==nullptr) return head;
        ListNode* temp=head->next;
        head->next=head->next->next;
        temp->next=head;
        head=temp;
        temp=temp->next->next;
        ListNode* prev=head->next;
        while(temp!=nullptr){
            prev->next=(temp->next!=nullptr)?temp->next:temp;
            ListNode* l=(temp->next!=nullptr)?temp->next->next:temp->next;
            prev->next->next=temp;
            temp->next=l;
            prev=prev->next->next;
            temp=temp->next;
        }
        return head;
    }
};