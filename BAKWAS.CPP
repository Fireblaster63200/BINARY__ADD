#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#define max 20
class binary
{
	void conversion()
	{
		int i=0,j;
		while(num != 0)
		{
			b[i++] = num%2;
			num = num/2;
			n++;
		}
		for(i=0,j=n-1;i<n;i++,j--)
			a[i] = b[j];
	}
	public:
	int num,a[max],b[max],carry;
	static int n;
	void display()
	{
		int i;
		conversion();
		cout<<"n\The conversion is: ";
		for(i=0;i<n;i++)
			cout<<" "<<a[i];
		onesComp();
		cout<<"\nThe conversion is: ";
		for(i=0;i<n;i++)
			cout<<" "<<a[i];
		twosComp();
		cout<<"\nThe conversion is: ";
		for(i=0;i<n;i++)
			cout<<" "<<a[i];
	}
	void onesComp()
	{
		int i,j;
		for(i=0;i<n;i++)
			a[i] = !a[i];
	}
	void twosComp()
	{
		int i;
		onesComp();
		for(i=n-1;i>=0;i--)
		{
			if(a[i] == 1)
				break;
		}
		i--;
		for(;i>=0;i--)
			a[i] = !a[i];
	}
	binary addition(binary e)
	{
		int i,j;
		binary d;
		conversion();
		e.conversion();
		for(i=0;i<n;i++)
		{
			if(e.a[i] == a[i] == 1 && d.carry != 1)
			{
				d.carry = 1;
				d.a[i] = 0;
			}
			else
			{
				if(e.a[i] == d.carry == 1)
				{
					d.carry = 1;
					a[i] = 0;
				}
				else if(a[i] == d.carry == 1)
				{
					d.carry = 1;
					a[i] = 0;
				}
				else
					d.carry = 0;
				d.a[i] = e.a[i] + a[i];
				return d;
			}
		}
	}
	binary()
	{
		carry = 0;
	}
};
int binary::n = 0;
void main()
{
	int i;
	binary b,c,d;
	clrscr();
	cout<<"\nEnter a number: ";
	cin>>b.num;
	cout<<"\nEnter a another number: ";
	cin>>c.num;
	d = c.addition(b);
	cout<<"\nThe addition is : ";
	for(i=0;i<binary::n;i++)
		cout<<" "<<c.a[i];
	getch();
}
