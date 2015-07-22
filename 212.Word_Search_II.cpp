/*
No. 212 Word Search II

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
//Using linked-list-constructed trie, seems slower than 26-element-vector-constructed trie, but costs less space
//Have considered using counter for already found words, which will make it faster when the board is large and all words exists on board
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (words.empty() || board.empty() || board[0].empty())
            return result;
        int m = board.size(), n = board[0].size();
        //first build the trie
        buildTrie(words);
        string cur;                     //record a possible prefix
        stack<pair<int, int> > path;    //record the current path, used for backtracking
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //search from the current coordinate
                dfs(result, board, cur, i, j);
            }
        }
        return result;
    }
    
private:
    vector<int> varX = {0, 1, 0, -1};
    vector<int> varY = {1, 0, -1, 0};
    
    void dfs(vector<string> &result, vector<vector<char> > &board, string &cur, int x, int y) {
        //record path and mark on board as visited
        cur += board[x][y];
        board[x][y] = '*';
        //only continue dfs if finds the current prefix
        if (trie->startsWith(cur)) {
            //add to result if find one word
            if (trie->search(cur)) {
                result.push_back(cur);
                trie->searchPre(cur)->isWord = false;   //avoid duplication
            }
            //dfs from its 4 neighboring points
            for (int i = 0; i < 4; ++i) {
                if (x + varX[i] < 0 || x + varX[i] > board.size() - 1 || y + varY[i] < 0 || y + varY[i] > board[0].size() - 1 || board[x + varX[i]][y + varY[i]] == '*')
                    continue;
                //guarantees a valid coordinate before continuing dfs
                dfs(result, board, cur, x + varX[i], y + varY[i]);
            }
        }
        //recover the board and current string
        board[x][y] = cur.back();
        cur.erase(cur.size() - 1);
    }
    
    //Below is the trie data structure used in this solution
    class TrieNode {
    public:
        char val = '#';
        TrieNode *next = NULL, *child = NULL;
        bool isWord = false;
        TrieNode() {}
    };
    
    class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }
        
        ~Trie() {
            deleteNode(root);
        }
        
        //insert a word into the trie
        void insert(string word) {
            TrieNode *p = root, *cur, *prev;
            for (char c : word) {
                if (!p->child)
                    p->child = new TrieNode();  //sentinel, making it convenient for processing below
                cur = p->child;                 //cur must not be NULL since there is sentinel
                while (cur->next && cur->next->val < c)
                    cur = cur->next;            //find the point before which the new letter is inserted (if it needs to be)
                if (cur->next && cur->next->val == c) {
                    p = cur->next;              //this letter already exists in the current trie
                } else {
                    TrieNode *temp = new TrieNode();
                    temp->val = c;
                    temp->next = cur->next;
                    cur->next = temp;
                    p = temp;
                }
            }
            p->isWord = true;                   //end of the word
        }
        
        //returns the node representing the last letter in the prefix, or NULL if such prefix does not exist in the trie
        TrieNode* searchPre(string pre) {
            TrieNode *cur = root;
            for (char c : pre) {
                cur = cur->child;
                while (cur) {
                    if (cur->val == c)
                        break;
                    else if (cur->val > c)
                        return NULL;
                    cur = cur->next;
                }
                if (!cur)
                    return NULL;
            }
            return cur;
        }
        
        //search for a word and returns true if it exists in current trie
        bool search(string word) {
            TrieNode *cur = searchPre(word);
            return (cur && cur->isWord);    //prefix exists and this can be the end of a word
        }
        
        bool startsWith(string prefix) {
            return (searchPre(prefix) != NULL);
        }
    private:
        TrieNode *root;
        
        //for destrutor (removing a word will be more complicated than this)
        void deleteNode(TrieNode *p) {
            if (p->next)
                deleteNode(p->next);
            if (p->child)
                deleteNode(p->child);
            delete p;
        }
    };
    
    //build a trie including all and just the words in the given vector
    void buildTrie(vector<string> &words) {
        if (trie)
            delete trie;        //in case we will reuse the class, just destroy the previously existing trie
        trie = new Trie();
        for (string word : words)
            trie->insert(word);
    }
    
    Trie *trie = NULL;
};
