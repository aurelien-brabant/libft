#include <criterion/criterion.h>
#include "libft/string.h"

TestSuite(ft_string);

Test(ft_string, ft_string_new_cstr)
{
	const char	*cstr = "Hello world\n";
	char		*actual = NULL;
	t_string str = ft_string_new_cstr(cstr);

	actual = ft_string_tocstring(str);

	cr_expect_str_eq(actual, cstr);
	free(actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_new_fill)
{
	const char	*ref = "xxxxxxxxxx";
	char		*actual = NULL;
	t_string str = ft_string_new_fill(10, 'x');

	actual = ft_string_tocstring(str);

	cr_expect_str_eq(actual, ref);
	free(actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_append_cstr)
{
	const char	*strs[] = { "Hello", " world", " how", " are", " you ?", NULL };
	char		*ref = "Hello world how are you ?";
	char		*actual = NULL;

	t_string str = ft_string_new_cstr(strs[0]);

	/* append */
	for (size_t i = 1; strs[i] != NULL; ++i) {
		ft_string_append_cstr(str, strs[i]);
	}

	actual = ft_string_tocstring(str);

	cr_expect_str_eq(actual, ref);
	free(actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_append)
{
	const char	*strs[] = { "Hello", " world", " how", " are", " you ?" };
	t_string	tstrings[5];
	size_t		nb = sizeof (strs) / sizeof (char *);
	char		*ref = "*** Hello world how are you ?";
	char		*actual = NULL;

	/* Starting tstring */
	t_string str = ft_string_new_cstr("*** ");

	/* create tstrings */
	for (size_t i = 0; i < nb; ++i) {
		tstrings[i] = ft_string_new_cstr(strs[i]);
	}
	/* append tstrings to string */
	for (size_t i = 0; i < nb; ++i) {
		ft_string_append(str, tstrings[i]);
	}

	/* compare with ref */
	actual = ft_string_tocstring(str);
	cr_expect_str_eq(actual, ref);

	/* cleanup */
	free(actual);
	for (size_t i = 0; i < nb; ++i) {
		ft_string_destroy(tstrings[i]);
	}
	ft_string_destroy(str);
}

Test(ft_string, ft_string_at)
{
	const char		*ref = "00000000000";
	char			*actual = NULL;
	t_string		str = ft_string_new_cstr("Hello world");
	
	for (size_t i = 0; i < ft_string_length(str); ++i) {
		*ft_string_at(str, i) = '0';
	}
	actual = ft_string_tocstring(str);
	cr_expect_str_eq(actual, ref);

	free(actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_reserve)
{
	const char	*ref = "xxxxxxxxxx";
	const char	*actual = NULL;
	t_string	str = ft_string_new_fill(10, 'x');

	/* ensure capacity is indeed 10 */
	cr_expect_eq(ft_string_capacity(str), 10);

	/* now reserve more */
	ft_string_reserve(str, 50);

	/* ensure it has been reserved properly */
	cr_expect_eq(ft_string_capacity(str), 50);
	actual = ft_string_tocstring(str);
	cr_expect_str_eq(actual, ref);

	/* Try to reserve less than occupied by the string (less than length) */
	ft_string_reserve(str, 9);
	cr_expect_eq(ft_string_capacity(str), 50);

	/* Attempt to write on reserved spaces, just to ensure the space is allocated */
	for (int i = 10; i < 50; ++i) {
		*ft_string_at(str, i) = 0;
	}

	free((void *)actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_replacechar)
{
	char		*ref = "ababababab";
	char		*actual = NULL;
	t_string	str = ft_string_new_cstr("xbxbxbxbxb");

	ft_string_replacechar(str, 'x', 'a');
	actual = ft_string_tocstring(str);

	cr_expect_str_eq(actual, ref);

	free(actual);
	ft_string_destroy(str);
}

Test(ft_string, ft_string_findchar)
{
	int			ref = 4;
	t_string	str = ft_string_new_cstr("HellO world");

	cr_expect_eq(ft_string_findchar(str, 'O'), ref);
	ref = -1;
	cr_expect_eq(ft_string_findchar(str, 'x'), ref);

	ft_string_destroy(str);
}



