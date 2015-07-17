/***
	233. Number of Digit One
	Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

	For example:
	Given n = 13,
	Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
***/

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        if(n < 10) return 1;
        string str = to_string(n);
        int cnt = 0;
        int digit = 0;
        do{
            int fig = n % 10;
            if(fig == 1){
                int tmp = stoi(str.substr(str.length()-digit-1));
                cnt += amp[digit] + tmp - base[digit] + 1;
            }
            else if(fig > 0){
                cnt += fig*amp[digit] + base[digit];
            }
            digit++;
            n=n/10;
        }while(n);
        return cnt;
    }
private:
    static int amp[10]; 
    static int base[10];
};

int Solution::amp[10]= {0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
int Solution::base[10]= {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

/***
	The basic idea is: divide the number into small parts and aggregate the results.

	For example: 289 = 2*100 + 8*10 + 9 thus the ones in 289 equals the sum of ones in 200 and 80 and 9.

	How to compute the number of ones in 200?

	0 ~ 9: contains 1 "1"

	0 ~ 99: contains 20 "1"s

	0 ~ 999: contains 300 "1"s

	0 ~ 9999: contains 4000 "1"s

	...

	0 ~ 1e10-1: contains 900,000,000 "1"s

	this covers the INT_MAX.

	200 contains 2 (0 ~ 99) ranges, and from (100 ~ 199) contains another 100 "1"s. So 200 contains 2 * 20 + 100 = 140 "1"s.

	80 contains 8 * 1 + 10 = 18 "1"s. 9 contains 9 * 0 + 1 = 1 "1"

	So 289 contains 140 + 18 + 1 = 159 "1"s.

	count += fig * amp[digit] + base[digit];

	However, if fig == 1, this is special case.

	e.g. 13 = [1 * 1 + (13 - 10) + 1] + [3 * 0 + 1] = 6

	124 = [1 * 20 + (124 - 100) + 1] + [2 * 1 + 10] + [4 * 0 + 1] = 58

	count += 1 * amp[digit] + number_start_from_fig - base[digit] + 1;

	to compute number_start_from_fig (415 -> 15; 156 -> 156; 3124 -> 124), I used string substr() function.
***/