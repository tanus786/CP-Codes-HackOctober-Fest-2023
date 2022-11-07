#include <stdio.h>
#include <string.h>
 
int main()
{
  	char str[100];
  	int i, len, stratIndex, endIndex;
 
  	printf("\n Please Enter any Text :  ");
  	gets(str);
  	
  	len = strlen(str);
  	endIndex = len - 1;
	    	 	   	
  	for(i = 0; i <= endIndex; i++)
	{
		if(str[i] != str[endIndex])
		{
			break;	
		} 
		endIndex--;		
	}
	if(i >= endIndex)
	{
		printf("\n %s is a Palindrome String", str);
	}
	else
	{
		printf("\n %s is Not", str);
	}	
	
  	return 0;
}
