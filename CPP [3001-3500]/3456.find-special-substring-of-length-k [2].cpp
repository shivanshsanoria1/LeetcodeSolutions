class Solution {
private:
    // return true if the window is surrounded by chars
    // which are different from the ones inside the window 
    bool checkCharOnWindowSides(string& s, int left, int right){
        if(left - 1 >= 0 && s[left - 1] == s[left])
            return false;
        
        if(right + 1 < s.length() && s[right] == s[right + 1])
            return false;

        return true;
    }

    // returns true if there are exactly k same chars in the window
    bool isWindowMadeOfSingleChar(vector<int>& freq, int k){
        for(int i=0; i<26; i++)
            if(freq[i] == k)
                return true;

        return false;
    }

public:
    // T.C.=O(n*26), S.C.=O(26)
    // fixed length sliding-window
    bool hasSpecialSubstring(string s, int k) {
        vector<int> freq(26, 0);
        for(int i=0; i<k; i++)
            freq[s[i] - 'a']++;
        
        int n = s.length();
        int left = 0, right = k-1;

        while(right < n)
        {
            if(checkCharOnWindowSides(s, left, right) && isWindowMadeOfSingleChar(freq, k))
                return true;
            
            if(right + 1 < n)
                freq[s[right + 1] - 'a']++;
            freq[s[left] - 'a']--;

            left++;
            right++;
        }

        return false;
    }
};