class Solution {
public:
    // T.C.=O(d), S.C.=O(d)
    // d: max num of digits in num, (limited to 9 here)
    // Greedy
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        vector<int> postfixMax(n, -1);
        for(int i=n-2; i>=0; i--)
        {
            if(postfixMax[i+1] == -1 || s[i+1] > s[postfixMax[i+1]])
                postfixMax[i] = i+1;
            else
                postfixMax[i] = postfixMax[i+1];
        }
        
        for(int i=0; i<n-1; i++)
            if(postfixMax[i] != -1 && s[i] < s[postfixMax[i]])
            {
                swap(s[i], s[postfixMax[i]]);
                break;
            }

        return stoi(s);
    }
};

// postfixMax[i]: rightmost index of the max-char in index-range [i+1, n-1] 
// or -1 if there are no chars to the right of index i