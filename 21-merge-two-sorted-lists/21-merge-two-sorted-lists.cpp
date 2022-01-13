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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* root = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                root->next = list1;
                list1 = list1->next;
                root = root->next;
            }else{
                root->next = list2;
                list2 = list2->next;
                root = root->next;
            }
        }
        
       if(list1) root->next = list1;
       if(list2) root->next = list2;
        
        return dummy->next;
    }
};