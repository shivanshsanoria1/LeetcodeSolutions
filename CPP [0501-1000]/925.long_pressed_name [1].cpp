class Solution {
private:
    typedef pair<char, int> PCI;

    vector<PCI> consecutiveCharFreq(string& s){
        vector<PCI> pairs;
        char prev = ' ';
        int freq = 0;

        for(char curr: s)
        {
            if(curr == prev)
                freq++;
            else
            {
                if(prev != ' ')
                    pairs.push_back({prev, freq});
                prev = curr;
                freq = 1;
            }
        }

        pairs.push_back({prev, freq});

        return pairs;
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length())
            return false;
            
        vector<PCI> v1 = consecutiveCharFreq(name);
        vector<PCI> v2 = consecutiveCharFreq(typed);

        if(v1.size() != v2.size())
            return false;
        
        for(int i=0; i<v1.size(); i++)
        {
            auto [ch1, freq1] = v1[i];
            auto [ch2, freq2] = v2[i];

            if(ch1 != ch2 || freq1 > freq2)
                return false;
        }

        return true;
    }
};