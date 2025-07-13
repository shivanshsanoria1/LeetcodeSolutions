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

    bool isValidBusinessLine(string& s, vector<string>& validBusinessLines){
        for(string& validBusinessLine: validBusinessLines)
            if(s == validBusinessLine)
                return true;
        
        return false;
    }

    int convertBusinessLineToInt(string& s, vector<string>& validBusinessLines){
        for(int i=0; i<validBusinessLines.size(); i++)
            if(s == validBusinessLines[i])
                return i;
        
        return -1;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> idxs;
        vector<string> validBusinessLines = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(int i=0; i<code.size(); i++)
        {
            if(!isActive[i])
                continue;
            if(!isValidCode(code[i]))
                continue;
            if(!isValidBusinessLine(businessLine[i], validBusinessLines))
                continue;

            idxs.push_back(i);
        }
        
        sort(idxs.begin(), idxs.end(), [&](int& i, int& j){
            return businessLine[i] == businessLine[j] ? code[i] < code[j] : convertBusinessLineToInt(businessLine[i], validBusinessLines) < convertBusinessLineToInt(businessLine[j], validBusinessLines);
        });

        vector<string> ans;
        for(int idx: idxs)
            ans.push_back(code[idx]);

        return ans;
    }
};