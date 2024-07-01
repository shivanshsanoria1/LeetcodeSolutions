class Solution {
public:
    // T.C.=O(r + n*log(n)), S.C.=O(n)
    // r: size of roads[]
    // Greedy
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        for(vector<int>& road: roads)
        {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        // sort in decreasing order of degree
        sort(degrees.begin(), degrees.end(), greater<int>());

        long long int sum = 0;
        for(int degree: degrees)
        {
            sum += (long long int)degree * n;
            n--;
        }

        return sum;
    }
};