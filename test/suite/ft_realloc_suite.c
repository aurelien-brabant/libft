#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_realloc);

Test(ft_realloc, test_basic)
{
	char	*ref = "Hello worldHello world";
	char	*s = 0;

	s = strdup("Hello world");
	s = ft_realloc(s, strlen(s), strlen(s) * 2 + 1);
	strcat(s, "Hello world");
	cr_assert(strcmp(s, ref) == 0, "Reallocation failed:\nWas:\"%s\"\nExpected:\"%s\"", s, ref);
}
