class Solution {
private:
    vector<string> tokenize(string& s){
        vector<string> tokens;
        string token = "";

        // append a leading +ive sign if no sign is present
        if(s[0] != '+' && s[0] != '-')
            tokens.push_back("+");
        // terminating delimiter
        s += "+";

        for(char ch: s)
        {
            if(ch == '+' || ch == '-')
            {
                if(token != "")
                    tokens.push_back(token);
                token = "";
                token += ch;
                tokens.push_back(token);
                token = "";
            }
            else
                token += ch;
        }

        s.pop_back();
        tokens.pop_back();

        return tokens;
    }

    pair<int, int> getNumAndDemo(string fraction){
        int idx = fraction.find('/');
        int n = stoi(fraction.substr(0, idx));
        int d = stoi(fraction.substr(idx + 1));

        return {n, d};
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string fractionAddition(string expression) {
        vector<string> tokens = tokenize(expression);

        int n1 = 0, d1 = 1;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-")
                continue;

            auto [n2, d2] = getNumAndDemo(tokens[i+1]);

            int lc = lcm(d1, d2);

            if(tokens[i] == "+")
                n1 = n1*(lc/d1) +  n2*(lc/d2);
            else // tokens[i] == "-"
                n1 = n1*(lc/d1) -  n2*(lc/d2);

            int sign = n1 < 0 ? -1 : 1;
            n1 = abs(n1);
            d1 = lc;

            int gc = __gcd(n1, d1);
            n1 *= sign;
            n1 /= gc;
            d1 /= gc;
        }

        return to_string(n1) + "/" + to_string(d1);
    }
};

/*
# for the addition or subtraction of 2 fractions n1/d1 and n2/d2:
  (n1/d1) +- (n2/d2) = (n1*(lc/d1) +- n2*(lc/d2)) / lc = n/d
  where lc = lcm(d1, d2)
# to reduce a fraction n/d to its irreducible form:
  n/d = (n/gc) / (d/gc)
  where gc = gcd(n, d)
*/