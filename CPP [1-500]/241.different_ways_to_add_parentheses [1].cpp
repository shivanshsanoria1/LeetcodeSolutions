class Solution {
private:
    bool isOperator(char ch){
        return ch == '+' || ch == '-' || ch == '*';
    }

    vector<string> tokenize(string& s){
        vector<string> tokens;
        string token = "";
        s += '+';

        for(char ch: s)
        {
            if(isOperator(ch))
            {
                tokens.push_back(token);
                token = "";
                token += ch;
                tokens.push_back(token);
                token = "";
            }
            else // ch is a digit
                token += ch;
        }

        s.pop_back();
        tokens.pop_back();

        return tokens;
    }

    vector<int> solve(vector<string>& tokens, int left, int right){
        vector<int> res;
        
        if(left > right)
            return res;

        if(left == right)
        {
            res.push_back(stoi(tokens[left]));
            return res;
        }

        for(int i=left; i<=right; i++)
        {
            if(!isOperator(tokens[i][0]))
                continue;

            vector<int> leftPart = solve(tokens, left, i-1);
            vector<int> rightPart = solve(tokens, i+1, right);

            for(int a: leftPart)
                for(int b: rightPart)
                {
                    if(tokens[i] == "+")
                        res.push_back(a + b);
                    else if(tokens[i] == "-")
                        res.push_back(a - b);
                    else // if(tokens[i] == "*")
                        res.push_back(a * b);
                }
        }

        return res;
    }

public:
    // Recursion
    vector<int> diffWaysToCompute(string expression) {
        vector<string> tokens = tokenize(expression);

        vector<int> ans = solve(tokens, 0, tokens.size()-1);

        return ans;
    }
};