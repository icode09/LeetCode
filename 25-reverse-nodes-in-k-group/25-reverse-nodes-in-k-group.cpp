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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 0) return head;
        
        ListNode* curr = head;
        int len = 0;
        while(curr){
            curr = curr->next;
            len++;
        }
        
        curr = head;
        ListNode* prev = NULL , *next;
        int count = 0;
        while(curr && count < k){
            next = curr->next;
            curr->next = prev;
            
            prev  = curr;
            curr = next;
            
            count++;
        }
        
        len = len - count;
        if(len < k) head->next = curr;
        else head->next = reverseKGroup(curr , k);
        
        return prev;
    }
};