#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void collatzConjecture(int a,int b)
{
	if(a<=0 || b<=0)
	{
		cout << "numbers must be positive" << endl;
		return;
	}
	if(a>b)
	{
		cout << "incorrect range" << endl;
		return;
	}
	unordered_map<int,int> mp;
	mp[1]=0;
	mp[2]=1;
	for(int i=a; i<=b; i++)
	{
		int n=i,count=0;
		vector<int> vec;
		while(n!=1)
		{
			if(mp.find(n) != mp.end())// n present in map
				break;
			else // n not present in map
			{
				vec.push_back(n); // push the n in vector (which are not present in map)
				if(n%2==0) // even num.
					n=n/2;
				else // odd num.
					n=3*n+1;
			}
		}
		int size=vec.size(),next;
		if(size>=1) // find next n of the last element of vector
		{
			if(vec[size-1]%2==0) // even num.
				next=vec[size-1]/2;
			else // odd num.
				next=3*vec[size-1]+1;
			for(int i=0; i<size; i++) // push the elements of vector in map
				mp[vec[i]]=size-i+mp[next];
		}
		cout << "steps for " << i << "- " << mp[i] << endl;
	}
}

int main()
{
	int a=1, b=100;
	collatzConjecture(a,b);
	return 0;
}
