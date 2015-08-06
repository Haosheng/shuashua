/*
No. 233 Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        long long result = 0, last = INT_MIN;
        for (long long i = 10; last < result ; i *= 10) {   //Just too lazy to think of other ending condition :P
            last = result;
            result += (n / i * (i / 10));                   //Number of bases (eg: 1, 10, 100, ...) contained in (n / (10 * base)) * (10 * base) (this does not contain the 'remainder' part). Every base contained represents one '1' on the current digit.
            if (n % i >= i / 10) {                          //Check if there is any base left out in the remainder part
                if (n % i < i / 5)                          //If the remainder part is less than (20..0)
                    result += (n % (i / 10) + 1);
                else                                        //If the remainder part is no less than (20..0), then the number of '1' on the current digit in the remainder part is just the base number
                    result += i / 10;
            }
        }
        return result;
    }
};
/*
For example:
n = 113. 
1.  When considering the right most digit, we divide it with 10, and find that there are 11 10s, and every 10 will contain a '1';
2.  Then consider the remainder part we get by dividing it by 10, which is 3. 3 is larger than 1, and also larger than 2, so there will be an extra '1';
3.  Then consider the '10' digit, we divide it by 100, finding out that there is only one 100, containing only one '10'. But this '10' represents '1' on the '10' digit, so it will come with 9 other numbers with the same '10' digit. In total this contributes 10 to the counter;
4.  For the remainder part of this, it is 13, which is larger than 10 but smaller than 20. So we will add (13 % 10 + 1 = 3 + 1) to the result;
...
*/
