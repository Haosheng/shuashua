class MinStack {
public:
    void push(int x) {
        s.push_back(x);
        if (minS.empty() || x <= minS[minS.size() - 1])
            minS.push_back(x);
    }

    void pop() {
        int x = s[s.size() - 1];
        if (!minS.empty() && x == minS[minS.size() - 1])
            minS.pop_back();
        s.pop_back();
    }

    int top() {
        if (!s.empty())
            return s[s.size() - 1];
    }

    int getMin() {
        if (!minS.empty())
            return minS[minS.size() - 1];
    }
    
private:
    vector<int> s;
    vector<int> minS;
};
