/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:17:18 by gbazin            #+#    #+#             */
/*   Updated: 2024/11/19 17:36:45 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

#define White "\033[0;37m"
#define Green "\033[0;32m"
#define Red "\033[0;31m"
#define Purple "\033[0;35m"

int	main(void)
{
	const char	*str1 = NULL;
	int			*i;
	const char	*str2 = "test";
	int			good_token;

	good_token = 0;
	i = malloc(10000);
	printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║		🌶️ Bienvenue sur la proutinette 🌶️		║\n");
	printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
	// test 1
	printf(Purple "Test 1 :\n");
	printf(White);
	i[0] = printf("PRINTF_OG:%s\n", str1);
	i[1] = ft_printf("FT_PRINTF:%s\n", str1);
	if (i[0] == i[1])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[0], i[1]), good_token = 1;
	printf(White "\n");
	// test 2
	printf(Purple "Test 2 :\n");
	printf(White);
	i[2] = printf("PRINTF_OG: %s %x %c\n", str2, -42, '>');
	i[3] = ft_printf("FT_PRINTF: %s %x %c\n", str2, -42, '>');
	if (i[2] == i[3])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[2], i[3]), good_token = 1;
	printf(White "\n");
	// test 3
	printf(Purple "Test 3 :\n");
	printf(White);
	i[4] = printf("PRINTF_OG: %d %X %u\n", -42, -42, -42);
	i[5] = ft_printf("FT_PRINTF: %d %X %u\n", -42, -42, -42);
	if (i[4] == i[5])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[4], i[5]), good_token = 1;
	printf(White "\n");
	// test 4
	printf(Purple "Test 4 :\n");
	printf(White);
	i[6] = printf("PRINTF_OG: %i %% %p\n", -42, &str2);
	i[7] = ft_printf("FT_PRINTF: %i %% %p\n", -42, &str2);
	if (i[6] == i[7])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[6], i[7]), good_token = 1;
	printf(White "\n");
	// test 5
	printf(Purple "Test 5 (%%d):\n");
	printf(White);
	i[8] = printf("PRINTF_OG: %d %d %d\n", -100, 0, 100);
	i[9] = ft_printf("FT_PRINTF: %d %d %d\n", -100, 0, 100);
	if (i[8] == i[9])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[8], i[9]), good_token = 1;
	printf(White "\n");
	// test 6
	printf(Purple "Test 6 (%%i):\n");
	printf(White);
	i[10] = printf("PRINTF_OG: %i %i %i\n", INT32_MIN, 0, INT32_MAX);
	i[11] = ft_printf("FT_PRINTF: %i %i %i\n", INT32_MIN, 0, INT32_MAX);
	if (i[10] == i[11])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[10], i[11]), good_token = 1;
	printf(White "\n");
	// test 7
	printf(Purple "Test 7 (%%u):\n");
	printf(White);
	i[12] = printf("PRINTF_OG: %u %u %u\n", INT32_MIN, 0, INT32_MAX);
	i[13] = ft_printf("FT_PRINTF: %u %u %u\n", INT32_MIN, 0, INT32_MAX);
	if (i[12] == i[13])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[12], i[13]), good_token = 1;
	printf(White "\n");
	// test 8
	printf(Purple "Test 8 (%%x):\n");
	printf(White);
	i[14] = printf("PRINTF_OG: %x %x %x\n", INT32_MIN, 0, INT32_MAX);
	i[15] = ft_printf("FT_PRINTF: %x %x %x\n", INT32_MIN, 0, INT32_MAX);
	if (i[14] == i[15])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[14], i[15]), good_token = 1;
	printf(White "\n");
	// test 9
	printf(Purple "Test 9 (%%X):\n");
	printf(White);
	i[16] = printf("PRINTF_OG: %X %X %X\n", INT32_MIN, 0, INT32_MAX);
	i[17] = ft_printf("FT_PRINTF: %X %X %X\n", INT32_MIN, 0, INT32_MAX);
	if (i[16] == i[17])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[16], i[17]), good_token = 1;
	printf(White "\n");
	// test 10
	printf(Purple "Test 10 (%%p):\n");
	printf(White);
	i[18] = printf("PRINTF_OG: %p %p %p\n", &str1, (void *)-2147483648, str1);
	i[19] = ft_printf("FT_PRINTF: %p %p %p\n", &str1, (void *)-2147483648,
			str1);
	if (i[18] == i[19])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[18], i[19]), good_token = 1;
	printf(White "\n");
	// test 11
	printf(Purple "Test 11 (%%p 2):\n");
	printf(White);
	i[20] = printf("PRINTF_OG: %p %p %p\n", (void *)LONG_MAX, (void *)LONG_MIN,
			(void *)LLONG_MAX);
	i[21] = ft_printf("FT_PRINTF: %p %p %p\n", (void *)LONG_MAX,
			(void *)LONG_MIN, (void *)LLONG_MAX);
	if (i[20] == i[21])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[20], i[21]), good_token = 1;
	printf(White "\n");
	// test 12
	//printf(Purple "printf(NULL)\n");
	//printf(White);
	//i[22] = printf(NULL);
	//i[23] = ft_printf(NULL);
	//if (i[22] == i[23])
	//	printf(Green "Ok ✓");
	//else
	//	printf(Red "KO ✗ OG=%d, FT:%d", i[22], i[23]), good_token = 1;
	//printf(White "\n");
	// test 13
	printf(Purple "test%%\n");
	printf(White);
	write(1, "x", 1);
	i[22] = printf(NULL);
	i[23] = ft_printf(NULL);
	write(1, "x", 1);
	if (i[22] == i[23])
		printf(Green "Ok ✓");
	else
		printf(Red "KO ✗ OG=%d, FT:%d", i[22], i[23]), good_token = 1;
	printf(White "\n");
	if (good_token == 1)
	{
		printf(Red);
		printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║		🤢 Dommage, fix ca bien ! 🤢				║\n");
		printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
	}
	else
		{
		printf(Green);
		printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║		🥳 Masterclass, plus que la moulinette 🥳			║\n");
		printf("╚══════════════════════════════════════════════════════════════════════════════╝\n");
	}
	return (0);
}
//cc -c main.c -o main.o 
//cc main.o -L. -lftprintf -o c