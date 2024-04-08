class Solution {
private:
    bool sameFreq(vector<int>& freq1, vector<int>& freq2){
        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;
        return true;
    }

public:
    // T.C.=O(n2 + 26*n1), S.C.=O(2*26)
    // Sliding-window
    vector<int> findAnagrams(string s1, string s2) { 
        vector<int> ans;
        int n1=s1.length(), n2=s2.length();
        // s2 cannot be longer than s1
        if(n1 < n2) 
            return ans;

        // to store the freq of chars in s2
        vector<int> freq2(26, 0); 
        for(char ch: s2)
            freq2[ch - 'a']++;

        // to store the freq of chars in substring (of length n2) of s1
        vector<int> freq1(26,0); 
        for(int i=0; i<n2; i++)
            freq1[s1[i] - 'a']++;

        // check if freq of s2 and freq of curr substring of s1 match
        if(sameFreq(freq1, freq2)) 
            ans.push_back(0);

        int left = 0, right = n2;
        while(right < n1)
        {
            // decrement the freq of char at index 'left' of s1
            freq1[s1[left] - 'a']--; 
            // increment the freq of char at index 'right' of s1
            freq1[s1[right] - 'a']++; 

            left++;
            right++;

            // check if freq of s2 and freq of curr substring of s1 match
            if(sameFreq(freq1, freq2)) 
                ans.push_back(left);
        }

        return ans;
    }
};