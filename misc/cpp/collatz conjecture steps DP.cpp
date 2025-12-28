#include <iostream>
#include <unordered_map>
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
	int sum=0, max_step=0, max_num;
	float avg;
	unordered_map<int,int> mp;
	for(int i=a; i<=b; i++)
	{
		int c=0, n=i;
		while(n!=1)
		{
			if(mp.find(n)!= mp.end()) // value is present in map
			{
				c=c+mp[n];
				break;
			}
			else // value is not present in map
			{
				c++;
				if(n%2==0) // even num.
					n=n/2;
				else // odd num.
					n=3*n+1;
			}
		}
		mp[i]=c; // insert value in map
		cout << "steps for " << i << "- " << c << endl;
		sum=sum+c;
		if(c>max_step)
		{
			max_step=c;
			max_num=i;
		}
	}
	avg=(float)sum/(b-a+1);
	cout << "avg. steps in range " << a << " to " << b << "- " << avg << endl;
	cout << "max steps- " << max_step << " first occuring for the number " << max_num << endl;
}

int main()
{
	int a=1, b=100;
	collatzConjecture(a,b);
	return 0;
}