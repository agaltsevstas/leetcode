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
    ListNode* reverseList(ListNode* head) // [1->2->3->4->5]
    {
        if (!head)
            return nullptr;

        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur) // [1->2->3->4->5], [nullptr<-1->2->3->4->5], [nullptr<-1<-2->3->4->5], [nullptr<-1<-2<-3->4->5], [nullptr<-1<-2<-3<-4->5],  [nullptr<-1<-2<-3<-4<-5]
        {
            ListNode* next = cur->next; // 2, 3, 4, 5, nullptr
            cur->next = prev; // 1->nullptr, 2->1, 3->2, 4->3, 5->4
            prev = cur; // 1, 2, 3, 4, 5
            cur = next; // 2, 3, 4, 5, nullptr
        }

        return prev;
    }
};
