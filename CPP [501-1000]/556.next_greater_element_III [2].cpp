class Solution {
public:
    int nextGreaterElement(int n) {
        string s= to_string(n); //convert n to string
        next_permutation(s.begin(),s.end()); //find next permutation of string s
        long int ans= stol(s); //convert the string back to long int
        return (ans > INT_MAX || ans <= n) ? -1 : ans; //return -1 if ans exceeds INT_MAX
    }
};