/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:47:14 by mmonahan          #+#    #+#             */
/*   Updated: 2019/01/15 19:05:15 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

t_list	*ft_map(t_list *elem)
{
	int		i;
	t_list	*new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	if (!new_elem)
		return (0);
	i = 0;
	while (((char *)new_elem->content)[i])
	{
		((char *)new_elem->content)[i] = 'y';
		i++;
	}
	return (new_elem);
}

int	main(void)
{
	int i;
	int j;
	int k; //key

	printf("---------------------------------------\n");
	printf("ft_memset VS memset (3)\n");

	char str1[] = "qwerty"; //6 символов

	printf("original memset\n");
	memset(str1, 'L', 4);
	printf("%s\n", str1);
	printf("21 ft_memset\n");
	ft_memset(str1, 'p', 4);
	printf("%s\n", str1);

	printf("---------------------------------------\n");
	printf("ft_bzero VS bzero (3)\n");

	char temp_bzero_war_1[][1024] = {{"Aaa"},
									{"ss"},
									{"bbsdf"},
									{"1"},
									{"11"},
									{122},
									{""}};

	char temp_bzero_war_2[][1024] = {{"Aaa"},
									{"ss"},
									{"bbsdf"},
									{"1"},
									{"11"},
									{122},
									{""}};

	int test_bzero;
	int test_ft_bzero;
	int rezult_bzero_war;
	test_bzero = 0;
	test_ft_bzero = 0;
	rezult_bzero_war = 0;
	i = 0;
	printf("result\t\tbzero\tft_bzero\tstring1\tstring2\n");
	while (temp_bzero_war_1[i][0])
	{
		bzero(temp_bzero_war_1[i], strlen(temp_bzero_war_1[i]));
		ft_bzero(temp_bzero_war_2[i], ft_strlen(temp_bzero_war_2[i]));
		rezult_bzero_war = strcmp(temp_bzero_war_1[i], temp_bzero_war_2[i]);
		if (rezult_bzero_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\t\"%s\"\n", \
			test_bzero, \
			test_ft_bzero, \
			temp_bzero_war_1[i], \
			temp_bzero_war_2[i]);
		i++;
	}


	printf("ft_bzero\n");
	char t_ft_bzero[10];// = NULL; //"asdfg";
	printf("do\t%s\n", t_ft_bzero);
	ft_bzero(t_ft_bzero, 0);
	printf("posle\t%c%c%c%c%c\n", t_ft_bzero[0],t_ft_bzero[1],t_ft_bzero[2],t_ft_bzero[3],t_ft_bzero[4]);

	printf("bzero\n");
	char t_bzero[100];// = NULL; //"asdfg";
	printf("do\t%s\n", t_bzero);
	bzero(t_bzero, 0);
	printf("posle\t%c%c%c%c%c\n", t_bzero[0],t_bzero[1],t_bzero[2],t_bzero[3],t_bzero[4]);


	printf("---------------------------------------\n");
	printf("ft_memcpy VS memcpy (3)\n");

	char memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	char ft_memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};

	memcpy(memcpy_test[0], memcpy_test[1], 3);
	memcpy(memcpy_test[1], memcpy_test[2], 4);
	memcpy(memcpy_test[2], memcpy_test[0], 2);
	ft_memcpy(ft_memcpy_test[0], ft_memcpy_test[1], 3);
	ft_memcpy(ft_memcpy_test[1], ft_memcpy_test[2], 4);
	ft_memcpy(ft_memcpy_test[2], ft_memcpy_test[0], 2);
	i = 0;
	j = 0;
	k = 0;
	while (i < 3) {
		while (j < 5)
		{
			if (memcpy_test[i][j] != ft_memcpy_test[i][j])
			k++;
			j++;
		}
		j = 0;
		if (k == 0)
		printf("[OK]");
		else
		printf("[-KO-]");
		printf("\t(%lu vs %lu)\t%s %s\n", strlen(ft_memcpy_test[i]), strlen(memcpy_test[i]), ft_memcpy_test[i], memcpy_test[i]);
		i++;
	}
	// if ( memcmp ()== 0)
	//	 printf("[OK]");
	// else
	//	 printf("[-KO-]");
	// printf("\t(%lu vs %lu)\t%s %s\n", strlen(ft_memcpy_test[i]), strlen(memcpy_test[i]), ft_memcpy_test[i], memcpy_test[i]);

	printf("---------------------------------------\n");
	printf("ft_memccpy VS memccpy (3)\n");

	char memccpy_src[15]="1234567890";
	char memccpy_dst[15]="";
	memccpy(memccpy_dst, memccpy_src,'1', 10);
	printf("memccpy_dst: %s\n", memccpy_dst);

	char ft_memccpy_src[15]="1234567890";
	char ft_memccpy_dst[15]="";
	memccpy(ft_memccpy_dst, ft_memccpy_src,'1', 10);
	printf("ft_memccpy_dst: %s\n", ft_memccpy_dst);

	printf("---------------------------------------\n");
	printf("ft_memmove VS memmove (3)\n");

	char memmove_test[10] = "123456789";
	printf("src old: %s\n", memmove_test);
	memmove(&memmove_test[4], &memmove_test[3], 3);
	printf("src new: %s\n", memmove_test);
	memmove(&memmove_test[2], &memmove_test[3], 3);
	printf("src new: %s\n", memmove_test);

	char ft_memmove_test[10] = "123456789";
	printf("src old: %s\n", ft_memmove_test);
	ft_memmove(&ft_memmove_test[4], &ft_memmove_test[3], 3);
	printf("src new: %s\n", ft_memmove_test);
	ft_memmove(&ft_memmove_test[2], &ft_memmove_test[3], 3);
	printf("src new: %s\n", ft_memmove_test);

	printf("---------------------------------------\n");
	printf("ft_memchr VS memchr (3)\n");

	char memchr_test[15] = "1234567890";
	char *memchr_t;
	printf("memchr_test old: %s\n", memchr_test);
	memchr_t = memchr(memchr_test, '3', 10);
	if (memchr_t != NULL)
		memchr_t[0] = '!';
	printf("memchr_test new: %s\n", memchr_test);

	char ft_memchr_test[15] = "1234567890";
	char *ft_memchr_t;
	printf("ft_memchr_test old: %s\n", ft_memchr_test);
	ft_memchr_t = ft_memchr(ft_memchr_test, '3', 10);
	if (ft_memchr_t != NULL)
		ft_memchr_t[0] = '!';
	printf("ft_memchr_test new: %s\n", ft_memchr_test);

	printf("---------------------------------------\n");
	printf("ft_memcmp VS memcmp (3)\n");

	unsigned char test1_memcmp[] = "1234567890";
	unsigned char test2_memcmp[] = "1234567890";
	if (memcmp(test1_memcmp, test2_memcmp, 10) == 0)
		printf("[OK]\t%d\n", memcmp(test1_memcmp, test2_memcmp, 10));
	else
		printf("[-KO-]\t%d\n", memcmp(test1_memcmp, test2_memcmp, 10));

	unsigned char test1_ft_memcmp[15] = "1234567890";
	unsigned char test2_ft_memcmp[15] = "1234567890";
	if (ft_memcmp(test1_ft_memcmp, test2_ft_memcmp, 10) == 0)
		printf("[OK]\t%d\n", ft_memcmp(test1_ft_memcmp, test2_ft_memcmp, 10));
	else
		printf("[-KO-]\t%d\n", ft_memcmp(test1_ft_memcmp, test2_ft_memcmp, 10));

	printf("---------------------------------------\n");
	printf("ft_strdup VS strdup (3)\n");

	char strdup_test[11] = "1234567890";
	char *istrdup_test;
	istrdup_test = strdup(strdup_test);
	printf(" strdup_test = %s\nistrdup_test = %s\n", strdup_test, istrdup_test);
	free(istrdup_test);

	char ft_strdup_test[11] = "1234567890";
	char *ift_strdup_test;
	ift_strdup_test = strdup(ft_strdup_test);
	printf(" ft_strdup_test = %s\nift_strdup_test = %s\n", ft_strdup_test, ift_strdup_test);
	free(ift_strdup_test);

	printf("---------------------------------------\n");
	printf("ft_strlen VS strlen (3)\n");

	char strlen_test[][10] = {{"qwerty"}, {"zxc"}, {"asueijfa"}};
	i = 0;
	j = 0;
	while (i < 3)
	{
		if (strlen(strlen_test[i]) == ft_strlen(strlen_test[i]))
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t(%lu vs %lu)\t%s\n", ft_strlen(strlen_test[i]), strlen(strlen_test[i]), strlen_test[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_strcpy VS strcpy (3)\n");

	char test_strcpy_dst[] = "fffffffff";
	char test_strcpy_src[] = "";
	printf("original old: %s %s\n", test_strcpy_dst, test_strcpy_src);
	strcpy(test_strcpy_dst, test_strcpy_src);
	printf("original new: %s %s\n\n", test_strcpy_dst, test_strcpy_src);

	char test_ft_strcpy_dst[] = "fffffffff";
	char test_ft_strcpy_src[] = "";
	printf("prototype old: %s %s\n", test_ft_strcpy_dst, test_ft_strcpy_src);
	ft_strcpy(test_ft_strcpy_dst, test_ft_strcpy_src);
	printf("prototype new: %s %s\n", test_ft_strcpy_dst, test_ft_strcpy_src);

	printf("---------------------------------------\n");
	printf("ft_strncpy VS strncpy (3)\n");

	char test_strncpy_src[11] = "12345\06789";
	char test_strncpy_dst1[11] = "1111111111";
	char test_strncpy_dst2[11] = "1111111111";
	printf("%s\n", test_strncpy_src);
	strncpy(test_strncpy_dst1, test_strncpy_src, 3);
	printf("%s\n", test_strncpy_dst1);
	strncpy(test_strncpy_dst2, test_strncpy_src, 7);
	printf("%s\n", test_strncpy_dst2);

	printf("---------------------------------------\n");
	printf("ft_strcat VS strcat (3)\n");

	char test_strcat_app[1024] = "123456789";
	char test_strcat_dst[1024] = "abcdifghi ";
	strcat(test_strcat_dst, test_strcat_app);
	printf("test_strcat_dst: %s\n", test_strcat_dst);

	char test_ft_strcat_app[1024] = "123456789";
	char test_ft_strcat_dst[1024] = "abcdifghi ";
	ft_strcat(test_ft_strcat_dst, test_ft_strcat_app);
	printf("test_ft_strcat_dst: %s\n", test_ft_strcat_dst);

	printf("---------------------------------------\n");
	printf("ft_strncat VS strncat (3)\n");

	char test_strncat_src1[10] = "000";
	char test_strncat_src2[10] = "000";
	char test_strncat_app[1024] = "12345";
	printf("test_strncat_dst: %s\n", test_strncat_app);
	strncat(test_strncat_src1, test_strncat_app, 3);
	printf("test_strncat_src1: %s\n", test_strncat_src1);
	strncat(test_strncat_src2, test_strncat_app, 7);
	printf("test_strncat_src2: %s\n", test_strncat_src2);

	char test_ft_strncat_src1[10] = "000";
	char test_ft_strncat_src2[10] = "000";
	char test_ft_strncat_app[1024] = "12345";
	printf("test_ft_strncat_dst: %s\n", test_ft_strncat_app);
	ft_strncat(test_ft_strncat_src1, test_ft_strncat_app, 3);
	printf("test_ft_strncat_src1: %s\n", test_ft_strncat_src1);
	ft_strncat(test_ft_strncat_src2, test_ft_strncat_app, 7);
	printf("test_ft_strncat_src2: %s\n", test_ft_strncat_src2);

	printf("---------------------------------------proverit'\n");
	printf("ft_strlcat VS strlcat (3)\n");

	char test_strlcat_src1[10] = "000";
	char test_strlcat_src2[10] = "000";
	char test_strlcat_app[10] = "12345";
	size_t temp_strlcat;
	printf("test_strlcat_dst: %s\n", test_strlcat_app);
	temp_strlcat = strlcat(test_strlcat_src1, test_strlcat_app, 3);
	printf("test_strlcat_src1: %s, %zu\n", test_strlcat_src1, temp_strlcat);
	temp_strlcat = strlcat(test_strlcat_src2, test_strlcat_app, 7);
	printf("test_strlcat_src2: %s, %zu\n", test_strlcat_src2, temp_strlcat);

	char test_ft_strlcat_src1[10] = "000";
	char test_ft_strlcat_src2[10] = "000";
	char test_ft_strlcat_app[10] = "12345";
	size_t temp_ft_strlcat;
	printf("test_ft_strlcat_dst: %s\n", test_ft_strlcat_app);
	temp_ft_strlcat = ft_strlcat(test_ft_strlcat_src1, test_ft_strlcat_app, 3);
	printf("test_ft_strlcat_src1: %s, %zu\n", test_ft_strlcat_src1, temp_ft_strlcat);
	temp_ft_strlcat = ft_strlcat(test_ft_strlcat_src2, test_ft_strlcat_app, 7);
	printf("test_ft_strlcat_src2: %s, %zu\n", test_ft_strlcat_src2, temp_ft_strlcat);

	printf("---------------------------------------\n");
	printf("ft_strchr VS strchr (3)\n");

	char test_strchr[11] = "126456789";
	char *temp_strchr;
	temp_strchr = strchr(test_strchr, '6');
	if (temp_strchr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_strchr - test_strchr + 1);

	char test_ft_strchr[11] = "126456789";
	char *temp_ft_strchr;
	temp_ft_strchr = ft_strchr(test_ft_strchr, '6');
	if (temp_ft_strchr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_ft_strchr - test_ft_strchr + 1);

	printf("---------------------------------------\n");
	printf("ft_strrchr VS strrchr (3)\n");

	char test_strrchr[11] = "126456789";
	char *temp_strrchr;
	temp_strrchr = strrchr(test_strrchr, '6');
	if (temp_strrchr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_strrchr - test_strrchr + 1);

	char test_ft_strrchr[11] = "126456789";
	char *temp_ft_strrchr;
	temp_ft_strrchr = ft_strrchr(test_ft_strrchr, '6');
	if (temp_ft_strrchr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_ft_strrchr - test_ft_strrchr + 1);

	printf("---------------------------------------\n");
	printf("ft_strstr VS strstr (3)\n");

	char test_strstr_str1 [11] = "123456789";
	char test_strstr_str2 [10] = "789";
	char *temp_strstr = strstr(test_strstr_str1, test_strstr_str2);
	if (temp_strstr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_strstr - test_strstr_str1 + 1);

	char test_ft_strstr_str1 [11] = "123456789";
	char test_ft_strstr_str2 [10] = "789";
	char *temp_ft_strstr = ft_strstr(test_ft_strstr_str1, test_ft_strstr_str2);
	if (temp_ft_strstr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_ft_strstr - test_ft_strstr_str1 + 1);

	printf("---------------------------------------\n");
	printf("ft_strnstr VS strnstr (3)\n");

	char test_strnstr_str1 [11] = "123456789";
	char test_strnstr_str2 [10] = "34";
	char *temp_strnstr = strnstr(test_strnstr_str1, test_strnstr_str2, 4);
	if (temp_strnstr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_strnstr - test_strnstr_str1 + 1);

	char test_ft_strnstr_str1 [11] = "123456789";
	char test_ft_strnstr_str2 [10] = "34";
	char *temp_ft_strnstr = ft_strnstr(test_ft_strnstr_str1, test_ft_strnstr_str2, 4);
	if (temp_ft_strnstr == NULL)
		printf("NO\n");
	else
		printf("YES\t%ld\n", temp_ft_strnstr - test_ft_strnstr_str1 + 1);

	printf("---------------------------------------\n");
	printf("ft_strcmp VS strcmp (3)\n");

	char temp_strcmp_war_1[][1024] = {{"Aaa"},
									{"s"},
									{"bb"},
									{"1"},
									{"11"},
									{122},
									{""}};

	char temp_strcmp_war_2[][1024] = {{"Aaa"},
									{"ss"},
									{"b"},
									{"1"},
									{"11"},
									{122},
									{""}};

	int test_strcmp;
	int test_ft_strcmp;
	int rezult_strcmp_war;
	test_strcmp = 0;
	test_ft_strcmp = 0;
	rezult_strcmp_war = 0;
	i = 0;
	printf("result\t\tstrcmp\tft_strcmp\tstring1\tstring2\n");
	while (temp_strcmp_war_1[i][0])
	{
		if (temp_strcmp_war_1[i + 1][0] == '\0')
		{
			test_strcmp = strcmp(temp_strcmp_war_1[i + 1], temp_strcmp_war_2[0]);
			test_ft_strcmp = ft_strcmp(temp_strcmp_war_1[i + 1], temp_strcmp_war_2[0]);
			rezult_strcmp_war = test_strcmp - test_ft_strcmp;}
		else
		{
			test_strcmp = strcmp(temp_strcmp_war_1[i], temp_strcmp_war_2[i + 1]);
			test_ft_strcmp = ft_strcmp(temp_strcmp_war_1[i], temp_strcmp_war_2[i + 1]);
			rezult_strcmp_war = test_strcmp - test_ft_strcmp;
		}
		if (rezult_strcmp_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\t\"%s\"\n", \
			test_strcmp, \
			test_ft_strcmp, \
			temp_strcmp_war_1[i], \
			temp_strcmp_war_2[i]);
		i++;
	}


	char test_strcmp_str1[1024] = "11";
	char test_strcmp_str2[1014] = "11";
	int temp_strcmp;
	temp_strcmp = strcmp(test_strcmp_str1, test_strcmp_str2);
	if (temp_strcmp == 0)
		printf("YES\t%d\n", temp_strcmp);
	else
		printf("NO\t%d\n", temp_strcmp);

	char test_ft_strcmp_str1[1024] = "11";
	char test_ft_strcmp_str2[1014] = "11";
	int temp_ft_strcmp;
	temp_ft_strcmp = ft_strcmp(test_ft_strcmp_str1, test_ft_strcmp_str2);
	if (temp_ft_strcmp == 0)
		printf("YES\t%d\n", temp_ft_strcmp);
	else
		printf("NO\t%d\n", temp_ft_strcmp);

	printf("---------------------------------------\n");
	printf("ft_strncmp VS strncmp (3)\n");

	char test_strncmp_str1[1024] = "1";
	char test_strncmp_str2[1014] = "3";
	int temp_strncmp;
	temp_strncmp = strncmp(test_strncmp_str1, test_strncmp_str2, 30);
	if (temp_strncmp == 0)
		printf("YES\t%d\n", temp_strncmp);
	else
		printf("NO\t%d\n", temp_strncmp);

	char test_ft_strncmp_str1[1024] = "1";
	char test_ft_strncmp_str2[1014] = "3";
	int temp_ft_strncmp;
	temp_ft_strncmp = ft_strncmp(test_ft_strncmp_str1, test_ft_strncmp_str2, 30);
	if (temp_ft_strncmp == 0)
		printf("YES\t%d\n", temp_ft_strncmp);
	else
		printf("NO\t%d\n", temp_ft_strncmp);




	printf("---------------------------------------\n");
	printf("ft_atoi VS atoi (3)\n");

	char temp_atoi_war[][1024] = {{"1234"},
								{"0"},
								{"-0"},
								{"+0"},
								{"a123"},
								{"123"},
								{"++123"},
								{"+-123"},
								{"-+123"},
								{"--123"},
								{"+123"},
								{"-123"},
								{"+123sdf"},
								{"-123sdf"},
								{"+123 sdf"},
								{"-123 sdf"},
								{"- 123 sdf"},
								{"+ 123 sdf"},
								{" + 123 sdf"},
								{" - 123 sdf"},
								{" +123 sdf"},
								{" -123 sdf"},
								{" +123.4df"},
								{" -123.4df"},
								{" +0123.4df"},
								{" -0123.4df"},
								{" +0000123.4df"},
								{" -0000123.4df"},
								{" +00001203.4df"},
								{" -00001203.4df"},
								{"adf-123"},
								{"adf+123"},
								{"adf-123sdf"},
								{"adf+123sdf"},
								{"2222222222222"},
								{"-2222222222222"},
								{"222222222222222"},
								{"-222222222222222"},
								{"222222222222222222"},
								{"-222222222222222222"},
								{"2147483648"},
								{"2147483647"},
								{"−1147483647"},
								{"−2147483647"},
								{"−2147483648"},
								{"9223372036854775805"},
								{"9223372036854775806"},
								{"9223372036854775807"},
								{"−9223372036854775808"},
								{"−9223372036854775807"},
								{"−9223372036854775806"},
								{"9223372036854775808"},
								{"9223372036854775809"},
								{"9223372036854775810"},
								{"9223372036854775811"},
								{"9999372036854775810"},
								{"9999999999999999999"},
								{"10000000000000000000"},
								{"20000000000000000000"},
								{"30000000000000000000"},
								{"40000000000000000000"},
								{"−9223372036854775809"},
								{"22222222222222222222"},
								{"-22222222222222222221"},
								{" 123.45"},
								{" 1 23"},
								{""}};
	int test_atoi;
	int test_ft_atoi;
	int rezult_atoi_war;

	test_atoi = 0;
	test_ft_atoi = 0;
	rezult_atoi_war = 0;
	i = 0;
	printf("result\t\tatoi\tft_atoi\t\tstring\n");
	while (temp_atoi_war[i][0])
	{
		test_atoi = atoi(temp_atoi_war[i]);
		test_ft_atoi = ft_atoi(temp_atoi_war[i]);
		rezult_atoi_war = test_atoi - test_ft_atoi;
		if (rezult_atoi_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_atoi, \
			test_ft_atoi, \
			temp_atoi_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_isspace VS isspace (3)\n");

	int temp_isspace = isspace(2);
	printf("%d\n", temp_isspace);

	int temp_ft_isspace = ft_isspace(2);
	printf("%d\n", temp_ft_isspace);

	printf("---------------------------------------\n");
	printf("ft_isalpha VS isalpha (3)\n");

	char temp_isalpha_war[][1024] = {{"A"},
									{"s"},
									{"b"},
									{"1"},
									{"11"},
									{122},
									{""}};

	int test_isalpha;
	int test_ft_isalpha;
	int rezult_isalpha_war;
	test_isalpha = 0;
	test_ft_isalpha = 0;
	rezult_isalpha_war = 0;
	i = 0;
	printf("result\t\tisalpha\tft_isalpha\tstring\n");
	while (temp_isalpha_war[i][0])
	{
		test_isalpha = isalpha(temp_isalpha_war[i][0]);
		test_ft_isalpha = ft_isalpha(temp_isalpha_war[i][0]);
		rezult_isalpha_war = test_isalpha - test_ft_isalpha;
		if (rezult_isalpha_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_isalpha, \
			test_ft_isalpha, \
			temp_isalpha_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_isdigit VS isdigit (3)\n");

	char temp_isdigit_war[][1024] = {{"1"},
									{"A"},
									{"a"},
									{"00"},
									{"11"},
									{"!"},
									{"\t"},
									{122},
									{""}};

	int test_isdigit;
	int test_ft_isdigit;
	int rezult_isdigit_war;
	test_isdigit = 0;
	test_ft_isdigit = 0;
	rezult_isdigit_war = 0;
	i = 0;
	printf("result\t\tisdigit\tft_isdigit\tstring\n");
	while (temp_isdigit_war[i][0])
	{
		test_isdigit = isdigit(temp_isdigit_war[i][0]);
		test_ft_isdigit = ft_isdigit(temp_isdigit_war[i][0]);
		rezult_isdigit_war = test_isdigit - test_ft_isdigit;
		if (rezult_isdigit_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_isdigit, \
			test_ft_isdigit, \
			temp_isdigit_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_isalnum VS isalnum (3)\n");

	char temp_isalnum_war[][1024] = {{"1"},
									{"A"},
									{"a"},
									{"00"},
									{"066"},
									{"!"},
									{"\t"},
									{126},
									{""}};

	int test_isalnum;
	int test_ft_isalnum;
	int rezult_isalnum_war;
	test_isalnum = 0;
	test_ft_isalnum = 0;
	rezult_isalnum_war = 0;
	i = 0;
	printf("result\t\tisalnum\tft_isalnum\tstring\n");
	while (temp_isalnum_war[i][0])
	{
		test_isalnum = isalnum(temp_isalnum_war[i][0]);
		test_ft_isalnum = ft_isalnum(temp_isalnum_war[i][0]);
		rezult_isalnum_war = test_isalnum - test_ft_isalnum;
		if (rezult_isalnum_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_isalnum, \
			test_ft_isalnum, \
			temp_isalnum_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_isascii VS isascii (3)\n");

	char temp_isascii_war[][1024] = {{"1"},
									{17},
									{31},
									{32},
									{"sp"},
									{126},
									{127},
									{128},
									{"!"},
									{""}};

	int test_isascii;
	int test_ft_isascii;
	int rezult_isascii_war;
	test_isascii = 0;
	test_ft_isascii = 0;
	rezult_isascii_war = 0;
	i = 0;
	printf("result\t\tisascii\tft_isascii\tstring\n");
	while (temp_isascii_war[i][0])
	{
		test_isascii = isascii(temp_isascii_war[i][0]);
		test_ft_isascii = ft_isascii(temp_isascii_war[i][0]);
		rezult_isascii_war = test_isascii - test_ft_isascii;
		if (rezult_isascii_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_isascii, \
			test_ft_isascii, \
			temp_isascii_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_isprint VS isprint (3)\n");

	char temp_isprint_war[][1024] = {{"1"},
									{17},
									{31},
									{32},
									{"sp"},
									{126},
									{127},
									{128},
									{"!"},
									{""}};

	int test_isprint;
	int test_ft_isprint;
	int rezult_isprint_war;
	test_isprint = 0;
	test_ft_isprint = 0;
	rezult_isprint_war = 0;
	i = 0;
	printf("result\t\tisprint\tft_isprint\tstring\n");
	while (temp_isprint_war[i][0])
	{
		test_isprint = isprint(temp_isprint_war[i][0]);
		test_ft_isprint = ft_isprint(temp_isprint_war[i][0]);
		rezult_isprint_war = test_isprint - test_ft_isprint;
		if (rezult_isprint_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_isprint, \
			test_ft_isprint, \
			temp_isprint_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_toupper VS toupper (3)\n");

	char temp_toupper_war[][1024] = {{"1"},
									{17},
									{31},
									{32},
									{"sp"},
									{126},
									{127},
									{128},
									{"!"},
									{""}};

	int test_toupper;
	int test_ft_toupper;
	int rezult_toupper_war;
	test_toupper = 0;
	test_ft_toupper = 0;
	rezult_toupper_war = 0;
	i = 0;
	printf("result\t\ttoupper\tft_toupper\tstring\n");
	while (temp_toupper_war[i][0])
	{
		test_toupper = toupper(temp_toupper_war[i][0]);
		test_ft_toupper = ft_toupper(temp_toupper_war[i][0]);
		rezult_toupper_war = test_toupper - test_ft_toupper;
		if (rezult_toupper_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_toupper, \
			test_ft_toupper, \
			temp_toupper_war[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_tolower VS tolower (3)\n");

	char temp_tolower_war[][1024] = {{"1"},
									{17},
									{31},
									{32},
									{"sp"},
									{126},
									{127},
									{128},
									{"!"},
									{""}};

	int test_tolower;
	int test_ft_tolower;
	int rezult_tolower_war;
	test_tolower = 0;
	test_ft_tolower = 0;
	rezult_tolower_war = 0;
	i = 0;
	printf("result\t\ttolower\tft_tolower\tstring\n");
	while (temp_tolower_war[i][0])
	{
		test_tolower = tolower(temp_tolower_war[i][0]);
		test_ft_tolower = ft_tolower(temp_tolower_war[i][0]);
		rezult_tolower_war = test_tolower - test_ft_tolower;
		if (rezult_tolower_war == 0)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t%d\t\t\"%s\"\n", \
			test_tolower, \
			test_ft_tolower, \
			temp_tolower_war[i]);
		i++;
	}

	printf("\n**********P*A*R*T***I*I**************\n");

	printf("---------------------------------------\n");
	printf("ft_memalloc\n");

	printf("---------------------------------------\n");
	printf("ft_memdel\n");

	// char tmp_memdel_1[10] = "abc";
	// char *tmp_memdel_2;
	//
	// tmp_memdel_2 = &tmp_memdel_1;
	//
	// printf("temp_memdel_1 - %s\n", tmp_memdel_1);
	// ft_memdel(&tmp_memdel_2);
	// printf("temp_memdel_1 - %s\n", tmp_memdel_1);

	printf("---------------------------------------\n");
	printf("ft_strnew\n");

	char *ftsn;
	ftsn = ft_strnew(10);
	printf("%s\n", ftsn);

	printf("---------------------------------------\n");
	printf("ft_strdel\n");

	printf("---------------------------------------\n");
	printf("ft_strclr\n");

	char temp_strclr[] = "abcdefghi";
	//char	*str;
	// str = (char *)malloc(sizeof(*str) * 10);
	// if (!str)
	// 	return (0);
	printf("columns - 123456789\n");
	//ft_memset(temp_strclr, 'u', ft_strlen(temp_strclr));
	//str[9] = '\0';
	printf("start   - %s\n", temp_strclr);
	ft_strclr(temp_strclr);
	printf("finish  - %s\n", temp_strclr);

	printf("---------------------------------------\n");
	printf("ft_striter\n");

	printf("---------------------------------------\n");
	printf("ft_striteri\n");

	printf("---------------------------------------\n");
	printf("ft_strequ\n");

	printf("---------------------------------------\n");
	printf("ft_strnequ\n");

	char temp_strnequ_war_1[][1024] = {{"Aaa"},
									{"s"},
									{"bb"},
									{"1"},
									{"11"},
									{122},
									{"abcd"},
									{"abc"},
									{"abcd"},
									{"abcd"},
									{"Abcd"},
									{""}};

	char temp_strnequ_war_2[][1024] = {{"Aaa"},
									{"ss"},
									{"b"},
									{"1"},
									{"11"},
									{122},
									{"abcd"},
									{"abcd"},
									{"abc"},
									{"Abcd"},
									{"abcd"},
									{""}};
	int temp_strnequ_war_i[] = {1, 2, 3, 1, 0, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};

	int test_ft_strnequ;
	int rezult_strnequ_war;
	test_ft_strnequ = 0;
	rezult_strnequ_war = 0;
	i = 0;
	printf("result\t\tft_strnequ\tstring1\tstring2\tn\n");
	while (temp_strnequ_war_1[i][0])
	{
		test_ft_strnequ = ft_strnequ(temp_strnequ_war_1[i], temp_strnequ_war_2[i], temp_strnequ_war_i[1]);
		rezult_strnequ_war = test_ft_strnequ;
		if (rezult_strnequ_war == 1)
			printf("[OK]");
		else
			printf("[-KO-]");
		printf("\t\t%d\t\t\"%s\"\t\"%s\"\t%d\n", \
			test_ft_strnequ, \
			temp_strnequ_war_1[i], \
			temp_strnequ_war_2[i], \
			temp_strnequ_war_i[i]);
		i++;
	}

	printf("---------------------------------------\n");
	printf("ft_strsub\n");

	char temp_strsub_war[15] = "123456789";

	printf("%s\n", temp_strsub_war);

	printf("%s\n", ft_strsub(temp_strsub_war, 2, 4));

	printf("---------------------------------------\n");
	printf("ft_strjoin\n");

	char temp_ft_strjoin_war1[5] = "1234";
	char temp_ft_strjoin_war2[5] = "5678";
	char *rezult_ft_strjoin_war;
	rezult_ft_strjoin_war = temp_ft_strjoin_war1;
	printf("%s\n", rezult_ft_strjoin_war);
	rezult_ft_strjoin_war = ft_strjoin(temp_ft_strjoin_war1, temp_ft_strjoin_war2);
	printf("%s\n", rezult_ft_strjoin_war);


	printf("---------------------------------------\n");
	printf("ft_strtrim\n");

	char s1[] = "lorem amet ";
	char s2[] = "  abcde  /t ";
	//char	*strtrim;
	ft_strtrim(s1);
	ft_strtrim(s2);


	printf("---------------------------------------\n");
	printf("\n");

	printf("---------------------------------------\n");
	printf("ft_putchar VS putchar (3)\n");

	// char temp_putchar_war[][1024] = {{"1"},
	//								 {17},
	//								 {31},
	//								 {32},
	//								 {"sp"},
	//								 {126},
	//								 {127},
	//								 {128},
	//								 {"!"},
	//								 {""}};
	//
	// int test_putchar;
	// int test_ft_putchar;
	// int rezult_putchar_war;
	// test_putchar = 0;
	// test_ft_putchar = 0;
	// rezult_putchar_war = 0;
	// i = 0;
	// printf("result\t\tputchar\tft_putchar\tstring\n");
	// while (temp_putchar_war[i][0])
	// {
	//     test_putchar = putchar(temp_putchar_war[i][0]);
	//     test_ft_putchar = ft_putchar(temp_putchar_war[i][0]);
	//     rezult_putchar_war = test_putchar - test_ft_putchar;
	//     if (rezult_putchar_war == 0)
	//         printf("[OK]");
	//     else
	//         printf("[-KO-]");
	//     printf("\t\t%d\t%d\t\t\"%s\"\n", \
	//         test_putchar, \
	//         test_ft_putchar, \
	//         temp_putchar_war[i]);
	//     i++;
	// }
	printf("---------------------------------------\n");
	printf("ft_lstnew\n\n");

	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*tmp;


	char	str [] = "lorem";
	char	str2 [] = "ipsum";
	char	str3 [] = "dolor";
	char	str4 [] = "sit";
	elem = ft_lstnew(str, sizeof(str));
	elem2 = ft_lstnew(str2, sizeof(str2));
	elem3 = ft_lstnew(str3, sizeof(str3));
	elem4 = ft_lstnew(str4, sizeof(str4));
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	tmp = elem;

	while (elem)
	{
		printf("%s\t[%zu]\t%p\n", elem->content, elem->content_size, elem->next);
		elem = elem->next;
	}

	printf("---------------------------------------\n");
	printf("ft_lstmap\n\n");

	t_list	*list;

	list = ft_lstmap(tmp, &ft_map);
	if (list)
		while (list)
		{
			printf("%s\t[%zu]\t%p\n", list->content, list->content_size, list->next);
			list = list->next;
		}
	else
		printf("NULL\n");

	printf("---------------------------------------\n");
	printf("ft_strfree\n\n");

	char **test_ft_strfree;
	test_ft_strfree = ft_memalloc(sizeof(char*) * 4);
	test_ft_strfree[0] = (char*)malloc(sizeof(char) * 3);
	//test_ft_strfree[0] = "12";
	test_ft_strfree[1] = (char*)malloc(sizeof(char) * 4);
	test_ft_strfree[2] = (char*)malloc(sizeof(char) * 2);
	test_ft_strfree[3] = (char*)malloc(sizeof(char) * 5);
	//test_ft_strfree[3] = NULL;
	//char test_ft_strfree[4][3] = {{"123"}, {"456"}, {"789"}, NULL};
	//char *test_ft_strfree[3] = {{"123"}, {"456"}, {"789"}, {NULL}};
	if (test_ft_strfree)
		printf("[OK]\n");
	ft_strfree(test_ft_strfree, 4);
	if (test_ft_strfree)
		printf("[OK]\n");

	return (0);
}
