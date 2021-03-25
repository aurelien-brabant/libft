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
