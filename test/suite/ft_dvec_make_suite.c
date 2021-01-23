#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_dvec_make);

Test(ft_dvec_make, test_make)
{
	t_dvec	dvec;

	ft_dvec_make(&dvec, 2); //Set the capacity to 10.
	cr_expect(dvec.cap == 2, "dvec.cap member not set properly:\nWas: %ld\nExpected: %ld", dvec.cap, (size_t)2);
	cr_expect(dvec.len == 0, "dvec.len member not set properly:\nWas: %ld\nExpected: %ld", dvec.len, (size_t)0);
	dvec.val[0] = "This should not segfault1";
	dvec.val[1] = "This should not segfault2";
	free(dvec.val);
}

Test(ft_dvec_make, test_make_auto)
{
	t_dvec	dvec;

	ft_dvec_make(&dvec, 0); //Set the capacity to default.
	cr_expect(dvec.cap == VECTOR_DEFAULT_CAP, "dvec.cap member not set properly:\nWas: %ld\nExpected: %ld", dvec.cap, (size_t)VECTOR_DEFAULT_CAP);
	cr_expect(dvec.len == 0, "dvec.len member not set properly:\nWas: %ld\nExpected: %ld", dvec.len, (size_t)0);
	dvec.val[0] = "This should not segfault1";
	dvec.val[1] = "This should not segfault2";
	dvec.val[2] = "This should not segfault3";
	dvec.val[3] = "This should not segfault4";
	free(dvec.val);
}
