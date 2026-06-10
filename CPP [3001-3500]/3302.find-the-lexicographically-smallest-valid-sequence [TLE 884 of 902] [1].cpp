class Solution {
private:
    // returns true if nums2[] is Lexicographically smaller than nums1[]
    bool isLexicoSmaller(vector<int>& nums1, vector<int>& nums2){
        // both nums1[] and nums2[] are of same size
        int n=nums1.size();
        for(int i=0; i<n; i++)
        {
            if(nums1[i] < nums2[i])
                return false;
            else if(nums1[i] > nums2[i])
                return true;
        }

        return false;
    }

public:
    // T.C.=O(n2 * (n1 + n2)), S.C.=O(n2)
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<int> ans;

        for(int w=0; w<n2; w++) // wildcard-index
        {
            int i = 0, j = 0;
            vector<int> temp;
            
            while(i < n1 && j < n2)
            {
                if(j == w || word1[i] == word2[j])
                {
                    temp.push_back(i);
                    j++;
                }
                i++;
            }

            if(j == n2 && (ans.empty() || isLexicoSmaller(ans, temp)))
                ans = temp;
        }

        return ans;
    }
};

// char at wildcard-index 'w' in word2 can be matched with any char in word1