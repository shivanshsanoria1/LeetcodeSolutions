class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string(n); //convert n to string
        int i=s.length()-2; //start i from 2nd last digit
        while(i>=0 && s[i] >= s[i+1]) //decrement i until a digit smaller than its prev digit is found
            i--;
        if(i < 0) //digits in n are in decreasing order
            return -1;
        int j=s.length()-1; //start j from last digit
        while(s[i] >= s[j]) //find the rightmost smaller digit than s[i]
            j--;
        swap(s[i],s[j]); //swap digits at i and j
        reverse(s.begin()+i+1,s.end()); //reverse the digits from (i+1) till end
        long int ans= stol(s); //convert the string back to long int
        return ans > INT_MAX ? -1 : ans; //return -1 if ans exceeds INT_MAX
    }
};