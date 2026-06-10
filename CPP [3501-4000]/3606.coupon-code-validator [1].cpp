class Solution {
private:
    bool isValidCode(string& s){
        if(s.length() == 0)
            return false;

        for(char ch: s)
        {
            if(ch >= 'a' && ch <= 'z')
                continue;
            if(ch >= 'A' && ch <= 'Z')
                continue;
            if(ch >= '0' && ch <= '9')
                continue;
            if(ch == '_')
                continue;

            return false;
        }

        return true;
    }

    bool isValidBusinessLine(string& s){
        return s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant";
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // {code[i], businessLine[i]}
        vector<pair<string, string>> temp;

        for(int i=0; i<code.size(); i++)
        {
            if(!isActive[i])
                continue;
            if(!isValidCode(code[i]))
                continue;
            if(!isValidBusinessLine(businessLine[i]))
                continue;

            temp.push_back({code[i], businessLine[i]});
        }
        
        sort(temp.begin(), temp.end(), [](pair<string, string>& a, pair<string, string>& b){
            auto [code_a, businessLine_a] = a;
            auto [code_b, businessLine_b] = b;

            return businessLine_a == businessLine_b ? code_a < code_b : businessLine_a < businessLine_b;
        });

        vector<string> ans;
        for(auto [code, businessLine]: temp)
            ans.push_back(code);

        return ans;
    }
};