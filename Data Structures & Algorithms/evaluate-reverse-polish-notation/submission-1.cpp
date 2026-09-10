class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        set<string> symbols = {"+", "-", "*","/"};
        for (string s: tokens){
            if (!symbols.contains(s)){
                nums.push(stoi(s));
                continue;
            }

            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            if (s == "+"){
                nums.push(num1 + num2);
            } else if (s == "-"){
                nums.push(num1 - num2);
            } else if (s == "*"){
                nums.push(num1 * num2);
            } else {
                nums.push(num1 / num2);
            }
        }
        return nums.top();
    }
};
