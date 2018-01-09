#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

void binaryArray(int n, int *array, int size)
{
 int one_zero = 0;
 int i = size - 1;
 unsigned int dec_num = n;
   for (;dec_num > 0;)
   {
	one_zero =  (dec_num & 1);
	array[i] = one_zero;
	dec_num = dec_num >> 1;
    if (dec_num > 0)
    {
	 i = i - 1;
    }
   }
   if  (i != 0 && i > 0)
   {
	i = i - 1;
    for (i;i >= 0;i--)
       {
         array[i] = 0;
       }
   }
}
void binaryPrinter(int *array, int size)
{
    int i;
    printf("Binary Representation is :\n");
    for(i = 0; i < size; i++)
	{
    printf("%d ",array[i]);
    }
}

unsigned int countOnes(int num)
{
   int count = 0;
   unsigned dec_num = num;
   for (;dec_num > 0;)
   {
   count = count + (dec_num & 1);
   dec_num = dec_num >> 1;
   }
   return count;
}

int myStrStr(char *haystack,char *needle,char *buffer)
{
char *d = haystack;
int loop_pos = 0;
int buf_var = 0;
int flag =0;
int result = 0;
int posi_Stop = 0;
int i = 0;
int j = 0;
for(j;j<255;j++)
{
buffer[j]='\0';
}
int loop_cnt = strlen(needle);
for (;*d != '\0'; d++)
 {
  char haystack_char = *d;
  char *e = needle;
   loop_pos = 0;
   for (;*e != '\0'; e++)
   {
    char needle_char = *e;
	loop_pos = loop_pos  + 1;

	if (posi_Stop == 0 && loop_pos == 1)
	{
	 if ((haystack_char == needle_char) && (flag == 0))
	   {
	    flag = 1;
	    buf_var = 1;
	    posi_Stop = posi_Stop+1;
	    buffer[i] = haystack_char;
	    i = i + 1;
	    break;
	   }
         else
          {
           flag = 0;
           buf_var = 0;
           posi_Stop = 0;
           j = 0;
           for(j;j<i;j++)
           {
            buffer[j]='\0';
           }
           i = 0;
          }
	}
	if (posi_Stop < loop_pos)
	  {
	   if ((flag == 1) &&  (haystack_char == needle_char))
	   {
	    buf_var = buf_var + 1;
	    posi_Stop = posi_Stop + 1;
	    buffer[i] = haystack_char;
	    i = i + 1;
	    break;
	   }
           else
           {
 	    flag  = 0;
	    buf_var = 0;
	    posi_Stop = 0;
	    j = 0;
            for(j;j<i;j++)
            {
             buffer[j]='\0';
            }
	    i = 0;
           }
          }
      }
      if (loop_cnt == buf_var)
      {
       result = 1;
       break;
      }
 }
    return result;
}
