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

        // Floyd's cycle detection

        if(head == NULL || head -> next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }

            slow = slow -> next;

            if(fast == slow) return true;
        }
        return false;

        /* method 1 */
        // unordered_set<ListNode*> st;

        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(st.find(temp) != st.end()){
        //         return true;
        //     }

        //     st.insert(temp);
        //     temp = temp -> next;
        // }

        // return false;

        // method 2
        
    //    map<ListNode*,bool> m;

    //     ListNode* temp = head;

    //     while(temp != NULL){
            
    //         if(m[temp] == true){
    //             return true;
    //         }

    //         m[temp]= true;
    //         temp = temp -> next;

    //     }

    //     return false;

        
    }
};
