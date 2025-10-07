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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *newHead = head->next;

        while (curr && curr->next)
        {
            ListNode *forward = curr->next;
            ListNode *nextPair = forward->next;

            forward->next = curr;
            curr->next = nextPair;

            if (prev)
                prev->next = forward;
            
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};