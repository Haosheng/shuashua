/*
No.160 Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *p1 = headA, *p2 = headB;
        int lenDiff = 0;                //length difference between A and B, will be positive if A is longer, vice versa
	while (p1 && p2) {
	    p1 = p1->next;
	    p2 = p2->next;
	}
	//in case the link lists will be too long, not counting the common length part
        while (p1) {
            p1 = p1->next;
            ++lenDiff;
        }
        while (p2) {
            p2 = p2->next;
            --lenDiff;
        }
        p1 = headA, p2 = headB;
        //make the remaining length in their list from p1 and p2 the same
        if (lenDiff > 0)
            for (; lenDiff != 0; --lenDiff)
                p1 = p1->next;
        else if (lenDiff < 0)
            for (; lenDiff != 0; ++lenDiff)
                p2 = p2->next;
        //try to find the intersection
        ListNode *result = NULL;
        while (p1) {
            //if have not yet found a candidate
            if (p1->val == p2->val && !result)
                result = p1;
            //if fake candidate exists
            else if (p1->val != p2->val && result)
                result = NULL;
            p1 = p1->next;
            p2 = p2->next;
        }
        return result;
    }
};
