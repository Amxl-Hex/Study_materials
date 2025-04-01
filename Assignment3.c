#include<stdio.h>

//shift array elements
void shiftarrel()
{
int n, shift;
printf("Enter the number of elements:\n");
scanf("%d", &n);
int arr[n];
printf("Enter the elements:\n");
for(int i=0; i<n; i++)
{
	scanf("%d", &arr[i]);
}
//shift
printf("\nHow many places you want to shift?\n");
scanf("%d", &shift);
for(int i=n-1; i!=0; i--)
{
	arr[i]=arr[i-shift];
}
for(int i=0; i<shift; i++)
{
	arr[i]=0;
}
printf("\nThe shifted array is: ");
for(int i=0; i<n; i++)
{
	printf("%d ", arr[i]);
}
}


//largest in the array
void largestel()
{
int n;
printf("Enter the number of elements:\n");
scanf("%d", &n);
int arr[n];
printf("Enter the elements:\n");
for(int i=0; i<n; i++)
{
        scanf("%d", &arr[i]);
}
int largest=arr[0], index=0;
for(int i=0; i<n; i++)
{
	if(arr[i]>largest)
	{
		largest=arr[i];
		index=i;
	}
}
printf("\nLargest value: %d, Index: %d\n", largest, index);
}



//combined sorted array
void combinesortarr()
{
int n1, n2;
printf("Enter the number of elements:\n");
scanf("%d", &n1);
int arr1[n1];
printf("Enter the elements of first array:\n");
for(int i=0; i<n1; i++)
{
        scanf("%d", &arr1[i]);
}
printf("Enter the number of elements:\n");
scanf("%d", &n2);
int arr2[n1+n2];
printf("Enter the elements:\n");
for(int i=0; i<n2; i++)
{
        scanf("%d", &arr2[i]);
}
//combine
for(int i=0; i<n1; i++)
{
	arr2[i+n2]=arr1[i];
}

//sort
for(int i=0; i<n1+n2; i++)
{
	for(int j=i+1; j<n1+n2; j++)
	{
		if(arr2[i]>arr2[j])
		{
			arr2[i]+=arr2[j];
			arr2[j]=arr2[i]-arr2[j];
			arr2[i]=arr2[i]-arr2[j];
		}
	}
}
printf("Combined sorted array: \n");
for(int i=0; i<n1+n2; i++)
	printf("%d ",arr2[i]);
}


//symmetry check
void symmcheck()
{
int n, flag=0;
printf("Enter the number of elements:\n");
scanf("%d", &n);
int arr[n], temp[n];
printf("Enter the elements:\n");
for(int i=0; i<n; i++)
{
        scanf("%d", &arr[i]);
}
int k=0;
for(int i=n-1; i>=0; i--)
{
	temp[i]=arr[k];
	k++;
}
for(int i=0; i<n; i++)
printf("%d ", temp[i]);
for(int i=0; i<n; i++)
{
	if(arr[i]!=temp[i])
	{
		flag=1;
		break;
	}
}
if(flag==0)
printf("It is symmetric\n");
else
printf("It is not symmetric\n");
}


//element occurences
void eloccur()
{
int n;
printf("Enter the number of elements:\n");
scanf("%d", &n);
int arr[n];
printf("Enter the elements:\n");
for(int i=0; i<n; i++)
{
        scanf("%d", &arr[i]);
}
for(int i=0; i<n; i++)
{
	if(arr[i]!=-1)
	{
		int count=1;
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
				arr[j]=-1;
			}
		}
		printf("%d has occured %d time(s)\n", arr[i], count);
	}
}
}



