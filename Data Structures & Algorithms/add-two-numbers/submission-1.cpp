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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* prev = NULL;
        int rem = 0;
        while(head1 && head2){
            int sum = head1->val + head2->val + rem;
            rem = sum/10;
            sum = sum%10;

            prev = head2;
            head2->val = sum;

            head2 = head2->next;
            head1 = head1->next;
        }

        if(head1){
            prev->next = head1;
            head2 = head1;
        }
        while(head2){
            int sum = head2->val + rem;
            rem = sum/10;
            sum = sum%10;
        
            head2->val = sum;
            prev = head2;
            head2 = head2->next;
        }
        if(rem > 0){
            ListNode* temp = new ListNode(rem);
            prev->next = temp;
        }
        return l2;
    }
};
