/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        //duplicate each node and insert duplicate in between the node and its next 
        Node* curr = head;
        while(curr){
            Node *node = new Node(curr->val);
            node->random=NULL;
            node->next = curr->next;
            curr->next = node;
            curr=(curr->next)?curr->next->next:NULL;
        }
        //In the copied nodes, connect random pointers
        curr = head;
        while(curr){
          if(curr->next){
           curr->next->random = (curr->random)?curr->random->next:NULL;   
          }
          curr=(curr->next)?curr->next->next:NULL;
        }
        //connect next of copy, fix next of original
        Node *h = head->next;
        curr = head;
        while(curr){
            Node *tmp = curr->next;
            curr->next = (curr->next)?curr->next->next:NULL;
            tmp->next = (tmp->next)?tmp->next->next:NULL;
            curr = curr->next;
        }
        return h;
    }
};