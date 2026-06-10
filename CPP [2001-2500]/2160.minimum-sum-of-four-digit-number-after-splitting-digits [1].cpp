class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        int new1 = 10 * (str[0] - '0') + (str[2] - '0');
        int new2 = 10 * (str[1] - '0') + (str[3] - '0');
        return new1 + new2;
    }
};