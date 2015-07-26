/*
No 30 Substring With Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> rec, dict;
        //build the dictionary
        for (string word : words)
            ++dict[word];
        int count = 0;  //word counter
        for (int i = 0; i < len; ++i) {
            int start = i, cur = i;
            count = 0;
            rec.clear();
            while (cur < s.size()) {
                string word = s.substr(cur, len);
                cur += len;
                if (dict.count(word) == 0) {
                    //did not find the word in the dictionary
                    start = cur;
                    count = 0;
                    rec.clear();
                } else {
                    ++rec[word];
                    ++count;
                    //delete the last copy of this word from record
                    while (rec[word] > dict[word]) {
                        --rec[s.substr(start, len)];
                        start += len;
                        --count;
                    }
                    //when count is equal to n, we have found a solution
                    if (count == n)
                        result.push_back(start);
                }
            }
        }
        return result;
    }
};
