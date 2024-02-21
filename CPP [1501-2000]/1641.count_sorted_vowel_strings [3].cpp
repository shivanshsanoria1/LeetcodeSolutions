class Solution {
public:
    int countVowelStrings(int n) { //T.C.=O(1) , S.C.=(1) , math soln.
        return ((n+4)*(n+3)*(n+2)*(n+1))/24;
    }
};
// nCr = (n+r-1)! / (r!*(n-1)!) , Combinations with Repetitions Formula
// n : total number of elements in a set , r : number of elements that can be selected from a set
// in this problem, total number of elements in a set = 5, number of elements that can be selected from a set = n, ie, n=5 and r=n
// 5Cn = (5+n-1)! / (n!*(5-1)!)
//     = (n+4)! / (n!*4!)
//     = ((n+4)*(n+3)*(n+2)*(n+1)) / 24