/*
No.166 Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //to reduce calculation
        if (denominator == 1)
            return to_string(numerator);
        //deal with overflow
        if (numerator == INT_MIN && denominator == -1)
            return (to_string((long long)numerator / denominator));
        bool isNeg = false;
        //more comfortable to deal with both positive or both negative numbers (in case numerator == INT_MIN)
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) {
            isNeg = true;
            denominator = -denominator;
        }
        string result, intS, numS;
        int integral = numerator / denominator, rem = numerator % denominator;
        intS += to_string(integral);
        result = isNeg ? '-' + intS : intS;
        //deal with fraction part
        if (rem != 0) {
            unordered_map<int, int> rem2pos;
            int idx = 0;
            while (rem2pos.find(rem) == rem2pos.end()) {
                //record the position of current digit in fraction part
                rem2pos[rem] = idx;
                //calculate current digit position and remainder
                numS += ((long long)rem * 10 / denominator + '0');
                rem = (long long)rem * 10 % denominator;
                ++idx;
                //remainder equals to 0 means the result is non-recurring decimal
                if (rem == 0)
                    break;
            }
            //if recurring decimal, add parentheses
            if (rem != 0) {
                numS += ')';
                //string::insert accepts (int)pos with (const char*)str or (iterator)p with (char)c
                char* temp = "(";
                numS.insert(rem2pos[rem], temp);
            }
            result = result + '.' + numS;
        }
        return result;
    }
};
