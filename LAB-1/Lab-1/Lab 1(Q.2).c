#include<stdio.h>

void Cart(int [], int [], int, int);
void accept(int [], int);
void display(int [], int);
void bubbleSort(int [], int);

int main()
{
	int p,q;
    int a[20];
    int b[20];
    
    printf("\nENTER THE NUMBER OF ELEMENT IN SET A: ");
	scanf("%d",&p);
	accept(a,p);
	display(a,p);	
	
	printf("\nENTER THE NUMBER OF ELEMENT IN SET B: ");
	scanf("%d",&q);
	accept(b,q);
	display(b,q);
    
	printf("\n\nSize of SetA=%d \n Size of SetB=%d",p,q);
    bubbleSort(a,p);
    bubbleSort(b,q);
    printf("\n ");
	Cart(a,b,p,q);
}

void accept(int Arr[],int size)		//FOR ACCEPTING VALUE
{	int i;
	printf("SIZE=%d",size);
	printf("\nENTER THE ELEMENT IN SET:\n");	
	for(i=0;i<size;i++)
	{	scanf("%d",&Arr[i]);
	}
}

void display(int Arr[],int size)		//FOR DISPLAY VALUE
{	int i;
	printf("\nTHE ELEMENT IN SET:");
	printf("{");
	for(i=0;i<size;i++)
	{	if(i<size-1)
			printf("%d,",Arr[i]);
		else if(i==size-1)
		{	printf("%d}",Arr[i]);
		}
	}
}

void Cart(int a[],int b[],int m, int n)
{
    int i,j;
    printf("{");
    for(i=0;i<m;i++)
    {
        
        for(j=0;j<n;j++)
        {
            
            printf("(%d,%d)",a[i],b[j]);
            printf(",");
        }
        printf("\n");
    }
    printf("}");
}

void bubbleSort(int arr[], int n)
{
   int i, j,temp;
   for (i = 0; i < n-1; i++)      
    {
        
       for (j = 0; j < n-i-1; j++) 
       {
        
           if (arr[j] > arr[j+1])
           {
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
           }
       }
    }
}
