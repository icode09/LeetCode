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
        if(!head || !(head->next)) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head , *next = curr->next;
        
        head = head->next;
        
        while(curr && next){
            if(prev)
                prev->next = next;
            
            curr->next = next->next;
            next->next = curr;
            prev = curr;
            curr = curr->next;
            
            if(curr)
                next = curr->next;
        }
        
        return head;
    }
};