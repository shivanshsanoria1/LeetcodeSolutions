class Solution {
private:
    // splits the string s into an array of strings based on the delimiter
    vector<string> tokenize(string& s, char delimiter){
        vector<string> tokens;
        string token = "";
        s += delimiter;

        for(char ch: s)
        {
            if(ch == delimiter)
            {
                tokens.push_back(token);
                token = "";
            }
            else
                token += ch;
        }

        s.pop_back();

        return tokens;
    }

    bool isHexadecimal(char ch){
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
    }

    bool isValidIPv4(string& ip){
        vector<string> tokens = tokenize(ip, '.');

        if(tokens.size() != 4)
            return false;
        
        for(string& token: tokens)
        {
            if(!(token.length() >= 1 && token.length() <= 3))
                return false;
            // leading zero(s)
            if(token[0] == '0' && token.length() > 1)
                return false;

            int num = 0;
            for(char ch: token)
            {
                if(!isdigit(ch))
                    return false;

                num *= 10;
                num += ch - '0';
            }

            if(num > 255)
                return false;
        }

        return true;
    }
    
    bool isValidIPv6(string& ip){
        vector<string> tokens = tokenize(ip, ':');

        if(tokens.size() != 8)
            return false;

        for(string& token: tokens)
        {
            if(!(token.length() >= 1 && token.length() <= 4))
                return false;

            for(char ch: token)
                if(!isHexadecimal(ch))
                    return false;
        }

        return true;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string validIPAddress(string queryIP) {
        if(isValidIPv4(queryIP))
            return "IPv4";
        if(isValidIPv6(queryIP))
            return "IPv6";
        
        return "Neither";
    }
};