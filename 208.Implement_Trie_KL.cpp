/*
No. 208 Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.
*/

//Using linked lists for child nodes
//60ms implement time
//Could have done better using BST for child nodes (but I am lazy lol)
class TrieNode {
public:
    TrieNode() {
    }
    
    TrieNode(char c)
    :val(c) {
    }
    
    //Using prev and next to traverse child nodes. Child points to the first child of the current node
    TrieNode *prev = NULL, *next = NULL, *child = NULL;
    //Using '.' as a sentinel for word end
    char val = '.';
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            TrieNode *temp = searchChar(cur->child, c);
	    //If current char exists in the child list, continue
            if (temp && temp->val == c)
                cur = temp;
	    //If does not exist, just insert it
            else
                cur = insertChar(cur, temp, c);
        }
	//Add the sentinel for word end
        if (!cur->child || cur->child->val != '.')
            cur = insertChar(cur, cur->child, '.');
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *temp = find(word);
        if (!temp)
            return false;
	//Check if there is any word ending at this point
        return (temp->child->val == '.');
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return (find(prefix) != NULL);
    }

private:
    TrieNode* root;
    
    //O(n) search time. That's why I suggest BST can be faster :(
    TrieNode* searchChar(TrieNode *cur, char c) {
        while (cur) {
            if (cur->val > c)
                break;
            else if (cur->val == c)
                return cur;
            else
                cur = cur->next;
        }
        return cur;
    }
    
    TrieNode* insertChar(TrieNode *father, TrieNode *cur, char c) {
        TrieNode *temp = new TrieNode(c);
        if (!father->child) {			//If father node has no child node
            father->child = temp;
        } else if (!cur) {			//If inserting at the end of the list
            TrieNode *p = father->child;
            while (p->next)
                p = p->next;
            p->next = temp;
            temp->prev = p;
        } else if (cur == father->child) {	//If inserting at the head of the child list
            temp->next = cur;
            cur->prev = temp;
            father->child = temp;
        } else {				//Normal cases
            temp->next = cur;
            temp->prev = cur->prev;
            temp->prev->next = temp;
            cur->prev = temp;
        }
        return temp;
    }
    
    //Tries to find the prefix in the trie. If finds it, returns the last node, or just returns NULL
    TrieNode* find(string prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            TrieNode *temp = searchChar(cur->child, c);
            if (!temp || temp->val != c)
                return NULL;
            cur = temp;
        }
        return cur;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
