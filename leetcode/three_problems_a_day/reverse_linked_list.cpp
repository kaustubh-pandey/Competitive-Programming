/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr;
        ListNode* nxt;
        ListNode* prev;
        prev=NULL;
        curr=head;
        if(head==NULL || head->next==NULL){
            return curr;
        }
        nxt = head->next;
        while(nxt){
         curr->next=prev;
         prev=curr;
         curr=nxt;
         nxt=nxt->next;
        }
        curr->next=prev;
        return curr;
    }
};