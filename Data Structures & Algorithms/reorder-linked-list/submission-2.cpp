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
    /*
    first traverse the linked list and make pointers to the head of the second half
    and tail of the list. Reverse the second half of the list and then merge the
    two lists back together
    */
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;

        }

        ListNode* half = head;
        ListNode* tail = head->next;

        while (tail && tail->next) {
            tail = tail -> next -> next;
            half = half -> next;

        }

        ListNode* second = half->next;
        half->next = nullptr;           

        ListNode* prev = nullptr;
        while (second) {
            ListNode* nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        second = prev; // head of reversed second half

    

        ListNode* first = head;
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }

    
        
    }
};
