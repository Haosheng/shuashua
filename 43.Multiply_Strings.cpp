/*
No. 43 Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        //special cases: x * 0
        string result;
        vector<int> calc(num1.size() + num2.size());    //max number of digits of the result must be like this
        int level = num2.size() - 1, cur = num1.size() - 1;
        //simulate the calculation
        while (level >= 0) {
            for (cur = num1.size() - 1; cur >= 0; --cur) {
                int i = num1[cur] - '0', j = num2[level] - '0';
                calc[cur + level + 1] += i * j;
                calc[cur + level] += calc[cur + level + 1] / 10;
                calc[cur + level + 1] %= 10;
            }
            --level;
        }
        //abandon leading 0s
        cur = 0;
        while (calc[cur] == 0)
            ++cur;
        while (cur < calc.size())
            result += (char)(calc[cur++] + '0');
        //result is 0
        if (result.empty())
            result += '0';
        return result;
    }
};
