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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len == n){
            ListNode* z = head;
            head = head->next;
            z = NULL;
            return head;
        }
        len = len - n - 1;

        ListNode* t = head;
        while(len){
            t = t->next;
            len--;
        }

        ListNode* x = t->next;
        if(x != NULL){
            t->next = x->next;
            x->next = NULL;
        }else{
            t = NULL;
        }

        return head;
    }
};
