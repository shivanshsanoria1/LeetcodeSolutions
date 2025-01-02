class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

public:
    // T.C.=O(n*q), S.C.=O(1)
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { 
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0], right = query[1];
            int count = 0;

            for(int i=left; i<=right; i++)
                if(isVowel(words[i][0]) && isVowel(words[i].back()))
                    count++;

            ans.push_back(count);
        }

        return ans;
    }
};