class Solution {
private:
    int findWordCount(string& s){
        int count = 0;
        for(char ch: s)
            if(ch == ' ')
                count++;
        return count + 1;
    }

public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp; // sender -> word count
        for(int i=0; i<messages.size(); i++)
            mp[senders[i]] += findWordCount(messages[i]);

        int maxWordCount = 0;
        string ans = "";
        for(auto& [sender, wordCount]: mp)
        {
            if(wordCount > maxWordCount)
            {
                maxWordCount = wordCount;
                ans = sender;
            }
            else if(wordCount == maxWordCount)
                ans = max(ans, sender);
        }
        return ans;
    }
};