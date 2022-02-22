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
    int findSize(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = findSize(l1);
        int size2 = findSize(l2);
        cout<<size1<<" "<<size2<<endl;
        ListNode* res = NULL;
        int diff;
        if(size1 > size2){
            while(size1 != size2){
                ListNode* newNode = new ListNode(l1->val);
                newNode->next = res;
                res = newNode;
                l1 = l1->next;
                size1--;
            }
        }else if(size2 > size1){
            while(size2 != size1){
                ListNode* newNode = new ListNode(l2->val);
                newNode->next = res;
                res = newNode;
                l2 = l2->next;
                size2--;
            }
        }
        
        while(l1 && l2){
            ListNode* newNode = new ListNode(l1->val + l2->val);
            cout<<newNode->val<<" ";
            newNode->next = res;
            res = newNode;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* curr = res;
        res = NULL;
        
        while(curr){
            curr->val += carry;
            if(curr->val >= 10){
                curr->val = (curr->val)%10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            ListNode* next = curr->next;
            curr->next = res;
            res = curr;
            curr = next;
        }
        
        if(carry){
            curr = new ListNode(carry);
            curr->next = res;
            res = curr;
        }
        
        return res;
    }
};