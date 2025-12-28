#include <bits/stdc++.h>
using namespace std;

int digital_root(string n)
{
	int sum=0;
	for(int i=0; i<n.length(); i++) // digit sum of n
		sum= sum+ n[i]-'0';
	if(sum==0)
		return 0;
	if(sum%9==0)
		return 9;
	return sum%9;
}

int main()
{
	string num="65785412";
	cout << digital_root(num) << endl;
	return 0;
}