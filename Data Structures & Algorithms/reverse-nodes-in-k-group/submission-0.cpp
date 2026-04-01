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

/**pseudocode:
while loop to count the number of nodes in the list

theres a for loop loooping through the linked list d
for the first k nodes. reduce the count 

reverse the list, next by recursion

*/

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
    
       while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count < k) {
            return head;

        } else {
             curr = head;
             ListNode* prev = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr-> next = prev;
                prev = curr;
                curr = next;

            }

            head->next = reverseKGroup(curr, k);
            return prev;

        }

        

        

        
        
    }
};
