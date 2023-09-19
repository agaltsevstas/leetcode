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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        ListNode* begin = new ListNode(0);
        ListNode* curr = begin;
        ListNode* list1_curr = list1;
        ListNode* list2_curr = list2;

        while (list1_curr || list2_curr)
        {
            if ((list2_curr == nullptr) || (list1_curr && list1_curr->val <= list2_curr->val))
            {
                curr->next = list1_curr;
                list1_curr = list1_curr->next;
            }
            else if ((list1_curr == nullptr) || (list2_curr && list2_curr->val < list1_curr->val))
            {
                curr->next = list2_curr;
                list2_curr = list2_curr->next;
            }

            curr = curr->next;
        }

        return begin->next;
    }
};
