#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n,*temp,value;
void binary_irr()
{
	clock_t t;
    t = clock();
	int beg,end,count,mid;
	beg=0;end=n-1;
	do{
		count++;
	mid=(beg+end)/2;
		if(temp[mid]==value)
		{
			printf("\n value found");
			break;
			
		}
		else if(temp[mid]>value)
		{
			beg=0;
			end=mid-1;
		}
		
    	else
		{
			beg=mid+1;
			end=n-1;
		}
		
	}while( temp[mid]!=value && mid>=0 && mid<n);
	printf("\n number of steps used %d",count);
	
t=clock()-t;
 double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("\nBinary iterative() took %f seconds to execute \n", time_taken);
}
int binary_recursive( int l, int r, int x)
{
	 clock_t t;
    t = clock();
	 if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        if (temp[mid] == x)  
            printf("\nvalue found");
 
      else  if (temp[mid] > x) 
            return binary_recursive( l, mid-1, value);
 
        else{
        
        return binary_recursive( mid+1, n, value);
    }
   }
 	t=clock()-t;
 double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("\nBinary Recursive() took %f seconds to execute \n", time_taken);
	   return -1;	
}
void linear()
{ int count1=0;
      clock_t t;
    t = clock();
	int count;
	for(int i=0;i<n;i++)
	{
		count++;
		if(temp[i]==value)
		{
			printf("\nthe number is found ");
			break;
			count1++;
		}
	}
	if(count1==0)
	{
		printf("\nthe no. is not found ");
	}
	else{
	
	printf("\nnumber of steps used %d ",count);
}
t=clock()-t;
 double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
    printf("\nLinear search() took %f seconds to execute \n", time_taken);
}
int main()
{

	printf("enter the number of elements in array ");
	scanf("%d",&n);
	temp=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
	{
		temp[i]=rand()%500;   
		printf("\n %d",temp[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(temp[i]<temp[j])
			{
				int t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
			}
		}
	}
		printf("\n after sorting ");
	for(int i=0;i<n;i++)
	{
	
	printf("\n %d",temp[i]);	
	}
	
	printf("\nenter the number you want to search:- ");
	scanf("%d",&value);
	printf("\n linear search ");
	
	linear();
	
	printf("\n binary search");
	binary_irr();
	
	printf("\n binary recursive search");
 int result=binary_recursive(1,n,value);
	if (result ==-1)
	{
		printf("\nvalue not found");
	}
	
}

