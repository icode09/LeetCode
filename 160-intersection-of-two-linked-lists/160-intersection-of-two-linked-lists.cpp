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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0 , sizeB = 0;
        ListNode* curr = headA;
        while(curr){
            curr = curr->next;
            sizeA++;
        }
        curr = headB;
        while(curr){
            curr = curr->next;
            sizeB++;
        }

        if(sizeA > sizeB){
            for(int i = 0;i<sizeA - sizeB;i++){
                headA = headA->next;
            }
        }else{
            for(int i = 0;i<sizeB - sizeA;i++){
                headB = headB->next;
            }
        }

        
        while(headA && headB){
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};