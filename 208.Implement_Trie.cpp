/***
	208. Implement Trie
	Implement a trie with insert, search, and startsWith methods.

	Note:
	You may assume that all inputs are consist of lowercase letters a-z.
***/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    bool isWord;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
       TrieNode *Node=root;
       TrieNode *prev;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(Node->children[index]==NULL){
                Node->children[index]=new TrieNode();
            }
            prev=Node;
            Node=Node->children[index];
        }
        prev->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* Node=root;
        TrieNode *prev;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(Node->children[index]==NULL) return false;
            prev=Node;
            Node=Node->children[index];
        }
        return prev->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* Node=root;
        TrieNode *prev;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(Node->children[index]==NULL) return false;
            prev=Node;
            Node=Node->children[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");