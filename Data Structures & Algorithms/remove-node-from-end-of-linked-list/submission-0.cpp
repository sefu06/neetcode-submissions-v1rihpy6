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

        //reverse the linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        //remove nth node from the starting node (prev)
         ListNode* revHead = prev;

        // Case 1: removing the first node of reversed list
        if (n == 1) {
            ListNode* toDelete = revHead;
            revHead = revHead->next;
            delete toDelete;
        } else {
            // Remove general case
            ListNode* curr2 = revHead;
            for (int i = 1; i < n - 1; i++) {
                curr2 = curr2->next;
            }
            ListNode* toDelete = curr2->next;
            curr2->next = toDelete->next;
            delete toDelete;
        }

        prev = nullptr;
        curr = revHead;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;


        
    }
};
