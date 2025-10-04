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
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *curr = head;

        while (curr)
        {
            Node *newNode = new Node(curr->val);
            if (cloneHead == NULL)
            {
                cloneHead = newNode;
                cloneTail = newNode;
            }
            else 
            {
                cloneTail->next = newNode;
                cloneTail = cloneTail->next;
            }

            curr = curr->next;
        }

        unordered_map<Node*, Node*> old_to_new;

        curr = head;
        Node *cloneCurr = cloneHead;

        while (curr)
        {
            old_to_new[curr] = cloneCurr;
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        curr = head;
        cloneCurr = cloneHead;

        while (curr)
        {
            cloneCurr->random = old_to_new[curr->random];
            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
    }
};