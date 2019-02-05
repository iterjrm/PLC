#include <stdio.h>

void main()
{
	char c='x';

	char ip[100];

	printf("\nEnter The String To Check If It's Recognized By The Language :\n");


	scanf("%s",ip);

	int i=0;

	int zero=0,one=0;

	while(1)
	{
			c = ip[i];

			if(c=='\0')
			{
				break;
			}
			if(c == '0')
			{

				zero++;
			}
			else if(c == '1')
			{
				one++;
			}
			else
			{
				printf("Invalid Literals Entered\n");
				return;

			}

			i++;



	}

	if((zero%2==0) && (one%2==0))
	{
			printf("Even No. Of 0's and 1's\n");
	}
	else if ((zero%2==0) && (one%2==1))
	{
		printf("Even No. Of 0's and Odd No. Of 1's\n");
	}
	else if ((zero%2==1) && (one%2==1))
	{
		printf("Odd No. Of 0's and 1's\n");
	}
	else
	{
		printf("Odd No. Of 0's and Even No. Of 1's\n");
	}
	
	




}
