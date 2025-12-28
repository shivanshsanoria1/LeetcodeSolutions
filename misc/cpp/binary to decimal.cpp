#include <iostream>
using namespace std;

/*void bin_to_dec2(int n)
{
	int d,t=1,sum=0;
	while(n>0)
	{
		d=(n%10)*t;
		t=t*2;
		n=n/10;
		sum=sum+d;
	}
	cout << sum;
}*/

void bin_to_dec(string num)
{
	string n=num;
	int base=1,sum=0;
	int l= n.length();
	for(int i=l-1;i>=0;i--)
	{
		if(n[i]=='1')
			sum= sum+base;
		base=base*2;
	}
	cout << sum;
}

int main()
{
	string num="10101001";
	bin_to_dec(num);
	return 0;
}