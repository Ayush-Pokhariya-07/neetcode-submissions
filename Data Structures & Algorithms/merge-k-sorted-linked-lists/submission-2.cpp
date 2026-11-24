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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return b->val < a->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   return NULL;

        ListNode* res = new ListNode(0);
        ListNode* temp = res;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                minHeap.push(lists[i]);
            }
        }

        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();

            temp->next = node;
            node = node->next;
            temp = temp->next;

            if(node){
                minHeap.push(node);
            }
        }

        return res->next;
    }
};
