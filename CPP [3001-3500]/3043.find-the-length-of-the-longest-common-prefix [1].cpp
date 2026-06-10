class Solution {
public:
    // T.C.=O(n1*d + n2*d), S.C.=O(min(n1, n2)*d)
    // d: max count of digits in a num (limited to 9 here)
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() < arr2.size())
            swap(arr1, arr2);

        unordered_set<int> prefixes2;
        for(int num2: arr2)
        {
            string s2 = to_string(num2);

            for(int len = 1; len <= s2.length(); len++)
                prefixes2.insert(stoi(s2.substr(0, len)));
        }

        int lcp = 0;
        for(int num1: arr1)
        {
            string s1 = to_string(num1);

            for(int len = s1.length(); len >= 1; len--)
                if(prefixes2.find(stoi(s1.substr(0, len))) != prefixes2.end())
                {
                    lcp = max(lcp, len);
                    break;
                }
        }
        
        return lcp;
    }
};