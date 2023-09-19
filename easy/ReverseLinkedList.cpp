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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr)
        {
            ListNode* next = curr->next;
            if (prev)
            {
                curr->next = prev;
            }
            else
            {
                curr->next = nullptr;
            }
            
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
