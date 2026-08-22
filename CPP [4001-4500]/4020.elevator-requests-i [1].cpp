class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int elevatorRequests(int n, vector<int>& requests) {
        int sum = requests[0];
        for(int i=1; i<requests.size(); i++)
            sum += abs(requests[i-1] - requests[i]);

        return sum;
    }
};