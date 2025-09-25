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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode *curr = head;
        ListNode *prev = nullptr;

        int i = 1;

        while (i < left)
        {
            prev = curr;
            curr = curr -> next;
            i++; 
        }

        ListNode *start = prev;

        ListNode *b_head = curr;
        ListNode *b_prev = nullptr;
        ListNode *b_for = b_head -> next;

        for (int j = 0; j < right - left + 1; j++)
        {
            b_head -> next = b_prev;
            b_prev = b_head;
            b_head = b_for;
            if (b_for) b_for = b_for->next;
        }

        if (start)
        {
            start->next->next = b_head;
            start -> next = b_prev;
        }
        else
        {
            head->next = b_head;
            head = b_prev;
        }

        return head;
    }
};