/*
No. 235 Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root, *s, *l;
	//For convenience
        if (p->val > q->val) {
            s = q;
            l = p;
        } else {
            s = p;
            l = q;
        }
        while (cur) {
	    //If the LCA is not one of the two nodes, then the two nodes must be on different sides of LCA
            if (cur == p || cur == q || cur->val > s->val && cur->val < l->val)
                return cur;
            else if (cur->val > l->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return NULL;	//This will not be reached, usually
    }
};
