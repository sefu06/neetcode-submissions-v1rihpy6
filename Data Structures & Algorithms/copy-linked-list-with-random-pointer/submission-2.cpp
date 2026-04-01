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

//what to do in english
// use a hashmap to store the indices of the random pointers
//then, go through the linked list and add the ramdon pointer index in the linked list

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[NULL] = NULL;


        Node* cur = head;


        //store the nodes
        while (cur != nullptr) {
            Node *copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur -> next;
        }

        cur = head;
        while (cur != nullptr) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
             }

             return oldToCopy[head];
        
    }
};
