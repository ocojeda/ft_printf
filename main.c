#include "includes/ft_printf.h"
#include <stdlib.h>

int main(void)
{
  int total;

 //TRUE
  /* total = ft_printf("%0d lkasjdfhal;kjsbf;ajksbdfha;sdjbfa;skjbdflsadkjbfdskjbalskjbd", -42);
   ft_printf("--->total = %d\n", total);
   total = printf("%0d", -42);
   printf("--->total = %d\n", total);
  total = ft_printf("{%10d}", -42);
   ft_printf("--->total = %d\n", total);
   total = printf("{%10d}", -42);
   printf("--->total = %d\n", total);
  total = ft_printf("{%10d}", 42);
   ft_printf("--->total = %d\n", total);
   total = printf("{%10d}", 42);
   printf("--->total = %d\n", total);
   total = ft_printf("{%4d}", 10000);
   ft_printf("--->total = %d\n", total);
   total = printf("{%4d}", 10000);
   printf("--->total = %d\n", total);
 total = ft_printf("{%30d}", 10000);
   ft_printf("--->total = %d\n", total);
   total = printf("{%30d}", 10000);
   printf("--->total = %d\n", total);
   total = ft_printf("{%3c}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%3c}", 0);
   printf("--->total = %d\n", total);
   total = ft_printf("{%5p}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%5p}", 0);
   printf("--->total = %d\n", total);
  total = ft_printf("{%-13p}", &strlen);
   ft_printf("--->total = %d\n", total);
   total = printf("{%-13p}", &strlen);
   printf("--->total = %d\n", total);
   total = ft_printf("{%10R}");
   ft_printf("--->total = %d\n", total);
   total = printf("{%10R}");
   printf("--->total = %d\n", total);
   
   total = ft_printf("{%-30S}", L"我是一只猫。");
   ft_printf("--->total = %d\n", total);
   total = printf("{%-30S}", L"我是一只猫。");
   printf("--->total = %d\n", total);
   
   */

   // TESTS A CORRIGER 
   
   
   
    total = ft_printf("{%s}", "");
   ft_printf("--->total = %d\n", total);
   total = printf("{%s}", "");
   printf("--->total = %d\n", total);


  total = ft_printf("{%05.S}", L"42 c est cool");
   ft_printf("--->total = %d\n", total);
   total = printf("{%05.S}", L"42 c est cool");
   printf("--->total = %d\n", total);



  
   
  // TEST 1
  /*
  total = ft_printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
   ft_printf("--->total = %d\n", total);
   total = printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
   printf("--->total = %d\n", total);
   total = ft_printf("{%-13p}", &strlen);
   ft_printf("--->total = %d\n", total);
   total = printf("{%-13p}", &strlen);
   printf("--->total = %d\n", total);
  total = ft_printf("{%10R}");
   ft_printf("--->total = %d\n", total);
   total = printf("{%10R}");
   printf("--->total = %d\n", total);
total = ft_printf("{%30S}", L"我是一只猫。");
   ft_printf("--->total = %d\n", total);
   total = printf("{%30S}", L"我是一只猫。");
   printf("--->total = %d\n", total);
total = ft_printf("{%5p}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%5p}", 0);
   printf("--->total = %d\n", total);
  total = ft_printf("{%3c}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%3c}", 0);
   printf("--->total = %d\n", total);
  total = ft_printf("{%.S}", L"我是一只猫。");
   ft_printf("--->total = %d\n", total);
   total = printf("{%.S}", L"我是一只猫。");
   printf("--->total = %d\n", total);
  total = ft_printf("%p", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("%p", 0);
   printf("--->total = %d\n", total);
   total = ft_printf("%s", "abc");
   ft_printf("--->total = %d\n", total);
   total = printf("%s", "abc");
   printf("--->total = %d\n", total);
   total = ft_printf("111%s333", "222");
   ft_printf("--->total = %d\n", total);
   total = printf("111%s333", "222");
   printf("--->total = %d\n", total);
   total = ft_printf("%s333", "222");
   ft_printf("--->total = %d\n", total);
   total = printf("%s333", "222");
   printf("--->total = %d\n", total);
   
   total = ft_printf("111%s", "222");
   ft_printf("--->total = %d\n", total);
   total = printf("111%s", "222");
   printf("--->total = %d\n", total);
   */
   total = ft_printf("{%s}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%s}", 0);
   printf("--->total = %d\n", total);
   
   //error//
   total = ft_printf("{%s}", "");
   ft_printf("--->total = %d\n", total);
   total = printf("{%s}", "");
   printf("--->total = %d\n", total);
   
   total = ft_printf("{%10d}", 42);
   ft_printf("--->total = %d\n", total);
   total = printf("{%10d}", 42);
   printf("--->total = %d\n", total);
   total = ft_printf("{%4d}", 10000);
   ft_printf("--->total = %d\n", total);
   total = printf("{%4d}", 10000);
   printf("--->total = %d\n", total);
total = ft_printf("{%30d}", 10000);
   ft_printf("--->total = %d\n", total);
   total = printf("{%30d}", 10000);
   printf("--->total = %d\n", total);
total = ft_printf("{%10d}", -42);
   ft_printf("--->total = %d\n", total);
   total = printf("{%10d}", -42);
   printf("--->total = %d\n", total);
total = ft_printf("{%3c}", 0);
   ft_printf("--->total = %d\n", total);
   total = printf("{%3c}", 0);
   printf("--->total = %d\n", total);

/*   total = ft_printf("%s %d %p %% %S %D %i %o %O %u %U %x %X %c %C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
   ft_printf("--->total = %d\n", total);
   
   total = printf("%s %d %p %% %S %lD %i %o %O %u %lU %x %X %c %C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
   printf("--->total = %d\n", total);*/
/*
total = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
ft_printf("--->total = %d\n", total);
total = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
printf("--->total = %d\n", total);
ft_putlnbr(UINT_MAX);
   total = ft_printf("%.4s", "42 is the answer");
   ft_printf("--->total = %d\n", total);
   
   total = printf("%.4s", "42 is the answer");
   printf("--->total = %d\n", total);*/

   //total = ft_printf("% 3.0d", 9999);
   //printf("--->total = %d\n", total);
    //ft_putchar('\n');
    //ft_putnbr(ft_printf("->%D", 0L));
    //ft_putnbr(printf("the real %d\n", INT_MIN));
    //printf("the real %d\n", INT_MIN);
    //ft_putnbr(printf("%s %s\n", NULL, NULL));
    //printf("%o %o %o %o %o\n", 1, 100, 999, 42, 999988888);
    //ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
    //printf("% Zoooo");
  /*
  ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);
  
  while(1);*/

    return 0;
}