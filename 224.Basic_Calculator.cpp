/*
No. 224 Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int start = 0;
        while (start < s.size()) {
	    //Eliminate spaces
            while (start < s.size() && s[start] == ' ')
                ++start;
            if (isdigit(s[start])) {
	        //Deal with numbers
                int idx = start;
                while (idx < s.size() && isdigit(s[idx]))
                    ++idx;
                int curNum = stoi(s.substr(start, idx - start));
		//Cannot use numbers on both sides of opening parenthesis directly in calculation
                if (op.empty() || op.top() == '(')
                    num.push(curNum);
                else {
		    //Since only suming and subtraction, no order concerns, just calculate every two numbers from left to right
                    if (op.top() == '+')
                        curNum += num.top();
                    else
                        curNum = num.top() - curNum;
                    num.pop();
                    op.pop();
                    num.push(curNum);
                }
                start = idx;
            } else {
		//Deal with operators
                if (s[start] == ')') {
                    op.pop();   //pop off the '('
                    if (!op.empty()) {
			//If there is number left alone outside opening parenthesis, do the calculation
                        int curNum = num.top();
                        num.pop();
                        if (op.top() == '+')
                            curNum += num.top();
                        else
                            curNum = num.top() - curNum;
                        num.pop();
                        op.pop();
                        num.push(curNum);
                    }
                } else
                    op.push(s[start]);
                ++start;
            }
        }
        return num.empty() ? 0 : num.top();	//In case of all-space string
    }
};

//Below is a general purpose calculator

/*
class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int start = 0;
        while (start < s.size()) {
            while (start < s.size() && s[start] == ' ')
                ++start;
            if (start == s.size())
                break;
            if (isdigit(s[start])) {
                int next = start;
                while (isdigit(s[next]))
                    ++next;
                num.push(stoi(s.substr(start, next - start)));
                if (!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '%'))
                    calculateLatest(num, op);
                start = next;
            } else {
                if (s[start] == '(')
                    op.push('(');
                else if (s[start] == ')') {
                    num.push(calculateAccessible(num, op));
                }
                else
                    op.push(s[start]);
                ++start;
            }
        }
        return calculateAccessible(num, op);
    }

private:
    int calculateAccessible(stack<int> &num, stack<char> &op) {
        stack<int> tempNum;
        stack<char> tempOp;
        tempNum.push(num.top());
        num.pop();
        while (!op.empty() && op.top() != '(') {
            tempNum.push(num.top());
            num.pop();
            tempOp.push(op.top());
            op.pop();
        }
        if (!op.empty())
            op.pop();
        while (!tempOp.empty())
            calculateLatest(tempNum, tempOp);
        return tempNum.top();
    }
    
    void calculateLatest(stack<int> &num, stack<char> &op) {
        if (num.empty() || op.empty())
            return;
        int num1 = num.top();
        num.pop();
        int num2 = num.top();
        num.pop();
        switch (op.top()) {
            case '+':
                num1 += num2;
                break;
            case '-':
                num1 -= num2;
                break;
            case '*':
                num1 *= num2;
                break;
            case '/':
                num1 /= num2;
                break;
            case '%':
                num1 %= num2;
                break;
            default:
                break;
        }
        op.pop();
        num.push(num1);
    }
};
*/
