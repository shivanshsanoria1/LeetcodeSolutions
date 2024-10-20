class Solution {
private:
    string invert(string& s){
        string inverted = "";
        for(char ch: s)
            inverted += ch == '1' ? "0" : "1";
        
        return inverted;
    }

    string generate(int n){
        if(n == 1)
            return "0";

        string prev = generate(n-1);
        string inverted = invert(prev);
        reverse(inverted.begin(), inverted.end());

        return prev + "1" + inverted;
    }

public:
    // T.C.=O(2^n), S.C.=O(2^n)
    char findKthBit(int n, int k) {
        return generate(n)[k-1];
    }
};