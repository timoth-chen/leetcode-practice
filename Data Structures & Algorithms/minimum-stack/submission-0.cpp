class MinStack {
public:
    vector<int> cur_stack;
    vector<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        cur_stack.push_back(val);
        if (min_stack.empty()){
            min_stack.push_back(val);
        } else{
            min_stack.push_back(min(min_stack.back(), val));
        }
    }
    
    void pop() {
        cur_stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return cur_stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};
