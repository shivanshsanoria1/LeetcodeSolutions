class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> plusOne(vector<int>& digits) {
        vector<int> digits1;
        int carry = 1;

        for(int i=digits.size()-1; i>=0; i--)
        {
            int sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;

            digits1.push_back(sum);
        }

        // final carry is generated from MSB
        if(carry == 1)
            digits1.push_back(1);

        reverse(digits1.begin(), digits1.end());

        return digits1;
    }
};