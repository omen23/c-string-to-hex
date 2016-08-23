/* file: stringtohex.c
*  by omen23 (c) 2016
*  print strings in hex
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
                
int main(void)
{ 
  unsigned char a[65536]; 
  unsigned char answer;
  bool msb = true;
  memset(a, 0, sizeof a); 
    
  printf("Please enter the string to convert: ");
  assert(fgets(a, sizeof a, stdin) != NULL);  
  /* remove 0xa (\n) of fgets() */
  a[strlen(a) - 1] = 0;
  int val = strlen(a) - 1;
  if (val == -1) main(); /* check for empty value and call main again */
  puts("The fgets() newline char '\\n' was replaced - it is '0a'\nand no '\\0' terminator is shown");
  printf("Do you want shellcode style output (default)? [y/N]: ");
  answer = getchar();
  
  if ('n' == tolower(answer)) 
    msb = false;

  if (msb) 
  {
    printf("hex-string in shellcode style/MSB order: ");
    for (int i = val; i >= 0; i--)
      printf("%02x", *(a + i));     
  }
  else 
  {     
    printf("hex-string in C/LSB order: ");
    for (int i = 0; i <= val; i++) 
      printf("%02x", a[i]);                
  }  
  putchar('\n');  
  /* false [0] if no errors occured, otherwise positive value */
  return errno != 0;
}

