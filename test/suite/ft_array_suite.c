#include <criterion/criterion.h>
#include "libft.h"
#include "libft/array.h"

/*
██╗  ██╗███████╗██╗     ██████╗ ███████╗██████╗ ███████╗
██║  ██║██╔════╝██║     ██╔══██╗██╔════╝██╔══██╗██╔════╝
███████║█████╗  ██║     ██████╔╝█████╗  ██████╔╝███████╗
██╔══██║██╔══╝  ██║     ██╔═══╝ ██╔══╝  ██╔══██╗╚════██║
██║  ██║███████╗███████╗██║     ███████╗██║  ██║███████║
╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝
*/

static int	cmp_uint(void *el1, void *el2)
{
	return (*(int *)el1 - *(int *)el2);
}

/*
████████╗███████╗███████╗████████╗███████╗
╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝
   ██║   █████╗  ███████╗   ██║   ███████╗
   ██║   ██╔══╝  ╚════██║   ██║   ╚════██║
   ██║   ███████╗███████║   ██║   ███████║
   ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝
*/

TestSuite(ft_array);

/*
** Test array creation, append, destruction (with resize). If any of these
** functions is not working properly, that's really annoying.
*/

Test(ft_array, test_array_core)
{
	t_array	a;
	int		el[] = { 1, 2, 3, 4, 5 };

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), el[i]);
	}
	ft_array_destroy(a, NULL);
}

Test(ft_array, test_array_delete)
{
	t_array	a;
	int		el[] = { 1, 2, 3, 4, 5 };

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	for (size_t i = 0; i < ft_array_get_length(a) - 1;) {
		ft_array_delete(a, i, NULL);
	}
	cr_expect_eq(*(int *)ft_array_get(a, 0), el[4]);
	ft_array_destroy(a, NULL);
}

Test(ft_array, test_array_delete_fn)
{
	t_array	a;
	char	*el[] = { "str1", "str2", "str3", "str4", "str5" };

	a = ft_array_new(sizeof (el) / sizeof (char *));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, strdup(el[i]));
	}
	/* Delete every element expect the last */
	for (size_t i = 0; i < ft_array_get_length(a) - 1;) {
		ft_array_delete(a, i, &free);
	}
	cr_expect_str_eq(ft_array_get(a, 0), el[4]);
	ft_array_destroy(a, &free);
}

/*
** Insert the distinctive value -1 at the beginning and the end of the array,
** as well as in the middle of it.
*/

