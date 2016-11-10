/*  
 *  file: stringtohex.c
 *  by omen23 © 2016
 *  print strings in hex
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
                
int main(void)
{ 
  
  unsigned char a[65536]; 
  unsigned char answer;  
  int i, val;
  
  memset(a, 0, sizeof a);
  printf("Please enter the string to convert: ");
  assert(fgets(a, sizeof a, stdin) != NULL);    
  /* remove 0xa (\n) of fgets() */
  a[strlen(a) - 1] = 0;
  val = strlen(a) - 1;
  if (val == -1) /* check for empty value and call main again */
    main(); 
  printf("The fgets() newline char '\\n' was replaced - it is '0a'\nand no '\\0' terminator is shown\nDo you want shellcode style output (default)? [y/N]: ");  
  answer = getchar();
  
  if ('n' == tolower(answer)) 
  {     
    printf("hex-string in C/LSB order: ");
    for (i = 0; i <= val; i++) 
      printf("%02x", a[i]);                
  } 
  else   
  {
    printf("hex-string in shellcode style/MSB order: ");
    for (i = val; i >= 0; i--)
      printf("%02x", *(a + i));     
  }   
  putchar('\n');  
  /* false [0] if no errors occured, otherwise positive value */
  return errno != 0;
}