//common elements
void commonel()
{
int n1, n2;
printf("Enter the number of elements:\n");
scanf("%d", &n1);
int arr1[n1];
printf("Enter the elements array1:\n");
for(int i=0; i<n1; i++)
{
        scanf("%d", &arr1[i]);
}
printf("Enter the number of elements:\n");
scanf("%d", &n2);
int arr2[n2], count=0;
printf("Enter the elements array2:\n");
for(int i=0; i<n2; i++)
{
        scanf("%d", &arr2[i]);
}

for(int i=0; i<n1; i++)
{
	int prev_count=count, dif=0;
	for(int j=0; j<n2; j++)
	{
		if(arr1[i]==arr2[j])
		{
			count++;
		}
	}
	dif=count-prev_count;
	if(count-prev_count>1)
		count=count-dif+1;
}
int arrt[count];
for(int i=0; i<n1; i++)
{
        for(int j=0; j<count; j++)
        {
                if(arr1[i]==arr2[j])
                {
                       	arrt[j]=arr1[i];
                       	arr1[i]=-1;
			arr2[j]=-1;
                }
        }
}
printf("\nThe common elements are: ");
for(int i=0; i<count; i++)
printf("%d ", arrt[i]);
}


//rotate matrix 90 degrees
void ninetyrotmat()
{
int r, c;
printf("\nEnter the number of rows: ");
scanf("%d", &r);
printf("\nEnter the number of columns: ");
scanf("%d", &c);
int mat[r][c];
printf("\nEnter the elements: \n");
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		scanf("%d", &mat[i][j]);
	}
}
int rt=c, ct=r;
int matt[rt][ct];
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		matt[j][i]=mat[i][j];
	}
}
for(int i=0; i<rt; i++)
{
	for(int j=ct-1; j>=0; j--)
		printf("%d ", matt[i][j]);
	printf("\n");
}
}


//missing integer
void missint()
{
int n;
printf("\nEnter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements: \n");
for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);
for(int i=1; i<=n; i++)
	if(arr[i-1]!=i)
	{
		printf("\nMissing element: %d", i);
		break;
	}
}


//kth smallest element
void kthsmall()
{
int n, k;
printf("\nEnter the number of elements: \n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements\n");
for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);
for(int i=0; i<n; i++)
{
	for(int j=i+1; j<n; j++)
	{
		if(arr[i]>arr[j])
		{
			arr[i]+=arr[j];
			arr[j]=arr[i]-arr[j];
			arr[i]-=arr[j];
		}
	}
}
printf("\nEnter value of K to find kth smallest element\n");
scanf("%d", &k);
printf("\nThe %dth smallest number in the array is %d\n", k, arr[k-1]);
}


//spiral matrix printing
void spiralmat()
{
int r, c;
printf("\nEnter the number of rows and columns\n");
scanf("%d%d", &r, &c);
int mat[r][c];
printf("\nEnter the elements\n");
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		scanf("%d", &mat[i][j]);
	}
}
printf("\nThe original matrix: \n");
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		printf("%d ", mat[i][j]);
	}
	printf("\n");
}
printf("\nSpiral output: ");
int l=0,m=0, even=0;
for(l; l<r; l++)
{
	if(even==0)
	{
		for(m=0; m<c; m++)
			printf("%d  ", mat[l][m]);
		//printf("\n");
		even++;
	}
	else
	{
		int flag=1;
		for(m; m>=0; m--)
		{
			if(flag==0)
				printf("%d  ", mat[l][m]);
			flag=0;
		}
		//printf("\n");
		even--;
	}
}
}

//print the unique values
void uniq_val()
{
int n, count=0;
printf("\nEnter the number of elements of array: \n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements of array:\n");
for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);
for(int i=0; i<n; i++)
{
	if(arr[i]!=-1)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]==arr[j])
			{
				arr[j]=-1;
			}
		}
		count++;
	}
}
int arr_uniq[count];
int j=0;
for(int i=0; i<n; i++)
{
	if(arr[i]!=-1)
		{
			arr_uniq[j]=arr[i];
			j++;
		}
}
printf("Unique values : ");
for(int i=0; i<count; i++)
	printf("%d ", arr_uniq[i]);
}


/*//finding sum of non contiguous elements
int nconti_sum(int *arr, int n, int i)
{
int sum=0;

}
//sum of non contiguous elements
void nonconti_sum()
{
int n;
printf("\nEnter the number of elements of array: \n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements of array:\n");
for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
int max_sum, sum;
for(int i=0; i<(n%2==0?n/2:(n/2)+1); i++)
{
	sum=nconti_sum(arr, n, i);

}
}
*/