Test(ft_array, test_array_insert)
{
	t_array	a;
	int		el[] = { 1, 12, 3, 4, 5, 6 };
	int		expected[] = { -1, 1, -1, 12, 3, 4, 5, 6, -1 };
	int		inserted = -1;
	int		actual;

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_insert(a, &inserted, 0);
	ft_array_insert(a, &inserted, 2);
	ft_array_insert(a, &inserted, ft_array_get_length(a));

	size_t expected_size = sizeof (expected) / sizeof (int); 
	for (size_t i = 0; i < expected_size ; ++i) {
		actual = *(int *)ft_array_get(a, i);
		cr_expect_eq(actual, expected[i], "for i == %ld (%d != %d)\n", i, actual, expected[i]);
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
	int		set = -1;

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
		ft_array_set(a, &set, i);
	}
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
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

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	subed = ft_array_sub(a, sub, &cmp_uint);
	/* Test subed array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(subed, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(subed, NULL);
}

/* FOREACH TEST: basic sum function */

int	add_to_sum(void *el, int i, void *actual)
{
	(void)i;
	*(int *)actual += *(int *)el;
	return (0);
}

Test(ft_array, test_array_foreach)
{
	int		el[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t	sum_up_to = sizeof(el) / sizeof (int);
	int		sum = (sum_up_to * (sum_up_to + 1)) / 2;
	int		actual = 0;
	t_array	a;

	a = ft_array_new(sum_up_to);
	for (size_t i = 0; i < sum_up_to; ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_foreach(a, &add_to_sum, &actual);
	cr_expect_eq(actual, sum, "%d != %d\n", actual, sum);
	ft_array_destroy(a, NULL);
}

/* INTER operation test */

Test(ft_array, test_array_inter)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	subed;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3 };
	int		expected[] = { 2, 3 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	subed = ft_array_inter(a, sub, &cmp_uint);
	/* Test subed array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(subed, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(subed, NULL);
}

/* UNION operation test */

Test(ft_array, test_array_union)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	_union;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3, 8, 4 };
	int		expected[] = { 1, 2, 3, 4, 5, 8 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	_union = ft_array_union(a, sub, &cmp_uint);
	/* Test _union array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(_union, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(_union, NULL);
}

/* DUPLICATION */

Test(ft_array, test_array_dup)
{
	/* arrays involved in test */

	t_array	a;
	t_array	dup;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	dup = ft_array_dup(a);
	/* Test dup array */
	for (size_t i = 0; i < ft_array_get_length(dup); ++i) {
		cr_expect_eq(*(int *)ft_array_get(dup, i), el[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(dup, NULL);
}

/* CONCATENATION */

Test(ft_array, test_array_concat)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	concat;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3, 8, 4 };
	int		expected[] = { 1, 2, 3, 4, 5, 2, 3, 8, 4 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	concat = ft_array_concat(a, sub);
	/* Test concat array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(concat, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(concat, NULL);
}

/* REVERSE */

Test(ft_array, test_array_reverse)
{
	t_array	a;

	int	el[] = { 1, 2, 3, 4, 5 };
	int	expected[] = { 5, 4, 3, 2, 1 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_reverse(a);
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* LEFT SHIFT */

Test(ft_array, test_shift_left)
{
	t_array	a;

	int	el[] = { 1, 2, 3, 4, 5 };
	int	expected[] = { 4, 5, 0, 0, 0 };
	int	shift_amount = 3;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_shift(a, -1, shift_amount);
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		/* if expected value is zero, it means tha NULL pointer is expected (not the number zero itself) */
		if (expected[i] == 0)
			cr_expect_null(ft_array_get(a, i));
		else
			cr_expect_eq(*(int *)ft_array_get(a, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* RIGHT SHIFT */

Test(ft_array, test_right_shift)
{
	t_array	a;

	int		el[] = { 7, 2, 24, 4, 5 };
	int		expected[] = { 0, 0, 0, 0, 7 };
	size_t	shift_amount = 4;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_shift(a, 1, shift_amount);
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		/* if expected value is zero, it means tha NULL pointer is expected (not the number zero itself) */
		if (expected[i] == 0)
			cr_expect_null(ft_array_get(a, i));
		else
			cr_expect_eq(*(int *)ft_array_get(a, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* LEFT ROTATE */

Test(ft_array, test_left_rotate)
{
	t_array	a;

	int	el[] = { 1, 2, 18, 4, 5 };
	int	expected[] = { 18, 4, 5, 1, 2 };
	int	rot_amount = 2;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_rotate(a, -1, rot_amount);
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* RIGHT ROTATE */

Test(ft_array, test_right_rotate)
{
	t_array	a;

	int	el[] = { 1, 2, 3, 43, 5 };
	int	expected[] = { 3, 43, 5, 1, 2 };
	int	rot_amount = 3;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	ft_array_rotate(a, 1, rot_amount);
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		cr_expect_eq(*(int *)ft_array_get(a, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* LINEAR SEARCH */

Test(ft_array, test_linsearch)
{
	t_array	a;

	int	el[] = { 54, 12, 3, 32, 5 };
	int	searched = 32;
	int	expected = 3;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Test one present value */
	cr_expect_eq(ft_array_linsearch(a, &searched, &cmp_uint), expected);

	/* Test one missing value */
	expected = -1;
	searched = 456;
	cr_expect_eq(ft_array_linsearch(a, &searched, &cmp_uint), expected);
	ft_array_destroy(a, NULL);
}

Test(ft_array, test_uniq)
{
	t_array	a;

	int	notuniq[] = { 54, 12, 3, 32, 12, 5, 5, 2 };
	int	uniq[] = { 54, 12, 3, 32, 5, 2, 0, 1, 15, 14, 13 };
	int	expected = 4;

	/* test */

	/* TEST NOT UNIQ ARRAY */

	a = ft_array_new(sizeof (notuniq) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &notuniq[i]);
	}
	cr_expect_eq(ft_array_uniq(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);

	/* TEST UNIQ ARRAY */

	a = ft_array_new(sizeof (notuniq) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &uniq[i]);
	}
	expected = -1;
	cr_expect_eq(ft_array_uniq(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);
}

/* Sorted insertion in an array */

Test(ft_array, test_sinsert)
{
	t_array	a;
	int		el[] = { 1, 2, 5, 12, 24, 36 };
	int		insert_set[] = { 13, 4, 0, 4 };
	int		expected[] = { 0, 1, 2, 4, 4, 5, 12, 13, 24, 36 };
	int		actual;

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}

	/* The array should remain sorted even if insert_set is unsorted */
	for (size_t i = 0; i < (int)(sizeof (insert_set) / sizeof (int)); ++i) {
		ft_array_sinsert(a, &insert_set[i], &cmp_uint);
	}

	size_t expected_size = sizeof (expected) / sizeof (int); 
	for (size_t i = 0; i < expected_size ; ++i) {
		actual = *(int *)ft_array_get(a, i);
		cr_expect_eq(actual, expected[i], "for i == %ld (%d != %d)\n", i, actual, expected[i]);
	}
	ft_array_destroy(a, NULL);
}

/* Sorted union */

Test(ft_array, test_array_sunion)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	_union;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3, 4, 8 };
	int		expected[] = { 1, 2, 3, 4, 5, 8 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	_union = ft_array_sunion(a, sub, &cmp_uint);
	/* Test _union array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(_union, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(_union, NULL);
}

/* Sorted inter */

Test(ft_array, test_array_sinter)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	subed;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3 };
	int		expected[] = { 2, 3 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	subed = ft_array_sinter(a, sub, &cmp_uint);
	/* Test subed array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(subed, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(subed, NULL);
}

/* Sorted sub */

Test(ft_array, test_array_ssub)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	subed;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 4, 5 };
	int		subset[] = { 2, 3, 4 };
	int		expected[] = { 1, 5 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (subset) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &subset[i]);
	}
	subed = ft_array_ssub(a, sub, &cmp_uint);
	/* Test subed array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(subed, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(subed, NULL);
}

/* Merge sorted arrays */

Test(ft_array, test_array_merge)
{
	/* arrays involved in test */

	t_array	a;
	t_array	sub;
	t_array	merged;

	/* reference integer sets */

	int		el[] = { 1, 2, 3, 12, 18, 23, 45 };
	int		el2[] = { 5, 6 };
	int		expected[] = { 1, 2, 3, 5, 6, 12, 18, 23, 45 };

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	sub = ft_array_new(sizeof (el2) / sizeof (int));
	/* Populate a */
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Populate sub */
	for (size_t i = 0; i < ft_array_capacity(sub); ++i) {
		ft_array_append(sub, &el2[i]);
	}
	merged = ft_array_merge(a, sub, &cmp_uint);
	/* Test merged array */
	for (size_t i = 0; i < (int)(sizeof (expected) / sizeof (int)); ++i) {
		cr_expect_eq(*(int *)ft_array_get(merged, i), expected[i]);
	}
	ft_array_destroy(a, NULL);
	ft_array_destroy(sub, NULL);
	ft_array_destroy(merged, NULL);
}

/* BINARY SEARCH */

Test(ft_array, test_binsearch)
{
	t_array	a;

	int	el[] = { 3, 5, 12, 32, 54 };
	int	searched = 5;
	int	expected = 1;

	/* test */

	a = ft_array_new(sizeof (el) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &el[i]);
	}
	/* Test one present value */
	cr_expect_eq(ft_array_binsearch(a, &searched, &cmp_uint), expected);

	/* Test one missing value */
	expected = -1;
	searched = 456;
	cr_expect_eq(ft_array_binsearch(a, &searched, &cmp_uint), expected);
	ft_array_destroy(a, NULL);
}

Test(ft_array, test_suniq)
{
	t_array	a;

	int	notuniq[] = { 1, 2, 3, 3, 4, 5, 12, 14, 18 };
	int	uniq[] = { 1, 2, 3, 4, 7, 8, 11, 13, 15, 17, 21 };
	int	expected = 3;

	/* test */

	/* TEST NOT UNIQ ARRAY */

	a = ft_array_new(sizeof (notuniq) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &notuniq[i]);
	}
	cr_expect_eq(ft_array_suniq(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);

	/* TEST UNIQ ARRAY */

	a = ft_array_new(sizeof (notuniq) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &uniq[i]);
	}
	expected = -1;
	cr_expect_eq(ft_array_suniq(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);
}

Test(ft_array, test_issorted)
{
	t_array	a;

	int	sorted[] = { 3, 5, 12, 32, 54 };
	int	unsorted[] = {3, 4, 3, 12, 32, 53 };
	int	expected = true;

	a = ft_array_new(sizeof (sorted) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &sorted[i]);
	}
	cr_expect_eq(ft_array_issorted(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);


	a = ft_array_new(sizeof (unsorted) / sizeof (int));
	for (size_t i = 0; i < ft_array_capacity(a); ++i) {
		ft_array_append(a, &unsorted[i]);
	}
	expected = false;
	cr_expect_eq(ft_array_issorted(a, &cmp_uint), expected);
	ft_array_destroy(a, NULL);
}
