// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
// */

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if(!head)   return NULL;

//         Node* newHead = new Node(head->val);
//         Node* origCurr = head->next;
//         Node* copyCurr = newHead;

//         while(origCurr){
//             copyCurr->next = new Node(origCurr->val);
//             origCurr = origCurr->next;
//             copyCurr = copyCurr->next;
//         }

//         origCurr = head;
//         copyCurr = newHead;

//         while(origCurr){
//             if(origCurr->random){
                
//                 Node* tempOrig = head;
//                 Node* tempCopy = newHead;
                
//                 while(tempOrig != origCurr->random){
//                     tempOrig = tempOrig->next;
//                     tempCopy = tempCopy->next;
//                 }
//                 copyCurr->random = tempCopy;
//             }
//             origCurr = origCurr->next;
//             copyCurr = copyCurr->next;
//         }

//         return newHead;
//     }
// };


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return NULL;

        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        Node* origCurr = head->next;
        Node* copyCurr = newHead;

        while(origCurr){
            copyCurr->next = new Node(origCurr->val);
            
            mp[origCurr] = copyCurr->next;

            origCurr = origCurr->next;
            copyCurr = copyCurr->next;
        }

        origCurr = head;
        copyCurr = newHead;

        while(origCurr){
            copyCurr->random = mp[origCurr->random];
            origCurr = origCurr->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }
};
