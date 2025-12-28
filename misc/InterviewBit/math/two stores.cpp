int Solution::solve(int cand, int cand1, int cost1, int cand2, int cost2) {
    int min_cost=INT_MAX;
    for(int x=0; x*cand1 <= cand ; x++) //x bags of cand1, y bags of cand2
    {
        if((cand-x*cand1)%cand2 == 0)
        {
            int y=(cand-x*cand1)/cand2;
            min_cost= min(min_cost, x*cost1 + y*cost2);
        }
    }
    return min_cost==INT_MAX ? -1 : min_cost;
}
