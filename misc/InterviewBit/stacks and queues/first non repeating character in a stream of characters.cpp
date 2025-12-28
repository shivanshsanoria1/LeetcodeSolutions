string Solution::solve(string s) {
    string ans="";
    vector<int> freq(26,0); //stores freq of each char
    queue<char> q;
    for(char ch: s)
    {
        freq[ch-'a']++; //update freq of curr char
        q.push(ch); //push curr char in queue
        while(!q.empty() && freq[q.front()-'a'] > 1) //keep popping from queue while freq of queue.front char > 1 and queue is not empty
            q.pop();
        if(q.empty())
            ans += '#';
        else
            ans += q.front();
    }
    return ans;
}
