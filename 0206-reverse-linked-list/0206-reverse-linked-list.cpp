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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp)
        {
            ListNode* nextN = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextN;
        }

        head = prev;
        return head;
    }
};