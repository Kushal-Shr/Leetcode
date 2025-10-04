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
private:
    void reverse(ListNode* &head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        head = prev;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        reverse(head);

        if (n == 1)
        {
            head = head->next;
        }

        else
        {
            ListNode *curr = head;

            for (int i = 0; i < n - 2; i++)
            {
                curr = curr->next;
            }

            curr->next = curr->next->next;
        }

        reverse(head);

        return head;
    }
};