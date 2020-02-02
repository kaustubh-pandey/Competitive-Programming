class Solution {
public:
    void swap(ListNode* first,ListNode* second){
        int temp = first->val;
        first->val=second->val;
        second->val=temp;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *curr = head;
        ListNode *tmp=curr;
        int count=0;
        while(tmp){
            count++;
            tmp=tmp->next;
        }
        while(count--){
            tmp = head;
            while(tmp){
                if(tmp->next && (tmp->val)>(tmp->next->val)){
                    swap(tmp,tmp->next);
                }
                tmp=tmp->next;
            }
        }
        return head;
    }
};