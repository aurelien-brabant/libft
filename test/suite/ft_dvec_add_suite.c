#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_dvec_add);

Test(ft_dvec_add, test_add)
{
	t_dvec	dvec;
	char	*s;

	s = ft_strdup("Hello world");

	ft_dvec_make(&dvec, VECTOR_DEFAULT_CAP);
	ft_dvec_add(&dvec, s);

	cr_expect(s == dvec.val[0], "Could not retrieve expected element at index 0:\nWas: %p\nExpected: %p", dvec.val[0], s);

	free(s);
	free(dvec.val);
}

Test(ft_dvec_add, test_resize)
{
	t_dvec	dvec;
	char	*s1 = "Hello world";
	char	*s2 = "How are you";

	ft_dvec_make(&dvec, 1); //Set the capacity to 1.
	ft_dvec_add(&dvec, s1);
	ft_dvec_add(&dvec, s2);

	cr_expect(s1 == dvec.val[0], "Could not retrieve expected element at index 0:\nWas: %p\nExpected: %p", dvec.val[0], s1);
	cr_expect(s2 == dvec.val[1], "Could not retrieve expected element at index 1:\nWas: %p\nExpected: %p", dvec.val[1], s2);

	free(dvec.val);
}
