#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

TestSuite(ft_dvec_del);

static void	clean(void **el)
{
	free(*el);
	*el = NULL;
}

Test(ft_dvec_del, test_del)
{
	t_dvec	dvec;
	char	*s;

	s = ft_strdup("Hello world");

	ft_dvec_make(&dvec, VECTOR_DEFAULT_CAP);
	dvec.val[0] = s;
	dvec.len = 1;

	ft_dvec_del(&dvec, 0, &clean);
	cr_expect(!dvec.val[0], "Expected NULL at index 0 after cleanup:\nWas: %p\nExpected: %p", dvec.val[0], NULL);

	if (dvec.val[0])
		free(dvec.val[0]);
}
