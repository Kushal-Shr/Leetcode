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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        int count = 0;

        while (count < k)
        {
            if (!temp)
                return head;
            temp = temp->next;

            count++;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != temp)
        {
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        head->next = reverseKGroup(temp, k);

        return prev;
    }
};