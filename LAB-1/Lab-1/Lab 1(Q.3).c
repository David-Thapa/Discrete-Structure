#include<stdio.h>

void floor_ceiling(float num)
{
	if(num == (int)num)
	{
		printf("floor value: %d\n",(int)num);
		printf("ceiling value: %d",(int)num);
	}
	else
	{
		if(num >= 0)
		{
			printf("floor value: %d\n",(int)num);
			printf("ceiling value: %d",(int)(num+1));
		}
		else
		{
			printf("floor value: %d\n",(int)(num-1));
			printf("ceiling value: %d",(int)num);
		}
	}
}

int main()
{
	float num;
	printf("Enter the number: ");
	scanf("%f",&num);
	floor_ceiling(num);
}
