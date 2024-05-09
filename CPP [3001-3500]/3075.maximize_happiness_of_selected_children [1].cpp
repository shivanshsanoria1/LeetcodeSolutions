class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort in decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long int sum = 0;

        for(int i=0; i<k && happiness[i] - i >= 0; i++)
            sum += happiness[i] - i;

        return sum;
    }
};