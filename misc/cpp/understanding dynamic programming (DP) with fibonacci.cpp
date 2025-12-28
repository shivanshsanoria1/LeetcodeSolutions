#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

// Recursion
// T.C.=O(2^n), S.C.=O(n)
int fib1(int n){
    if(n <= 1)
        return n;
    
    return fib1(n-1) + fib1(n-2);
}

// Memoization (Top-Down DP)
// T.C.=O(n), S.C.=O(n)
ulli fib2(int n, vector<ulli>& memo){    
    if(n <= 1)
        return n;

    // result already precalculated
    if(memo[n] != -1)
        return memo[n];
    
    // store the result in memo[]
    memo[n] = fib2(n-1, memo) + fib2(n-2, memo); 
    
    return memo[n];
}

// Tabulation (Bottom-Up DP)
// T.C.=O(n), S.C.=O(n)
ulli fib3(int n){
    vector<ulli> dp(n+1, -1);
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}

// Tabulation with Space-Optimization (Bottom-Up DP)
// T.C.=O(n), S.C.=O(1)
ulli fib4(int n){
    // 2nd previous element; acts as dp[i-2]
    ulli prev2 = 0;
    // 1st previous element; acts as dp[i-1]
    ulli prev1 = 1;
    
    for(int i=2; i<=n; i++)
    {
        // current element; acts as dp[i]
        ulli curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main(){
    int n = 25;
    
    // Method 1
    // int Fn = fib1(n);
    
    // Method 2
    vector<ulli> memo(n+1, -1);
    ulli Fn = fib2(n, memo);
    
    // Method 3
    // ulli Fn = fib3(n);
    
    // Method 4
    // ulli Fn = fib4(n);
    
    cout<<n<<"th Fibonacci-number = "<<Fn<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}

/*
# Fibonacci Numbers (0-indexed):
  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
# F(n) = F(n-1) + F(n-2) ; n >= 2
  F(0) = 0, F(1) = 1

# Methods 2, 3, 4 only work for n in range [0, 93] 
  due to the range of 'unsigned long long int' being
  [0, 18_446_744_073_709_551_615]

*/

/*
First 100 Fibonacci Numbers (0-indexed):

0. 0
1. 1
2. 1
3. 2
4. 3
5. 5
6. 8
7. 13
8. 21
9. 34
10. 55
11. 89
12. 144
13. 233
14. 377
15. 610
16. 987
17. 1597
18. 2584
19. 4181
20. 6765
21. 10946
22. 17711
23. 28657
24. 46368
25. 75025
26. 121393
27. 196418
28. 317811
29. 514229
30. 832040
31. 1346269
32. 2178309
33. 3524578
34. 5702887
35. 9227465
36. 14930352
37. 24157817
38. 39088169
39. 63245986
40. 102334155
41. 165580141
42. 267914296
43. 433494437
44. 701408733
45. 1134903170
46. 1836311903
47. 2971215073
48. 4807526976
49. 7778742049
50. 12586269025
51. 20365011074
52. 32951280099
53. 53316291173
54. 86267571272
55. 139583862445
56. 225851433717
57. 365435296162
58. 591286729879
59. 956722026041
60. 1548008755920
61. 2504730781961
62. 4052739537881
63. 6557470319842
64. 10610209857723
65. 17167680177565
66. 27777890035288
67. 44945570212853
68. 72723460248141
69. 117669030460994
70. 190392490709135
71. 308061521170129
72. 498454011879264
73. 806515533049393
74. 1304969544928657
75. 2111485077978050
76. 3416454622906707
77. 5527939700884757
78. 8944394323791464
79. 14472334024676221
80. 23416728348467685
81. 37889062373143906
82. 61305790721611591
83. 99194853094755497
84. 160500643816367088
85. 259695496911122585
86. 420196140727489673
87. 679891637638612258
88. 1100087778366101931
89. 1779979416004714189
90. 2880067194370816120
91. 4660046610375530309
92. 7540113804746346429
93. 12200160415121876738
94. 19740274219868223167
95. 31940434634990099905
96. 51680708854858323072
97. 83621143489848422977
98. 135301852344706746049
99. 218922995834555169026
100. 354224848179261915075

*/