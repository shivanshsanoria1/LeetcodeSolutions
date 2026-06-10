class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) { // T.C.=O(n*logn), S.C.=O(n)
        int n=reward1.size();
        vector<pair<int, int>> diff(n); // {diff, index}
        for(int i=0; i<n; i++)
            diff[i] = {reward1[i] - reward2[i], i};
        // sort in decreasing order of differences
        sort(diff.begin(), diff.end(), greater<pair<int, int>>());
        int sum = 0;
        for(int i=0; i<k; i++) // mouse1 eats the 1st k cheese
            sum += reward1[diff[i].second];
        for(int i=k; i<n; i++) // mouse2 eats the remaining cheese
            sum += reward2[diff[i].second];
        return sum;
    }
};