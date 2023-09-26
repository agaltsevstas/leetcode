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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* cur = head;

        int size = 0;
        while (cur)
        {
            ++size;
            cur = cur->next;
        }
        int index = size - n;

        size -= n;
    
        auto stub = new ListNode(0);
        stub->next = head;
        cur = stub;
        for (int i = 0; i < size; ++i)
        {
            cur = cur->next;
        }
        
        cur->next = cur->next->next;

        return stub->next;
    }
};
