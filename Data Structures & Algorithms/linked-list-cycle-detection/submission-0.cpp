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
    bool hasCycle(ListNode* head) {
        
       map<ListNode*,bool> m;

        ListNode* temp = head;

        while(temp != NULL){
            
            if(m[temp] == true){
                return true;
            }

            m[temp]= true;
            temp = temp -> next;

        }

        return false;

        // ListNode* temp1 = head;

        // while(temp1 != NULL){
        //     if(m[temp1] == true){
        //         return true;
        //     }
        //     m[temp1] = true;
        //     temp1 = temp1 -> next;
        // }

        // return false;
        
    }
};
