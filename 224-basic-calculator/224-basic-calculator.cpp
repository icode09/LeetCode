class Solution {
public:
    int calculate(string s) {
        stack<int> ops({1});
        int total = 0 , num = 0;
        int isPositive = 1;
        
        for(char ch : s){
            if(isdigit(ch)){
                num = num*10 + (ch - '0');
            }else{
                total += num * ops.top() * isPositive;
                num = 0;
                
                if(ch == '+') isPositive = 1;
                else if(ch == '-') isPositive  = -1;
                else if(ch == ')') ops.pop();
                else if(ch == '('){
                    ops.push(ops.top()*isPositive);
                    isPositive = 1;
                }
            }
        }
        
        total += ops.top() * num * isPositive;
        
        return total;
    }
};