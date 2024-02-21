class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { // T.C.=O(n*q), S.C.=O(1)
        vector<int> ans;
        for(auto qu: queries)
        {
            int left = qu[0], right = qu[1];
            int count = 0;
            for(int i=left; i<=right; i++)
                if(isVowel(words[i].front()) && isVowel(words[i].back()))
                    count++;
            ans.push_back(count);
        }
        return ans;
    }
};