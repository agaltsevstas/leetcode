// Time: O(n)
// Memory: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        auto slow = head;
        auto fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (!fast || !fast->next) // нету цикла
            return nullptr;

        slow = head; // Сбрасываем в самое начало
        while (slow != fast) // по 1 шагу оба указателя
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
