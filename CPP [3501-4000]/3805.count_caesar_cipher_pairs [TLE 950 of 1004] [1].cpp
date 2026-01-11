class Solution {
private:
    bool areSimilar(const string& s1, const string& s2){
        int diff = (s1[0] - s2[0] + 26) % 26;
        for(int i=1; i<s1.length(); i++)
            if((s1[i] - s2[i] + 26) % 26 != diff)
                return false;

        return true;
    }

public:
    // T.C.=O(n^2*m), S.C.=O(1)
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        long long int count = 0;
        
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(areSimilar(words[i], words[j]))
                    count++;

        return count;
    }
};