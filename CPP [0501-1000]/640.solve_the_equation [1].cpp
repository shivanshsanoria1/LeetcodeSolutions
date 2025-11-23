class Solution {
private:
    stack<string> tokenize(string& s){
        stack<string> tokens;
        string token = "";
        // to extract the last token
        s += "+"; 

        for(char ch: s)
        {
            if(ch == 'x' || ch == '+' || ch == '-')
            {
                // push the prev token and then clear it
                if(token != "")
                    tokens.push(token);
                token = "";

                // push the curr token and then clear it
                token += ch;
                tokens.push(token);
                token = "";
            }
            else // ch == digit
                token += ch;
        }

        // restore back the string
        s.pop_back(); 
        // remove the last '+' added at the starting
        tokens.pop(); 

        return tokens;
    }

    pair<int, int> getCoeffs(stack<string>& st){
        int coeff_x = 0, val = 0;

        while(!st.empty())
        {
            string curr = st.top();
            st.pop();

            if(curr == "x")
            {
                // nothing before 'x'
                if(st.empty())
                    coeff_x++;
                else
                {
                    string curr2 = st.top();
                    st.pop();

                    // '+' before 'x'
                    if(curr2 == "+")
                        coeff_x++;
                    // '-' before 'x'
                    else if(curr2 == "-")
                        coeff_x--;
                    else // num before 'x'
                    {
                        // sign of the num that is before 'x'
                        int sign = 1;
                        if(!st.empty())
                        {
                            if(st.top() == "-")
                                sign = -1;
                            st.pop();
                        }

                        coeff_x += sign * stoi(curr2); 
                    }
                }
            }
            else // num
            {
                // sign of the curr num
                int sign = 1;
                if(!st.empty())
                {
                    if(st.top() == "-")
                        sign = -1;
                    st.pop();
                }

                val += sign * stoi(curr);
            }
        }

        return {coeff_x, val};
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string solveEquation(string equation) {
        int idx = equation.find('=');
        // left hand side of equation
        string lhs = equation.substr(0, idx);
        // right hand side of equation
        string rhs = equation.substr(idx + 1);

        stack<string> lhs_st = tokenize(lhs);
        auto [lhs_coeff_x, lhs_val] = getCoeffs(lhs_st);

        stack<string> rhs_st = tokenize(rhs);
        auto [rhs_coeff_x, rhs_val] = getCoeffs(rhs_st);

        int coeff_x = lhs_coeff_x - rhs_coeff_x;
        int val = rhs_val - lhs_val;

        if(coeff_x == 0)
            return val == 0 ? "Infinite solutions" : "No solution";

        return "x=" + to_string(val / coeff_x);
    }
};