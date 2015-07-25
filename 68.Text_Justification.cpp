/*
No. 68 Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string cur;
        int charCnt = -1;
        int start = 0, end = 0;
        if (maxWidth == 0)
            result.push_back("");
        else
            while (end < words.size()) {
                charCnt = -1;
                cur.clear();
                //assuming each word length would be less than maxWidth
                while (end < words.size() && charCnt + words[end].size() + 1 <= maxWidth) {
                    charCnt += words[end].size() + 1;
                    ++end;
                }
                if (end == words.size()) {      //the last row
                    for (; start < end; ++start) {
                        cur += words[start];
                        cur += ' ';
                    }
                    cur.erase(cur.size() - 1);
                    cur.append(maxWidth - cur.size(), ' ');
                } else if (end == start + 1) {  //just one word
                    cur += words[start++];
                    cur.append(maxWidth - cur.size(), ' ');
                } else {
                    int leftover = maxWidth - charCnt;
                    int avg = leftover / (end - start - 1), extra = leftover % (end - start - 1);   //end - start - 1 would be number of gaps
                    int mid = start + extra;
                    for (; start < mid; ++start) {
                        cur += words[start];
                        cur.append(avg + 2, ' ');   //actually 1 + avg + 1
                    }
                    for (; start < end; ++start) {
                        cur += words[start];
                        cur.append(avg + 1, ' ');
                    }
                    cur.erase(cur.size() - 1 - avg);
                }
                result.push_back(cur);
            }
        return result;
    }
};
