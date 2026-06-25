/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* second = slow->next;
        slow->next = nullptr; // Sever the first half from the second half
        ListNode* prev = nullptr;
        
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Step 3: Merge the two halves alternately
        ListNode* first = head;
        second = prev; // 'prev' is now the head of the reversed second half
        
        while (second) {
            // Store the next nodes
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            
            // Link the nodes together
            first->next = second;
            second->next = tmp1;
            
            // Move the pointers forward
            first = tmp1;
            second = tmp2;
        }
    }
};