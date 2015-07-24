/*
No. 126 Word Ladder II

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

//Optimized by searching from both sides

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        unordered_set<string> s1, s2;
        unordered_set<string> found;
        s1.insert(start);
        s2.insert(end);
        if (dict.count(start) == 1)	//be safe to make sure there is something before erasing it
            dict.erase(dict.find(start));
        if (dict.count(end) == 1)
            dict.erase(dict.find(end));
        unordered_map<string, vector<string> > pre, su;	//prefix and suffix records
        if (findPath(s1, s2, found, pre, su, dict, false))
            generateResult(start, end, found, pre, su, result);
        return result;
    }
    
private:
    bool findPath(unordered_set<string> &start, unordered_set<string> &end, unordered_set<string> &found, unordered_map<string, vector<string> > &pre, unordered_map<string, vector<string> > &su, unordered_set<string> &dict, bool reversed) {
	//end on this situation
        if (start.empty())
            return false;
	//search from the side with fewer words
        if (start.size() > end.size())
            return findPath(end, start, found, pre, su, dict, !reversed);	//just never use ~reversed for flipping! Stuck on this for like an hour
        unordered_set<string> mid;
        for (string word : start) {
            string originalWord = word;
            for (char &c : word) {
                char originalChar = c;
		//replacing each char in the word with every possible alphabet
                for (c = 'a'; c <= 'z'; ++c) {
                    if (end.count(word) == 1) {
                        found.insert(word);
                        if (reversed)
                            su[word].push_back(originalWord);
                        else
                            pre[word].push_back(originalWord);
                    }
		    //if a word is in set "end", it must have been erased from dict, so it will be the same if the following is expressed with "else if"
                    if (dict.count(word) == 1 && word != originalWord) {
                        mid.insert(word);
                        if (reversed)
                            su[word].push_back(originalWord);
                        else
                            pre[word].push_back(originalWord);
                    }
                }
                c = originalChar;	//restore the original char
            }
        }
        if (!found.empty()) {
            return true;		//the two ends meet
        }
        for (string word : mid)
            dict.erase(word);		//avoid duplication
        return findPath(mid, end, found, pre, su, dict, reversed);
    }
    
    void generateResult(string &start, string &end, unordered_set<string> &found, unordered_map<string, vector<string> > &pre, unordered_map<string, vector<string> > &su, vector<vector<string> > &result) {
        vector<vector<string> > cur;
        vector<string> temp;
        for (auto word : found) {
            temp.push_back(word);
            cur.push_back(temp);
            temp.pop_back();
        }
	//tracing the words from middle to the beginning
        while (!cur.empty()) {
            swap(result, cur);
            cur.clear();
            for (auto &path : result) {
                for (string prev : pre[path.front()]) {
                    path.insert(path.begin(), prev);
                    cur.push_back(path);
                    path.erase(path.begin());
                }
            }
	    //there must be some records in "cur" if the previous steps are implemented correctly
            if (cur[0].front() == start)
                break;
        }
	//tracing the words from middle to the end
        while (!cur.empty()) {
            swap(result, cur);
            cur.clear();
	    //there must be some records in "result" if the previous steps are implemented correctly
            if (result[0].back() == end)
                break;
            for (auto &path : result) {
                for (string next : su[path.back()]) {
                    path.push_back(next);
                    cur.push_back(path);
                    path.pop_back();
                }
            }
        }
    }
};

