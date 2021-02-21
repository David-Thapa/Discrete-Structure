#include<stdio.h>
#include<stdlib.h>

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
	printf("\nTHE ELEMENT IN SET:\n");
	printf("{");
	for(i=0;i<size;i++)
	{	if(i<size-1)
			printf("%d,",Arr[i]);
		else if(i==size-1)
		{	printf("%d",Arr[i]);
		}
	}
	printf("}");
}
int uni(int A[],int m,int B[],int n,int UNO[])		//for union
{	int i,j,l,k=0;
	for(l=0;l<m;l++)
	{	UNO[k]=A[l];
		k++;	
	}
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			break;		
		}
		if(i==m)
		{	UNO[k]=B[j];
			k++;		
		}
	}
	return(k);
}
int intersection(int A[],int m,int B[],int n,int INT[])					//for intersection
{	int i,j,l,k=0;
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			{	break;			
			}
		}
		if(i!=m)
		{	INT[k++]=B[j];
		}		
	}
	return(k);
}
int difference(int A[],int m,int B[],int n,int DIF[])			//for difference
{	int i,j,k=0;
	for(j=0;j<n;j++)
	{	for(i=0;i<m;i++)
		{	if(B[j]==A[i])
			{	break;			
			}
		}
		if(i==m)
		{	DIF[k++]=B[j];
		}	
	}
	return(k);

}

int sdiff(int DIFBA[],int difba,int DIFAB[],int difab,int SDIF[])			//for symmetric	difference
{	int k;
	k=uni(DIFAB,difab,DIFBA,difba,SDIF);	
	return(k);
}


void show(int A[],int m,int B[],int n)	//for showing output
{	printf("\nSET A:");
	display(A,m);
	printf("\nSET B:");
	display(B,n);
}	

int main()
{	
	int A[20],B[20],UNO[50],DIFAB[50],DIFBA[50],INT[50],SDIF[50];	
	int m,n,uno,difab,difba,in,sd;
	system("clear");
	printf("\nENTER THE NUMBER OF ELEMENT IN SET A: ");
	scanf("%d",&m);
	accept(A,m);
	display(A,m);
	
	printf("\nENTER THE NUMBER OF ELEMENT IN SET B: ");
	scanf("%d",&n);
	accept(B,n);
	display(B,n);
	
	getchar();
	system("clear");
	
	//union
	show(A,m,B,n);	
	uno=uni(A,m,B,n,UNO);
	printf("\nAFTER UNION:");
	display(UNO,uno);
	
	//intersection
	in=intersection(A,m,B,n,INT);
	printf("\nAFTER INTERSECTION:");
	display(INT,in);
	
	//difference
	difba=difference(B,n,A,m,DIFBA);
	printf("\nAFTER DIFFERENCE A-B:");
	display(DIFBA,difba);
	difab=difference(A,m,B,n,DIFAB);
	printf("\nAFTER DIFFERENCE B-A:");
	display(DIFAB,difab);
	
	//symetric differece
	sd=sdiff(DIFBA,difba,DIFAB,difab,SDIF);
	printf("\nAFTER SYMETRIC DIFFERENCE:");
	display(SDIF,sd);
		
	return 0;
}
