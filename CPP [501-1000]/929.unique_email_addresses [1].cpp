class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string& email: emails)
        {
            int idx = email.find('@');

            string local = "";
            for(int i=0; i<idx; i++)
            {
                if(email[i] == '+')
                    break;
                else if(email[i] == '.')
                    continue;
                else
                    local += email[i];
            }

            string domain = email.substr(idx + 1);
            
            s.insert(local + "@" + domain);
        }
        return s.size();
    }
};