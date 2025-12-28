string Solution::solve(int m) {
    if(m>12)
        return "Invalid";
    if(m>=3 && m<=5)
        return "Spring";
    if(m>=6 && m<=8)
        return "Summer";
    if(m>=9 && m<=11)
        return "Autumn";
    return "Winter";
}    
