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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *prev = NULL;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == NULL)
        {
            if (prev)
                prev->next = slow->next;
            else
                head = NULL; 
        }
        else
        {
            slow->next = slow->next->next;
        }

        return head;
    }
};