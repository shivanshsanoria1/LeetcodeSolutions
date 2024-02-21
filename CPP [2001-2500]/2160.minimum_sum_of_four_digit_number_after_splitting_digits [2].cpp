class Solution {
public:
    int minimumSum(int num) {
        vector<int> digs;
        while(num > 0)
        {
            digs.push_back(num % 10);
            num /= 10;
        }
        sort(digs.begin(), digs.end());
        int new1 = 10 * digs[0] + digs[2];
        int new2 = 10 * digs[1] + digs[3];
        return new1 + new2;
    }
};