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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode* slow = head , *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow = middle , if even then first node of middle two nodes will be slow
        
        ListNode* curr = slow->next;
        ListNode* prev = NULL , *next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        while(head && prev){
            if(head->val != prev->val) return false;
            
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
};