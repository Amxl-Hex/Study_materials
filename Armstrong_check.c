#include<stdio.h>

int armcount=0;

int numberlen(int num)//find number of digits
{
int len=0;
while(num!=0)
{
	num/=10;
	len++;
}
return len;
}

int raisedto(int d, int numlen)//find rasied to (basically an user defined pow() function)
{
int d_raised=1;
while(numlen!=0)
{
	d_raised*=d;
	numlen--;
}
return d_raised;
}

void armstrong(int num)//checking armstrong or not
{
int numlen= numberlen(num);
int num1=num, armnum=0, d, d_raisedto;
while(num1!=0)
{
	d=num1%10;
	num1/=10;
	d_raisedto=raisedto(d,numlen);
	armnum+=d_raisedto;
}
if(armnum==num)
{
	printf("%d is an Armstrong number\n", num);
	armcount++;
}
else
	printf("%d is not an Armstrong number\n", num);
}


int main()
{
char choice='Y';
while(choice=='Y'||choice=='y')
{
	int num;
	printf("\nEnter the number: ");
	scanf("%d", &num);
	armstrong(num);
	printf("\nDo you want to check again?(Y/N)");
	scanf(" %c", &choice);
}
printf("\nTotal Armstrong numbers found: %d\n", armcount);
}
