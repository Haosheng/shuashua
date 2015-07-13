/*
Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/
/*
I should say that the description sucks. The word "next" is kind of misleading since at the beginning what it desires is just the smallest number.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while (cur){
            trace.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !trace.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = trace.top();
        int result = cur->val;
        trace.pop();
        if (cur->right) {
	    //Find the next element in an inorder traversal, track elements on the way
            TreeNode *temp = cur->right;
            while (temp) {
                trace.push(temp);
                temp = temp->left;
            }
        }
        return result;
    }

private:
    //Using stack to track father nodes. Current element is at the top. Not using extra pointer.
    stack<TreeNode *> trace;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
