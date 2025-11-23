class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

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

    vector<int> solve(vector<string>& tokens, int left, int right, VEC3D& dp){
        vector<int> res;

        if(left > right)
            return res;
        
        if(left == right)
        {
            res.push_back(stoi(tokens[left]));
            return res;
        }

        if(!dp[left][right].empty())
            return dp[left][right];

        for(int i=left; i<=right; i++)
        {
            if(!isOperator(tokens[i][0]))
                continue;

            vector<int> leftPart = solve(tokens, left, i-1, dp);
            vector<int> rightPart = solve(tokens, i+1, right, dp);

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

        dp[left][right] = res;
        return dp[left][right];
    }

public:
    // Memoization
    vector<int> diffWaysToCompute(string expression) {
        vector<string> tokens = tokenize(expression);

        int n=tokens.size();
        VEC3D dp(n, VEC2D(n, VEC1D()));
        vector<int> ans = solve(tokens, 0, n-1, dp);

        return ans;
    }
};