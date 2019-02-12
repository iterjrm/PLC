#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef enum
{
        start,stop,build_id,identifier,build_num,number,dead
}states;

states transition(states current, char c)
{
	switch(current)
	{
		case start:
				if(isdigit(c))
					return build_num;
				else if(isalpha(c))
					return build_id;
				else if(c == '.')
					return stop;
				else if(c == ' ')
					return start;
				else
					return dead;
		case build_id:
				if(isdigit(c))
                                        return build_id;
                                else if(isalpha(c))
                                        return build_id;
                                else if(c == '_')
                                        return build_id;
                                else if(c == ' ')
                                        return identifier;
                                else
                                	return dead;
		case build_num:
				if(isdigit(c))
                                        return build_num;
                                else if(c == ' ')
                                        return number;
                                else
                                	return dead;
	}
}

void main()
{
        states current_states;
        char transition_char,c;
	FILE *fd,*fd1;
	fd=fopen("input.txt","r");
	fd1=fopen("output.txt","w");
      
	 current_states=start;
        do
        {
            if (current_states == identifier)
			{
				fprintf(fd1," - Identifier\n");
				
				current_states = start;
			}
			else if (current_states == number)
			{
				fprintf(fd1," - Number\n");
                  current_states = start;
			}
			else if (current_states == dead)
			{
				c=fgetc(fd);
				while(c!=' ')
				{
					fprintf(fd1,"%c",c);
					c=fgetc(fd);
				}	
				fprintf(fd1," - Invalid\n");
				current_states = start;
			}
		transition_char=fgetc(fd);
		
		if (transition_char != ' ' && transition_char!= '.')
			fprintf(fd1,"%c", transition_char);
		current_states = transition(current_states, transition_char);
        } while (current_states != stop);

	
        fclose(fd);
        fclose(fd1);
}