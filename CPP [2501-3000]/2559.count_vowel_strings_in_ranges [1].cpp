class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { // T.C.=O(n + q), S.C.=O(n)
        int n=words.size();
        vector<int> prefix(n);
        prefix[0] = isVowel(words[0].front()) && isVowel(words[0].back()) ? 1 : 0;
        for(int i=1; i<n; i++)
        {
            if(isVowel(words[i].front()) && isVowel(words[i].back()))
                prefix[i] = 1 + prefix[i-1];
            else
                prefix[i] = prefix[i-1];
        }
        vector<int> ans;
        for(auto& qu: queries)
        {
            int left = qu[0], right = qu[1];
            int count = left - 1 >= 0 ? prefix[right] - prefix[left-1] : prefix[right];
            ans.push_back(count);
        }
        return ans;
    }
};