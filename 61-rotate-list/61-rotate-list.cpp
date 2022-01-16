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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int count = 1;
        ListNode* curr = head;
        while(curr->next){
            curr = curr->next;
            count++;
        }
        
        k = k%count;
        curr->next = head;
        for(int i = 0;i<count - k;i++){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};