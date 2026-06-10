class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1); // initialize vector with all 1's
        for(int i=1; i<rowIndex; i++) // i represents column
        {
            for(int j=i; j>=1; j--) // j represents row (generated from Right to Left)
                result[j] = result[j] + result[j-1];
        }
        return result;
    }
};