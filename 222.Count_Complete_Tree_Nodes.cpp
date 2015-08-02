/*
No. 222 Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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

//Using binary search

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int height = 0;
        TreeNode *p = root;
        while (p) {
            ++height;
            p = p->left;
        }
        if (height == 1)    //This does not suit in the following while loop, since the p in the loop must not start from the bottom most layer
            return 1;
        int count = 0, start = 1, result = (1 << (height - 1)) - 1;
        p = root;
        TreeNode *cur = root;
        while (true) {
            if (p->left == NULL || p->right == NULL) {
                //if p->left == NULL, we must be at the bottom most layer, and the current node is not counted yet
                //if p->right == NULL, we can be at the parent layer of the bottom most layer, and its left child is not counted yet
                //so if any of its child is NULL, we have reached the end of our search and should add 1 to the result counter
                return result + 1;
            }
            count = start;
            cur = p->right;
            while (cur && cur->right) { //we will add 1 to the current counter only when current node has a right child, so we may never reach the bottom most layer here, and count must be less than height
                cur = cur->left;
                ++count;
            }
            if (count == height - 1) {  //current node is a leaf, and the parent of current node has two children (since it has a right child also)
                p = p->right;
                result += 1 << (height - start - 1);
            } else {                    //count == height - 2, no right child
                if (cur->left) {
                    //found the rightmost leaf node
                    result += 1 << (height - start - 1);
                    return result + 1;
                } else {
                    p = p->left;
                }
            }
            ++start;
        }
    }
};
