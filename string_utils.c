/*
 * string_utils.c
 *
 *  Created on: 27 Nov 2018
 *      Author: aviv
 */

#include <string.h>
#include <stdio.h>
#include "string_utils.h"

void initString(char* str, int size)
{
	*str = '\0';
	if(fgets(str,size,stdin) == NULL) return;
	while(*str != '\n')str++;
	*str = '\0';
}

void printString(const char* str)
{
	printf("%s",str);
}

int countWords(const char* str)
{
	int res = 0,count = 0;
	for(;*str != '\0';str++)
	{
		if(!count && isLetter(*str))
			count = 1;
		if(count && !isLetter(*str))
		{
			count = 0;
			res++;
		}
	}
	return res;
}

void longestInCaptital(char* str)
{
	int length,longest = 0,count = 0;
	char *ch,*longestch;
	ch = str;
	longestch = str;
	for(;*str != '\0';str++)
	{
		if(!count && isLetter(*str))
		{
			ch = str;
			count = 1;
		}
		if(count && !isLetter(*str))
		{
			count = 0;
			length = str - ch - 1;
			if(length > longest)
			{
				longest = length;
				longestch = ch;
			}
		}
	}
	for(;isLetter(*longestch);longestch++)
		*longestch &= 0xDF;
}

void revertWords(char* str)
{
	char *start,*end;
	int rev = 1;
	for(;*str != '\0';str++)
	{
		if(rev && isLetter(*str))
		{
			start = str;
			rev = 0;
		}
		if(!rev && !isLetter(*str))
		{
			end = str - 1;
			rev = 1;
			while(start < end)
				swap(start++,end--);
		}
		if(!isSpecial(*str))
			*str = '*';
	}
}

void eraseCharsFromString(char* str,const char* symbols)
{
	int i;
	for(i = 0;*str != '\0';str++)
	{
		if(strchr(symbols,*(str + i)) != NULL) i++;
		*str = *(str+i);
	}
}

int isPalindrome(const char* str)
{
	const char *start,*end;
	start = str;
	end = strchr(str,'\0');
	for(;end > start ; end--,start++)
	{
		while(!isLetter(*start))start++;
		while(!isLetter(*end))end--;
		if((*start | 0x20) != (*end | 0x20))return 0;
	}
	return 1;
}

int isLetter(char ch)
{
	return ch >= 'A' && ch <= 'z';
}

int isSpecial(char ch)
{
	return strchr(SPECIAL_LETTERS,ch) == NULL;
}

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
