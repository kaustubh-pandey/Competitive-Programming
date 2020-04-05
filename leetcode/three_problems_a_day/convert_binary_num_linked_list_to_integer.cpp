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
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        int val=0;
        int count=0;
        while(!st.empty()){
            int d = st.top();
            st.pop();
            val+= (1<<count)*d;
            count++;
        }
        return val;
    }
};