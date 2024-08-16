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
    // T.C.=O(q*(n + 30)), S.C.=O(30)
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;

        for(vector<int>& query: queries)
        {
            string bits = getBinaryStr(query[0] ^ query[1]);

            size_t found = s.find(bits);
            if(found == string::npos)
                ans.push_back({-1, -1});
            else
                ans.push_back({(int)found, (int)found + (int)bits.length() - 1});

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