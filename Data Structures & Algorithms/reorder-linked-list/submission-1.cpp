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
        if (head == nullptr || head -> next == nullptr) {
            return;

        }
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //slow is the head of the second half of the list
        //reverse the second list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        

        while (curr != nullptr) {
              ListNode* next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;

        }

        //merge the lists
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l2->next) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }

        
        
    }
};
