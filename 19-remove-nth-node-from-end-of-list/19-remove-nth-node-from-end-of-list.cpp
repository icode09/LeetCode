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
    int findLength(ListNode* head){
        ListNode* curr = head;
        int len = 0;
        while(curr){
            len++;
            curr = curr->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        
        int len = findLength(head);
        n = len - n + 1;
        
        if(n == 1) return head->next;
        
        ListNode* prev = NULL , *curr = head;
        for(int i = 0;i<n-1;i++){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        
        return head;
    }
};