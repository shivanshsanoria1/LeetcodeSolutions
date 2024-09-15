class Solution {
public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefixXors(n);

        prefixXors[0] = arr[0];
        for(int i=1; i<n; i++)
            prefixXors[i] = arr[i] ^ prefixXors[i-1];
        
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0];
            int right = query[1];

            if(left - 1 >= 0)
                ans.push_back(prefixXors[right] ^ prefixXors[left - 1]);
            else
                ans.push_back(prefixXors[right]);
        }

        return ans;
    }
};

/*
# prefixXors[right] = A0 ^ A1 ^ A2 ^ ... ^ A(left-1) ^ A(left) ^ ... ^ A(right)
# prefixXors[left-1] = A0 ^ A1 ^ A2 ^ ... ^ A(left-1)
# prefixXors[right] ^ prefixXors[left-1] = A(left) ^ ... ^ A(right)
  since, all the nums in index-range [0, left-1] 
  will be XORed twice and thus will become 0
  and using the property of xor: A ^ 0 = A

# more specificaly:
  prefixXors[right] ^ prefixXors[left-1]
  = {A0 ^ A1 ^ A2 ^ ... ^ A(left-1)} ^ {A(left) ^ ... ^ A(right)} ^ {A0 ^ A1 ^ A2 ^ ... ^ A(left-1)}
  = {A0^A0 ^ A1^A1 ^ A2^A2 ^ ... ^ A(left-1)^A(left-1)} ^ {A(left) ^ ... ^ A(right)}
  = {0 ^ 0 ^ 0 ^ ... ^ 0} ^ {A(left) ^ ... ^ A(right)}
  = 0 ^ {A(left) ^ ... ^ A(right)}
  = A(left) ^ ... ^ A(right)
*/