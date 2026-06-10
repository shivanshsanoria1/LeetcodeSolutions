class Solution {
public:
    int solve(vector<string>& arr, int i, vector<int>& freq){
        if(i == arr.size())
            return 0;
        // exclude the string arr[i]
        int exclude = solve(arr, i+1, freq);
        bool canInclude = true;
        // add the freq of chars in arr[i]
        for(char ch: arr[i])
        {
            if(freq[ch - 'a'] > 0) // already seen char
                canInclude = false;
            freq[ch - 'a']++;
        }
        // only include the string arr[i] if all of its chars are had freq = 0
        int include = canInclude ? arr[i].length() + solve(arr, i+1, freq) : 0;
        // remove the freq of chars in arr[i]
        for(char ch: arr[i])
            freq[ch - 'a']--;
        
        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        vector<int> freq(26, 0);
        return solve(arr, 0, freq);
    }
};