#include<stdio.h>
#include<string.h>
int arrLength(const char* str)
    {
		int counter =1;
        while(*str != '\0')
            {
             counter++;
             str++;
			}
				   return counter;
            }
            
            
int main()
{
	
	int length;
	int *p;
	char str[10];
	printf(" enter string \n ");
	gets(str);
	
	p=&str[1];
	length = arrLength(p);
	
	printf("%d",length);
	
}
