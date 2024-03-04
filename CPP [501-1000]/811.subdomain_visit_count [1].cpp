class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // domain -> num of visits
        unordered_map<string, int> mp;
        for(string& cpdomain: cpdomains)
        {
            vector<string> words;
            string word = "";
            for(char ch: cpdomain)
            {
                if(ch == ' ' || ch == '.')
                {
                    words.push_back(word);
                    word = "";
                }
                else
                    word += ch;
            }

            int count = stoi(words[0]);
            string d1 = words[1];
            string d2 = words.size() == 2 ? word : words[2];
            string d3 = words.size() == 3 ? word : "";
            
            if(d3 == "") // d3 does not exist
            {
                mp[d1 + "." + d2] += count;
                mp[d2] += count;
            }
            else // d3 exists
            {
                mp[d1 + "." + d2 + "." + d3] += count;
                mp[d2 + "." + d3] += count;
                mp[d3] += count;
            }
        }

        vector<string> ans;
        for(auto [domain, freq]: mp)
            ans.push_back(to_string(freq) + " " + domain);
        return ans;
    }
};