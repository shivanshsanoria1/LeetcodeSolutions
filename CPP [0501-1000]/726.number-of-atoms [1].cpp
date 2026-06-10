class Solution {
private:
    vector<string> tokenize(string& formula){
        int n=formula.size();
        vector<string> tokens;

        for(int i=0; i<n;)
        {
            if(isupper(formula[i]))
            {
                string element = "";
                element += formula[i];
                if(i+1 < n && islower(formula[i+1]))
                {
                    element += formula[i+1];
                    i++;
                }
                tokens.push_back(element);
                i++;
            }
            else if(isdigit(formula[i]))
            {
                string count = "";
                while(i < n && isdigit(formula[i]))
                {
                    count += formula[i];
                    i++;
                }
                tokens.push_back(count);
            }
            else // formula[i] == '(' or ')'
            {
                string temp = "";
                temp += formula[i];
                tokens.push_back(temp);
                i++;
            }
        }

        return tokens;
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    string countOfAtoms(string formula) {
        int n=formula.size();
        // tokenize the 'formula' string, so that each 
        // element, number, '(', ')' can be accessed easily
        vector<string> tokens = tokenize(formula);
        int t=tokens.size();

        // element -> freq
        unordered_map<string, int> mp;
        stack<unordered_map<string, int>> st;

        for(int i=0; i<t; i++)
        {   
            if(isupper(tokens[i][0])) // tokens[i] is an element
            {
                // add the element and its freq in map
                int freq = i+1 < t && isdigit(tokens[i+1][0]) ? stoi(tokens[i+1]) : 1;
                mp[tokens[i]] += freq;
            }
            else if(tokens[i] == "(")
            {
                st.push(mp);
                mp.clear();
            }
            else if(tokens[i] == ")")
            {
                // multiplier for the curr pair of parenthesis
                int mul = i+1 < t && isdigit(tokens[i+1][0]) ? stoi(tokens[i+1]) : 1;

                // multiply the freq of each element in the curr map by multiplier and 
                // add them to the freq of the same elements in the map at stack-top
                for(auto [element, freq]: mp)
                    st.top()[element] += freq * mul;

                // replace the curr map with the map at stack-top
                mp = st.top();
                st.pop();
            }
        }

        // create a sorted version of the curr map
        map<string, int> sorted_mp;
        for(auto [element, freq]: mp)
            sorted_mp[element] = freq;
        
        // empty the sorted-map into the 'ans' string
        string ans = "";
        for(auto [element, freq]: sorted_mp)
        {
            ans += element;
            if(freq > 1)
                ans += to_string(freq);
        }

        return ans;
    }
};
// an element can only be of 1 or 2 chars in length
// Eg: 1 char: H, O, N, C
// Eg: 2 char: He, Mg, Si