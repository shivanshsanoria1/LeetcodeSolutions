class Solution {
private:
    bool isVowel(const char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

public:
    // T.C.=O(n + 5), S.C.=O(5)
    string sortVowels(string s) {
        // vowel -> freq
        unordered_map<char, int> mpFreq;
        // vowel -> index of 1st occurence
        unordered_map<char, int> mpIdx;

        for(int i=0; i<s.length(); i++){
            if(!isVowel(s[i]))
                continue;
            
            mpFreq[s[i]]++;

            if(mpIdx.find(s[i]) == mpIdx.end())
                mpIdx[s[i]] = i;
        }

        vector<pair<char, int>> vowels;
        for(const auto [vowel, freq]: mpFreq)
            vowels.push_back({vowel, freq});
        
        // sort vowels in decreasing order of freq, 
        // if freq are same then sort in increasing order of index of 1st occurence
        sort(vowels.begin(), vowels.end(), [&mpIdx, &mpFreq](const pair<char, int>& a, const pair<char, int>& b){
            return a.second == b.second ? mpIdx[a.first] < mpIdx[b.first] : a.second > b.second;
        });

        int i=0;
        for(char& ch: s){
            if(!isVowel(ch))
                continue;
            
            ch = vowels[i].first;
            if(--vowels[i].second == 0)
                i++;
        }

        return s;
    }
};