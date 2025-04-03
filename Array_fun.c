//THIS PROGRAM DEALS WITH MANY OF THE ARRAY FUNCTIONS.

#include<stdio.h>


//search for an element
void searchel(int *arr, int n)
{
int chk, pos, flag = 0;
printf("\nEnter the element to be searched\n");
scanf("%d", &chk);
for(int i = 0; i < n; i++)
{
	if(arr[i] == chk)
	{
		pos = i;
		flag = 1;
	}
}
if(flag == 1)
printf("\nThe element is present at position %d\n", pos+1);
else
printf("\nThe element is not present\n");
}


//reverse the array
void revarr(int *arr, int n)
{
int brr[n];
for(int i = 0; i < n; i++)
{
brr[n-1-i] = arr[i];
}
for(int i = 0; i < n; i++)
{
arr[i] = brr[i];
}
printf("\nReversed array: \n");
for(int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}


//insert an element
int insel(int *arr, int n)
{
int inel, pos;
printf("\nEnter the position to insert\n");
scanf("%d", &pos);
printf("Enter the element\n");
scanf("%d", &inel);
n += 1;
for(int i = n; i >= pos-1; i--)
arr[i] = arr[i-1];
arr[pos-1] = inel;
printf("\nThe updated array:\n");
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
return n;
}


//delete an element
int delel(int *arr, int n)
{
int delpos;
printf("\nEnter the position of the  element to be deleted\n");
scanf("%d", &delpos);
delpos -= 1;
for(int i = 0; i < n; i++)
{
	if(i == delpos)
		{
			for(int j = i; j < n; j++)
			{
				arr[j] = arr[j+1];
			}
		arr[n-1]=0;
		}
}
n -= 1;
printf("\n");
printf("The updated array\n");
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
return n;
}


//merge array
int mergarr(int *arr, int n)
{
int m, temp, k = 0;
printf("Enter the number of elements of new array\n");
scanf("%d", &m);
int brr[m];
printf("Enter the elements\n");
for(int i = 0; i < m; i++)
scanf("%d", &brr[i]);
temp = n;
n += m;
for(int i = temp; i < n; i++)
{
	arr[i] = brr[k];
	k += 1;
}
printf("\nEnter the updated array\n");
for(int i = 0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
return n;
}


//sort in ascending
void sortasc(int *arr, int n)
{
for(int i = 0; i < n; i++)
{
        for(int j = i+1; j < n; j++)
        {
                if(arr[i] > arr[j])
                {
                        arr[i] += arr[j];
                        arr[j] = arr[i]-arr[j];
                        arr[i] = arr[i]-arr[j];
                }
        }
}
printf("The sorted array: ");
for(int i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}


//sum of all elements
void sumofel(int *arr, int n)
{
int sum = 0;
for(int i = 0; i < n; i++)
{
sum += arr[i];
}
printf("Sum of all the elements = %d\n\n", sum);
}


//largest element in the array
void largestel(int *arr, int n)
{
int brr[n];
for(int i = 0; i < n; i++)
{
brr[i] = arr[i];
}
for(int i = 0; i < n; i++)
{
        for(int j = i+1; j < n; j++)
        {
                if(brr[i] > brr[j])
                {
                        brr[i] += brr[j];
                        brr[j] = brr[i]-brr[j];
                        brr[i] = brr[i]-brr[j];
                }
        }
}
printf("The largest element in array = %d\n", brr[n-1]);
}


//average of the array
void avgarr(int *arr, int n)
{
int sum = 0;
float avg;
for(int i = 0; i < n; i++)
sum += arr[i];
avg = sum/n;
printf("\nAverage of the elements in the array = %f\n", avg);
}



//main function
int main()
{
int n, flag = 0;
printf("Enter the number of elements\n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements\n");
for(int i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
//menu
while(flag == 0)
{
int ch;
printf("\n\n__Choose 1, 2, 3, 4 , 5, 6, 7, 8 or 9__\n1. Search for en element\n2. Reverse the array\n3. Insert element\n4. Delete element\n5. Merge\n6. Sort Ascending\n7. Sum of the elements\n8. Largest in the array\n9. Average of the array\n");
scanf("\n%d", &ch);
printf("\n");
switch(ch)
{
case 1: searchel(arr, n); break;
case 2: revarr(arr, n); break;
case 3: n = insel(arr, n); break;
case 4: n = delel(arr, n); break;
case 5: n = mergarr(arr, n); break;
case 6: sortasc(arr, n); break;
case 7: sumofel(arr, n); break;
case 8: largestel(arr, n); break;
case 9: avgarr(arr, n); break;
default: printf("Invalid Choice!\n");
}
char flagch;
printf("Do you want to continue?(Y/N)\n");
scanf(" %c", &flagch);
if(flagch == 'Y'||flagch == 'y')
flag = 0;
else
flag = 1;
}
return 0;
}
