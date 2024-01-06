#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10];
	int i,j,n,n1,n2;
	int p = 1; 
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				j++;
			}
			else
			{
				n1=a[i];
				n2=a[j];
        		   
				    while(n1!=n2)
   					 {
        				if(n1 > n2)
           				 n1 -= n2;
        				else
            			n2 -= n1;
    				}
    				
					a[i]= a[i]/n1;
					a[j]= a[j]/n1;	
						
			}
			}
		}
		
		for(i=0;i<n;i++)
		{
			p=p*a[i];
		}
		
		printf("%d",p);
	}
	
