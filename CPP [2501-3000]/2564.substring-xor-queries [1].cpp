class Solution {
private:
    string getBinaryStr(int num){
        if(num == 0)
            return "0";

        string s = "";
        while(num > 0)
        {
            s += to_string(num & 1);
            num = num >> 1;
        }

        reverse(s.begin(), s.end());
        return s;
    }

public:
    // T.C.=O(30*n + q*30), S.C.=O(30*n)
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        // substring (of len 1 to 30) of 's' -> index of 1st occurence in 's'
        unordered_map<string, int> mp;

        for(int len=1; len <= 30; len++)
            for(int i=0; i <= (int)s.length() - len; i++)
            {
                string sub = s.substr(i, len);
                if(mp.find(sub) == mp.end())
                    mp[sub] = i;
            }

        vector<vector<int>> ans;
        for(vector<int>& query: queries)
        {
            string bits = getBinaryStr(query[0] ^ query[1]);

            if(mp.find(bits) != mp.end())
                ans.push_back({mp[bits], mp[bits] + (int)bits.length() -1});
            else
                ans.push_back({-1, -1});
        }

        return ans;
    }
};
/*
# we need, val ^ query[0] = query[1]
  val ^ query[0] ^ query[0] = query[1] ^ query[0]
  val = query[0] ^ query[1]
  properties of XOR used: 
  A ^ A = 0
  A ^ 0 = A
  A ^ B = B ^ A
  (A ^ B) ^ C = A ^ (B ^ C)

# since each query[i] <= 10^9 
  (query[0] xor query[1]) <= 10^9 < 2^30 
  A ^ B has the same num of bits as max(A,B)
# 2^30 is the first num that needs 31 bits to be represented in binary
  so 10^9 requires 30 bits to be represented in binary
  thus the binary string 'bits' can have a max len of 30
*/