/***
	173. Binary Search Tree Iterator

	Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

	Calling next() will return the next smallest number in the BST.

	Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
***/

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
    BSTIterator(TreeNode *root){
        push_all(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!m_stk.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = m_stk.top();
        m_stk.pop();
        push_all(tmp->right);
        return tmp->val;
    }
private:
    stack<TreeNode*> m_stk;
    void push_all(TreeNode* node){
        for(;node;node=node->left){
            m_stk.push(node);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 /***
 	Hint: use stack.
 ***/