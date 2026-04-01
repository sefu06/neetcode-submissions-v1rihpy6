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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        if (lists.empty() == true) {
            return nullptr;
        }

        while(true) {
            ListNode* minNode = nullptr;
            int minIndex = -1;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] && (!minNode || lists[i]->val < minNode->val )) {
                minNode = lists[i];
                minIndex = i;

            }
        }

        if (minNode == nullptr) {
            break;

        }

        curr -> next = minNode;
        curr = curr->next;
        lists[minIndex] = lists[minIndex] -> next;

        

        }


        return dummy -> next;
        
    }
};
