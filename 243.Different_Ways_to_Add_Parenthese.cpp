/*
No. 243 Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

//Using divide and conquer
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (input.empty())	//Empty string, empty result.
            return result;
        else if (input.find('+') == string::npos && input.find('-') == string::npos && input.find('*') == string::npos) {
	    //Just a single number
            result.push_back(stoi(input));
            return result;
        }
        size_t bp = 0;
        while (bp != input.size()) {
	    //Find the next operator, i.e. the next breaking point
            while (bp < input.size() && isdigit(input[bp]))
                ++bp;
            if (bp == input.size())	//No more operators left, we have reached the end of input. Cannot let it run through the code below automatically, or there will be dead lock, since result1 will try to get the result we eventually want, but if we can get that, why bother calculate it again? So this is like doing recursion with exactly the same parameters, which will not give out results.
                break;
            vector<int> result1 = diffWaysToCompute(input.substr(0, bp));	//Calculate the part before breaking point
            vector<int> result2 = diffWaysToCompute(input.substr(bp + 1));	//Calculate the part after the breaking point
	    //Merge two result vectors
            for (int num1 : result1)
                for (int num2 : result2) {
                    switch (input[bp]) {
                        case '+':
                            result.push_back(num1 + num2);
                            break;
                        case '-':
                            result.push_back(num1 - num2);
                            break;
                        case '*':
                            result.push_back(num1 * num2);
                            break;
                    }
                }
            ++bp;	//bp should be pointing to the next number
        }
        return result;
    }
};
