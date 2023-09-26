// n - длина первого листа, m - длина второго листа
// Time: max(n + m)
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

   ListNode * middleNode(int steps, ListNode *nodeSteps, ListNode *node)
   {
       for (int i = 0; i < steps; ++i)
       {
           nodeSteps = nodeSteps->next;
       }

       while (nodeSteps && node)
       {
           if (nodeSteps == node)
               return node;

           nodeSteps = nodeSteps->next;
           node = node->next;
       }

       return nullptr;
   }

   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
   {
       ListNode *a = headA;
       ListNode *b = headB;
       int i = 0, j = 0;
       while (a || b)
       {
           if (a)
           {
               ++i;
               a = a->next;
           }

           if (b)
           {
               ++j;
               b = b->next;
           }
       }

       return middleNode(std::abs(i - j), i >= j ? headA : headB, i >= j ? headB : headA);
   }
};
