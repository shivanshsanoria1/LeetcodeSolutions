class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(1)
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n1 = num1.length(), n2 = num2.length();
        int carry = 0;
        string num = "";

        for(int i=0, j=0; i < n1 || j < n2; i++, j++)
        {
            int d1 = i < n1 ? num1[i] - '0' : 0;
            int d2 = j < n2 ? num2[j] - '0' : 0;

            int sum = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;

            num += to_string(sum);
        }

        // final carry is generated from MSB
        if(carry == 1)
            num += "1";
        
        reverse(num.begin(), num.end());

        return num;
    }
};

// similar: [67. add-binary]