//count number of array inversions
void countarr_inv()
{
int n, inv=0;
printf("\nEnter the number of elements: \n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements: \n");
for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);
for(int i=0; i<n-1; i++)
	for(int j=1+i; j<n; j++)
		if(arr[i]>arr[j])
			inv++;
printf("\nNumber of inversions = %d\n", inv);
}


//element wise addition
void elwise_add()
{
int n1, n2, n;
printf("\nEnter the length of array 1 and array 2\n");
scanf("%d%d", &n1, &n2);
int arr1[n1], arr2[n2];
printf("\nEnter the %d elements of array 1: \n", n1);
for(int i=0; i<n1; i++)
	scanf("%d", &arr1[i]);
printf("\nEnter the %d elements of array 2: \n", n2);
for(int i=0; i<n2; i++)
	scanf("%d", &arr2[i]);
n=(n1>n2?n1:n2);
for(int i=n1; i<n; i++)
	arr1[i]=0;
for(int i=n2; i<n; i++)
	arr2[i]=0;
int sum[n];
printf("\n\nSum = ");
for(int i=0; i<n; i++)
{
	sum[i]=arr1[i]+arr2[i];
	printf("%d ", sum[i]);
}
}


//transpose matrix
void transpose_mat()
{
int r, c;
printf("\nEnter the number of rows and columns: \n");
scanf("%d %d", &r, &c);
int mat[r][c];
printf("\nEnter the elements:\n");
for(int i=0; i<r; i++)
	for(int j=0; j<c; j++)
		scanf("%d", &mat[i][j]);
printf("\nThe transposed matrix : \n");
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
		printf("%d ", mat[j][i]);
	printf("\n");
}
}


//length of consecutive elements
void conseq_len()
{
int n, count=1, maxcount=0;
printf("\nEnter the number of elements\n");
scanf("%d", &n);
int arr[n];
printf("\nEnter the elements\n");
for(int i=0; i<n; i++)
	scanf("%d", &arr[i]);
for(int i=0; i<n; i++)
{
	for(int j=i+1; j<n; j++)
	{
		if(arr[i]>arr[j])
		{
			arr[i]+=arr[j];
			arr[j]=arr[i]-arr[j];
			arr[i]=arr[i]-arr[j];
		}
	}
}
for(int i=0; i<n; i++)
{
	if(arr[i+1]==arr[i]+1)
	{
		count++;
	}
	else
	{
		if(count>maxcount)
			maxcount=count;
		count=0;
	}
}
printf("\nLength of the longest consecutive sequence = %d\n", maxcount);
}



//main function
int main()
{
char ch='Y';
int cho;
while(ch=='Y'||ch=='y')
{
printf("Choose:\n1. Shift Array Elements\n2. Largest Value\n3. Combine Sorted Array\n4. Symmetry Check\n5. Element Occurences\n6. Filter unique values\n7. Max sum of non-contiguous elements\n8. Common Elements\n9. Rotate the matrix 90deg\n10. Find Missing integer\n11. k^(th) Smallest element\n13. Print matrix spirally\n15. Count the Number of Array Inversions\n16. Length of Consecutive Sequence\n17. Element-wise Addition\n18. Transpose Matrix\n20. Replace an Element\n\n");
scanf("%d", &cho);
switch(cho)
{
	case 1: shiftarrel(); break;
	case 2: largestel(); break;
	case 3: combinesortarr(); break;
	case 4: symmcheck(); break;
	case 5: eloccur(); break;
	case 6: uniq_val(); break;
	//case 7: nonconti_sum(); break;
	case 8: commonel(); break;
	case 9: ninetyrotmat(); break;
	case 10: missint(); break;
	case 11: kthsmall(); break;
	//case 12:
	case 13: spiralmat(); break;
	//case 14:
	case 15: countarr_inv(); break;
	case 16: conseq_len(); break;
	case 17: elwise_add(); break;
	case 18: transpose_mat(); break;
	//case 20: dyna_array(); break;
}
printf("\nDo you want to continue?(Y/N)\n");
scanf(" %c", &ch);
}
}
