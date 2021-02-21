#include<stdio.h>
#include<stdlib.h>
void degree_of_membershipA(float [], int []);
void degree_of_membershipB(float [], int []);

int main()
{
	char name[40][40];
	int i,j,age[10];
	float degOfMemA[10],degOfMemB[10];
	
	printf("Enter name and age:\n");
	for(i=0;i<5;i++)
	{	
		printf("Name: ");
		scanf("%s",&name[i]);
		printf("Age: ");
		scanf("%d",&age[i]);
		printf("\n");
	}
	system("clear");
	printf("Following are the name and age of 5 people:\n");
	for(i=0;i<5;i++)
	{
		printf("Name: %s and Age: %d\n",name[i],age[i]);
	}
	degree_of_membershipA(degOfMemA,age);
	degree_of_membershipB(degOfMemB,age);
	
	display(degOfMemA,"First Fuzzy Sets");
	display(degOfMemB,"Second Fuzzy Sets");
	
	fuzzy_union(name,degOfMemA,degOfMemB);
	
	fuzzy_intersection(name,degOfMemA,degOfMemB);
	
	fuzzy_complement(name,degOfMemA,"First Fuzzy sets");
	
	fuzzy_complement(name,degOfMemB,"Second Fuzzy sets");
}

void display(float degOfMem[10],char set[30])
{
	int i;
	printf("\nDegree of Membeship of %s = {",set);
	for(i=0;i<5;i++)
	{
		if(i<4)
		{
			printf("%.1f, ",degOfMem[i]);
		}
		else
		{
			printf("%.1f",degOfMem[i]);
		}
	}
	printf("}\n");
}

void degree_of_membershipA(float degOfMemA[10], int age[10])
{
	int i;
	float num;
	for(i=0;i<5;i++)
	{
		if(age[i]<=20)
		{
			degOfMemA[i] = 1;
		}
		else if(age[i] <= 30)
		{
			num = 30-age[i];
			degOfMemA[i] = num/10;
		}
		else
		{
			degOfMemA[i] = 0;
		}
		
	}
}

void degree_of_membershipB(float degOfMemB[10], int Age[10])
{
	int i;
	float num;
	for(i=0;i<5;i++)
	{
		if(Age[i]<=15)
		{
			degOfMemB[i] = 1;
		}
		else if(Age[i]>15 && Age[i]<=35)
		{
			num = 35-Age[i];
			degOfMemB[i] = num/20;
		}
		else
		{
			degOfMemB[i] = 0;
		}
		
	}
}

void fuzzy_union(char name[40][40],float degOfMemA[10],float degOfMemB[10])
{
	int i;
	float fuzzyUni[10];
	for(i=0;i<5;i++)
	{
		if(degOfMemA[i] > degOfMemB[i])
		{
			fuzzyUni[i] = degOfMemA[i];
		}
		else
		{
			fuzzyUni[i] = degOfMemB[i];
		}
	}
	printf("\nFuzzy Union = {");
	for(i=0;i<5;i++)
	{
		if(i<4)
		{
			printf("%.1f/%s, ",fuzzyUni[i],name[i]);
		}
		else
		{
			printf("%.1f/%s",fuzzyUni[i],name[i]);
		}
	}
	printf("}\n");
}

void fuzzy_intersection(char name[40][40],float degOfMemA[10],float degOfMemB[10])
{
	int i;
	float fuzzyIni[10];
	for(i=0;i<5;i++)
	{
		if(degOfMemA[i] > degOfMemB[i])
		{
			fuzzyIni[i] = degOfMemB[i];
		}
		else
		{
			fuzzyIni[i] = degOfMemA[i];
		}
	}
	printf("\nFuzzy Intersection = {");
	for(i=0;i<5;i++)
	{
		if(i<4)
		{
			printf("%.1f/%s, ",fuzzyIni[i],name[i]);
		}
		else
		{
			printf("%.1f/%s",fuzzyIni[i],name[i]);
		}
	}
	printf("}\n");
}

void fuzzy_complement(char name[40][40],float degOfMem[10],char set[20])
{
	int i;
	float fuzzyComp[10];
	for(i=0;i<5;i++)
	{
		fuzzyComp[i] = 1-degOfMem[i];
	}
	printf("\nFuzzy Complement of %s= {",set);
	for(i=0;i<5;i++)
	{
		if(i<4)
		{
			printf("%.1f/%s, ",fuzzyComp[i],name[i]);
		}
		else
		{
			printf("%.1f/%s",fuzzyComp[i],name[i]);
		}
	}
	printf("}\n");
}
