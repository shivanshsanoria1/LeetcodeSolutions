class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(1)
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n1 = a.length(), n2 = b.length();
        int carry = 0;
        string s = "";

        for(int i=0, j=0; i < n1 || j < n2; i++, j++)
        {
            int d1 = i < n1 && a[i] == '1' ? 1 : 0;
            int d2 = j < n2 && b[j] == '1' ? 1 : 0;

            int sum = (d1 + d2 + carry) % 2;
            carry = (d1 + d2 + carry) / 2;

            s += to_string(sum);
        }

        // final carry is generated from MSB
        if(carry == 1)
            s += "1";
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};

// similar: [415. add-strings]