#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_dvec_destroy);

static void	clean(void **el)
{
	free(*el);
	*el = NULL;
}

Test(ft_dvec_destroy, test_destroy)
{
	t_dvec	dvec;
	void	**v1;
	void	**v2;

	ft_dvec_make(&dvec, VECTOR_DEFAULT_CAP);
	dvec.val[0] = strdup("string 1");
	dvec.val[1] = strdup("string 2");
	dvec.len = 2;

	ft_dvec_destroy(&dvec, &clean);
	cr_assert(dvec.len == 0, "After destroy, dvector len found to be non-zero:\nWas: %ld\nExpected: %d", dvec.len, 0);
	cr_assert(dvec.cap == 0, "After destroy, dvector cap found to be non-zero:\nWas: %ld\nExpected: %d", dvec.cap, 0);
}
