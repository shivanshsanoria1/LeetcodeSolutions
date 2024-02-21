class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1; i>=0; i--)
        {
            if(digits[i]<9) // if digit is from 0-8
            {
                digits[i]++;  
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1); // if carry is generated
        return digits;
    }
};