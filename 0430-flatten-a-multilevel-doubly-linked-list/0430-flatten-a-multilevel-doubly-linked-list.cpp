/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr)
        {
            if (curr->child)
            {
                Node* n = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                
                while (curr && curr->next)
                {
                    curr = curr->next;
                }

                curr->next = n;
                if (n)
                n->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};