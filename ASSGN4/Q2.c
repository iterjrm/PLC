#include<stdio.h>
#include <ctype.h>



void main()
{

	char current_state;
	char transition_char;




		current_state = start;

		do{
			if(current_state == identifier)
			{
				printf(" - Identifier\n");
				current_state =start;

			}
			else if(current_state == number)
			{
				printf(" - Number\n");
			}


			scanf("%c",&transition_char);

			if(transition_char !=' ')
			{
				printf("%c",transition_char);
			}

			current_state = transition(current_state,transition_char)
		}while(current_state != stop);
		
}