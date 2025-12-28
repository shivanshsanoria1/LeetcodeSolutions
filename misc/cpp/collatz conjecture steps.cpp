#include <iostream>
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
	int sum=0, max_steps=0, max_num;
	float avg;
	for(int i=a; i<=b; i++)
	{
		int c=0, n=i;
		while(n!=1)
		{
			c++;
			if(n%2==0) // even num.
				n=n/2;
			else // odd num.
				n=3*n+1;
		}
		cout << "steps for " << i << "- " << c << endl;
		sum=sum+c;
		if(c>max_steps)
		{
			max_steps=c;
			max_num=i;
		}
	}
	avg=(float)sum/(b-a+1);
	cout << "avg. steps in range " << a << " to " << b << "- " << avg << endl;
	cout << "max steps- " << max_steps << " first occuring for the number " << max_num << endl;
}

int main()
{
	int a=1, b=10;
	collatzConjecture(a,b);
	return 0;
}