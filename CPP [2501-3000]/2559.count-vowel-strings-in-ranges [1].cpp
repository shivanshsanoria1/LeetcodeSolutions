class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) { 
        int n = words.size();
        vector<int> prefixCount(n);
        prefixCount[0] = isVowel(words[0][0]) && isVowel(words[0].back()) ? 1 : 0;

        for(int i=1; i<n; i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
                prefixCount[i] = 1 + prefixCount[i-1];
            else
                prefixCount[i] = prefixCount[i-1];
        }

        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0], right = query[1];
            int count = left - 1 >= 0 ? prefixCount[right] - prefixCount[left-1] : prefixCount[right];

            ans.push_back(count);
        }

        return ans;
    }
};