class Solution {
public:
    // T.C.=O(log(label)), S.C.=O(1)
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label >= 1)
        {
            ans.push_back(label);
            int level = floor(log2(label));
            // min and max vals in curr level
            int minVal = pow(2, level);
            int maxVal = 2*minVal - 1;

            label = (minVal + maxVal - label) / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
# if the values in each level were labelled from left to right:
  a node with value (i) would have left and right childs 
  with values (2*i) and (2*i+1) respectively and 
  a parent with value floor(i/2)

# level : [minVal, maxVal]
    0   : [2^0, 2^1 - 1]
    1   : [2^1, 2^2 - 1]
    2   : [2^2, 2^3 - 1]
    3   : [2^3, 2^4 - 1]
    .
    .
    .
    i   : [2^i, 2^(i+1) - 1]

*/