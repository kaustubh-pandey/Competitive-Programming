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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode;
        head->next=NULL;
        ListNode *curr=head;
        int carry=0,val;
        while(l1 && l2){
            val = l1->val + l2->val + carry;
            curr->val = val%10;
            carry = val/10;
            l1=l1->next;
            l2=l2->next;
            if(l1 || l2){
                curr->next = new ListNode;
                curr=curr->next;
                curr->next=NULL;   
            }
        }
        while(l1){
            val = l1->val+carry;
            curr->val=val%10;
            carry=val/10;
            l1=l1->next;
            if(l1){
                curr->next = new ListNode;
                curr=curr->next;
                curr->next=NULL;   
            }
            
        }
         while(l2){
            val = l2->val+carry;
            curr->val=val%10;
            carry=val/10;
            l2=l2->next;
            if(l2){
                curr->next = new ListNode;
                curr=curr->next;
                curr->next=NULL;   
            }   
        }
        if(carry){
            curr->next = new ListNode;
            curr=curr->next;
            curr->val=carry;
            curr->next=NULL;
        }
        return head;
    }
};