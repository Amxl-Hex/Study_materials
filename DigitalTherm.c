#include<stdio.h>

float ctof(int c)
{
float fa;
fa=((9*c)/5)+32;
printf("\nConverted temperature = %f\n", fa);
return fa;
}

float ftoc(int f)
{
float ce;
ce=(5*(f-32))/9;
printf("\nConerted temperature = %f\n", ce);
return ce;
}



int main()
{
int count=0;
float sum=0, c, f, max=0, min=0;
char choice='Y';
while(choice=='Y'||choice=='y')
{
	int conv_choice;
	printf("\nMenu\n1. Celcius to Fahrenheit\n2. Fahrenheit to Celcius\n");
	scanf("%d", &conv_choice);
	switch(conv_choice)
	{
		case 1: printf("\nEnter the temperature in celcius: ");
			scanf("%f", &c);
			f=ctof(c);
			if(c>100)
                                printf("\nHigh Temperature!\n");
                        else if(c<24)
                                printf("\nLow temperature!\n");

			if(count==0)
			{
				max=f;
				min=f;
			}
			else
			{
				if(f>max)
					max=f;
				else if(c<min)
					min=f;
			}
			count++;
			sum+=f;
			break;
		case 2: printf("\nEnter the temperature in fahrenheit: ");
			scanf("%f", &f);
			c=ftoc(f);
			if(c>=100)
				printf("\nHigh Temperature!\n");
			else if(c<24)
				printf("\nLow temperature!\n");
			if(count==0)
			{
				max=f;
				min=f;
			}
			else
			{
				if(f>max)
					max=f;
				else if(f<min)
					min=f;
			}
			count++;
			sum+=f;
			break;
		default: printf("\nWrong choice!\n");
	}
	printf("\nDo you want to continue?\n");
	scanf(" %c", &choice);
}
printf("\nTotal readings: %d\nAverage temperature= %f\nMin temperature= %f\nMax temoerature= %f\n", count, sum/count, min, max);
}
