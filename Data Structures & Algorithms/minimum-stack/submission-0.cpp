class MinStack {
public:
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i = 0; i < stack.size(); i++){
            mini = min(mini, stack[i]);
        }
        return mini;
    }
};
