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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while(half){
            ListNode* next = half->next;
            half->next = prev;
            prev = half;
            half = next;
        }

        half = prev;

        while(half){
            ListNode* temp1 = head->next;
            ListNode* temp2 = half->next;

            head->next = half;
            half->next = temp1;

            head = temp1;
            half = temp2;
        }
    }
};
