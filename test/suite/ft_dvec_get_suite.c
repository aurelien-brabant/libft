#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_dvec_get);

Test(ft_dvec_get, test_get)
{
	t_dvec	dvec;
	char	*s;

	ft_dvec_make(&dvec, VECTOR_DEFAULT_CAP); //Set the capacity to 10.
	dvec.val[0] = "string1";
	dvec.val[1] = "string2";
	dvec.len = 2;

	s = ft_dvec_get(&dvec, 1);
	cr_assert(s == dvec.val[1], "Failed to retrieve correct item at index 1:\nWas: %p\nExpected: %p", s, dvec.val[1]);
	free(dvec.val);
}

Test(ft_dvec_get, test_out_of_bounds)
{
	t_dvec	dvec;
	char	*s;

	ft_dvec_make(&dvec, VECTOR_DEFAULT_CAP); //Set the capacity to 10.
	dvec.val[0] = "string1";
	dvec.val[1] = "string2";
	dvec.len = 2;

	s = ft_dvec_get(&dvec, 2);
	cr_assert(!s, "Something else that NULL has been returned, but index is out of bounds:\nWas: %p\nExpected: %p", s, NULL);
	free(dvec.val);
}
