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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while (left && right)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
                curr = curr->next;
            }
        }

        if (left)
        {
            curr->next = left;
        }
        else
        {
            curr->next = right;
        }

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = findMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;

        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        ListNode *res = merge(left, right);

        return res;
    }
};