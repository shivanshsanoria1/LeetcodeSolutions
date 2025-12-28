int dayNum(string &s)
{
    if(s=="Monday")
        return 0;
    else if(s=="Tuesday")
        return 1;
    else if(s=="Wednesday")
        return 2;
    else if(s=="Thursday")
        return 3;
    else if(s=="Friday")
        return 4;
    else if(s=="Saturday")
        return 5;
    return 6;
}

int Solution::solve(string s, int n) {
    int ans=n/7; //n days have n/7 complete weeks, ie, n/7 sundays
    int rem_days= n%7; //n%7 days in the incomplete week
    int start_day= dayNum(s);
    return start_day + rem_days >= 7 ? ans+1: ans;
}
