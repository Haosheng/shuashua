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
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(Node->children[index]==NULL){
                Node->children[index]=new TrieNode();
            }
            Node=Node->children[index];
        }
        Node->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* Node=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(Node->children[index]==NULL) return false;
            Node=Node->children[index];
        }
        return Node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* Node=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(Node->children[index]==NULL) return false;
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

/***
    Use a bool variable to mark whether it is a word.
    This code would just pass the Online Judgement, however, destructor should be implemented to avoid memory leak.
    Moreover, think of how to implement delete(string word) function.
***/