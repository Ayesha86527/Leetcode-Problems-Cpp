class MinStack {
private:
    int s[30000];        // Main array to store values
    int minS[30000];     // Array to track minimum at each level
    int topIndex;        // Stack pointer
    
public:
    MinStack() {
        topIndex = -1;
    }
    
    void push(int val) {
        topIndex = topIndex + 1;
        s[topIndex] = val;
        
        if (topIndex == 0) {
            minS[topIndex] = val;  
        } else {
            minS[topIndex] = min(val, minS[topIndex - 1]);  
        }
    }
    
    void pop() {
        if (topIndex == -1) {
            return;
        }
        topIndex = topIndex - 1;
    }
    
    int top() {
        return s[topIndex];
    }
    
    int getMin() {
        return minS[topIndex];  
    }
};
