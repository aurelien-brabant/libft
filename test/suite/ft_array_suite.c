#include <criterion/criterion.h>
#include "libft.h"
#include "libft/array.h"

TestSuite(ft_array);

/********************************************************************
************************* HELPERS ***********************************
*********************************************************************/

static int	cmp_uint(void *el1, void *el2)
{
	return (*(int *)el1 - *(int *)el2);
}

/*
** Ensure main functions of an array are handled correctly
*/

/*
** Test array creation, append, destruction (with resize). If any of these
** functions is not working properly, that's really annoying.
*/


Test(ft_array, test_array_core)
{
	t_array	a;
	int		el[] = { 1, 2, 3, 4, 5 };
	int		size = sizeof (el) / sizeof (int);

	a = ft_array_new(1);
	for (int i = 0; i < size; ++i) {
		ft_array_append(a, &el[i]);
	}
	for (int i = 0; i < size; ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), el[i]);
	}
	ft_array_destroy(a, NULL);
}

/*
** Insert the distinctive value -1 at the beginning and the end of the array,
** as well as in the middle of it.
** Ensure insertion was successful.
*/

Test(ft_array, test_array_insert)
{
	t_array	a;
	int		el[] = { 1, 12, 3, 4, 5, 6 };
	int		expected[] = { -1, 1, -1, 12, 3, 4, 5, 6, -1 };
	int		inserted = -1;
	int		actual;

	a = ft_array_new(10);
	for (int i = 0; i < (int)(sizeof (el) / sizeof (int)); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_insert(a, &inserted, 0);
	ft_array_insert(a, &inserted, 2);
	ft_array_insert(a, &inserted, sizeof (el) / sizeof (int) + 2);
	for (int i = 0; i < (int)(sizeof (expected) / sizeof (int)) ; ++i) {
		actual = *(int *)ft_array_get(a, i);
		cr_expect_eq(actual, expected[i], "for i == %d (%d != %d)\n", i, actual, expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/*
** Set all elements of the array to set, which has the distinctive value -1.
*/

Test(ft_array, test_array_set)
{
	t_array	a;
	int		el[] = { 1, 2, 3, 4, 5 };
	int		size = sizeof (el) / sizeof (int);
	int		set = -1;

	a = ft_array_new(5);
	for (int i = 0; i < size; ++i) {
		ft_array_append(a, &el[i]);
		ft_array_set(a, &set, i);
	}
	for (int i = 0; i < size; ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), set);
	}
	ft_array_destroy(a, NULL);
}

/* Test substraction operation */

Test(ft_array, test_array_sub)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	subed;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3 };
	int		expected[] = { 1, 4, 5 };

	/* test */

	a = ft_array_new(5);
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (int i = 0; i < (int)(sizeof (el) / sizeof (int)); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (int i = 0; i < (int)(sizeof (subset) / sizeof (int)); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	subed = ft_array_sub(a, sub, &cmp_uint);
	/* Test subed array */
	for (int i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(subed, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(subed, NULL);
}
