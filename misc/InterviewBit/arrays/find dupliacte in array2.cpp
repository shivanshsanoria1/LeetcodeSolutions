int Solution::repeatedNumber(const vector<int> &A) { // T.C.=O(n) ; S.C.=O(1) ; similar to Floyd's cycle detection algo. in LL
    int slow=A[0], fast=A[0];
    while(1)
    {
        slow=A[slow]; // move slow by 1 step
        fast=A[A[fast]]; // move fast by 2 step
        if(slow==fast)
            break;
    }
    fast=A[0]; // reset fast at start
    while(slow!=fast) // to find the starting of the loop   
    {
        slow=A[slow]; // move slow by 1 step
        fast=A[fast]; // move slow by 1 step
    }
    return slow;
}
