string Solution::solve(int A) {
    string fact="1";
    int carry, pro;
    for(int i=2; i<=A; i++)
    {
        string fact2="";
        carry=0;
        int n=fact.length();
        for(int j=n-1; j>=0; j--)
        {
            pro=(fact[j]-'0')*i+carry;
            carry=pro/10;
            pro=pro%10;
            fact2.insert(0,to_string(pro)); // add pro to thr front of the string "fact2"
        }
        if(carry>0) // final carry is generated from MSB
            fact2.insert(0,to_string(carry)); // add carry to thr front of the string "fact2"
        fact=fact2; // copy fact2 to fact
    }
    return fact;
}
