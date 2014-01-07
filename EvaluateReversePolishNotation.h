/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       
 Problem:    Evaluate Reverse Polish Notation
 Difficulty: Easy
 Notes:
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 Solution: stack.
 */
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                stack.push(stoi(tokens[i]));
            else {
                int op2 = stack.top();stack.pop();
                int op1 = stack.top();stack.pop();
                int result = 0;
                if(tokens[i]=="+")
                    result = op1 + op2;
                else if(tokens[i]=="-")
                    result = op1 - op2;
                else if(tokens[i]=="*")
                    result = op1 * op2;
                else if(tokens[i]=="/")
                    result = op1 / op2;
                stack.push(result);
            }
        }
        return stack.top();
    }
};
