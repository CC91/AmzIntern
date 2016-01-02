// 155. Min Stack

class MinStack {
    stack<int> s;
    stack<int> sMin;
public: // use 2 stacks, one stack to record minimum
    void push(int x) {
        if (sMin.empty() ||x<=sMin.top()) sMin.push(x);
        s.push(x);
    }

    void pop() {
        if (sMin.top()>=s.top()) sMin.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sMin.top();
    }
};