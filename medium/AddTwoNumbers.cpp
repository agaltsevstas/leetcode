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

 // Time: O(max(n, m))
 // Memory: O(max(n, m) + 1)->O(max(n, m))
 // В яндексе дают в обратном порядке, нужно перевернуть
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode();
        ListNode* next = result;

        int carry = 0;
        while (l1 && l2)
        {
            ListNode* node = new ListNode();

            const int sum = l1->val + l2->val + carry;
            node->val = sum % 10;
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
            next = next->next = node;
        }

        while (l1)
        {
            ListNode* node = new ListNode();

            const int sum = l1->val + carry;
            node->val = sum % 10;
            carry = sum / 10;

            l1 = l1->next;
            next = next->next = node;
        }

        while (l2)
        {
            ListNode* node = new ListNode();

            const int sum = l2->val + carry;
            node->val = sum % 10;
            carry = sum / 10;

            l2 = l2->next;
            next = next->next = node;
        }

        if (carry != 0)
        {
            ListNode* node = new ListNode();
            node->val = carry;

            next->next = node;
            carry = 0;
        }

        return result->next;
    }
};
