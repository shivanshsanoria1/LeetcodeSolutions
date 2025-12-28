int Solution::solve(int r, int c) {
    int top_left= min(r-1,c-1);
    int top_right= min(r-1,8-c);
    int bottom_left= min(8-r,c-1);
    int bottom_right= min(8-r,8-c);
    return top_left + top_right + bottom_left + bottom_right;
}
