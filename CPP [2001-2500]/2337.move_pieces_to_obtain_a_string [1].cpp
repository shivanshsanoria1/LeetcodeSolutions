class Solution {
private:
    typedef pair<char, int> PCI;

    // returns pairs of useful char ('L' or 'R')
    // and its index appearing in string 's'
    vector<PCI> findCharIndex(string& s){
        vector<PCI> chIdxs;
        for(int i=0; i<s.length(); i++)
            if(s[i] != '_')
                chIdxs.push_back({s[i], i});

        return chIdxs;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    bool canChange(string start, string target) {
        vector<PCI> chIdxs1 = findCharIndex(start);
        vector<PCI> chIdxs2 = findCharIndex(target);

        // unequal num of useful chars ('L' or 'R') 
        // in 'start' and 'target' strings
        if(chIdxs1.size() != chIdxs2.size())
            return false;

        for(int i=0; i<chIdxs1.size(); i++)
        {
            auto [ch1, idx1] = chIdxs1[i];
            auto [ch2, idx2] = chIdxs2[i];

            // char mismatch
            if(ch1 != ch2)
                return false;
            
            // each 'L' in 'start' string must appear 
            // at an index >= that in 'target' string
            if(ch1 == 'L' && idx1 < idx2)
                return false;

            // each 'R' in 'start' string must appear 
            // at an index <= that in 'target' string
            if(ch1 == 'R' && idx1 > idx2)
                return false;
        }

        return true;
    }
};