#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> parseInts(string s){
    stringstream ss(s);
    
    vector<int> nums;
    
    int num;
    char ch;
    
    while(ss){
        ss>>num>>ch;
        nums.push_back(num);
    }
    
    return nums;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    string s = "";
    cin>>s;
    
    vector<int> nums = parseInts(s);
    
    for(int num: nums)
        cout<<num<<endl;
      
    return 0;
}
