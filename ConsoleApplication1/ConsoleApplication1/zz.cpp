#include <stdio.h>

int main()
{
	int a=0;

	printf(" ������ �Է��Ͽ� �ּ��� : ");
	scanf("%d", &a);

	if (a >0)
	{
		printf(" %d is a negative.\n",a);
	}
	else if(a<0)
	{
		printf(" %d is a positive.\n",a);
	}
	else
	{
		printf("0 is zero\n");
	}

	return 0;
}