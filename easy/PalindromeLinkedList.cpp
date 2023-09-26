// Time: O(n)
// Memory: O(1)

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
    bool isPalindrome(ListNode* head)
    {
        ListNode* last = head;
        ListNode* middle = head;

        while (last && last->next)
        {
            middle = middle->next;
            last = last->next->next;
        }

        if (last)
            middle = middle->next;

        ListNode* prev = nullptr;
        while (middle)
        {
            ListNode* next = middle->next;
            middle->next = prev;
            prev = middle;
            middle = next;
        }

        while (prev && head)
        {
            if (prev->val != head->val)
                return false;
            
            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};
