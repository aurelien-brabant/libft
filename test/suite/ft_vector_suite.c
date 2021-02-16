#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "libft.h"
#include "libft/internal/vector_int.h"
#include "libft/vector.h"

/*
** This suite tests all the functions related to the
** vector pseudo-class
*/

TestSuite(ft_vector);

static char	*strs1[] = { "string1", "string2", "string 3" };
static char	*strs2[] = { "string4", "string5", "string6", "string7" };

/*****************************************************************************/
/* BASIC FUNCTIONS TESTS                                                     */
/*****************************************************************************/

/* Not testing using ft_vec_get because it has not been tested yet */

/*
** ft_vec_add
*/

Test(ft_vector, ft_vec_add)
{
	t_vector		vec;
	t_vector_int	*vint;

	/* defaults values */
	vec = ft_vec_new(0, 0);
	vint = (t_vector_int *)vec;

	for (int i = 0; i < 3; ++i)
	{
		ft_vec_add(vec, strs1[i]);
		cr_expect_str_eq(vint->items[i], strs1[i]);
	}

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_get
*/

Test(ft_vector, ft_vec_get)
{
	t_vector		vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
	{
		ft_vec_add(vec, strs1[i]);
		cr_expect_str_eq(ft_vec_get(vec, i), strs1[i]);
	}

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_foreach
*/

char	*get_strs_from_foreach[3];
int		foreach_index = 0;

static void test_foreach(void *el, size_t index, void *strs)
{
	cr_expect_str_eq(((char **)strs)[index], (char *)el);
}

Test(ft_vector, ft_vec_foreach)
{
	t_vector		vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);
	ft_vec_foreach(vec, test_foreach, strs1);

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_cap
*/

Test(ft_vector, ft_vec_cap)
{
	
	t_vector		vec;

	vec = ft_vec_new(10, 0);

	cr_expect_eq(ft_vec_cap(vec), 10);

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_len
*/

Test(ft_vector, ft_vec_len)
{
	
	t_vector		vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);

	cr_expect_eq(ft_vec_len(vec), 3);

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_cat
*/

Test(ft_vector, ft_vec_cat)
{
	
	t_vector		vec1;
	t_vector		vec2;
	t_vector		vec_cat;

	vec1 = ft_vec_new(0, 0);
	vec2 = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec1, strs1[i]);
	for (int i = 0; i < 4; ++i)
		ft_vec_add(vec2, strs2[i]);
	vec_cat = ft_vec_cat(vec1, vec2);
	for (int i = 0; i < 7; ++i)
	{
		if (i < 3)
			cr_expect_str_eq(ft_vec_get(vec_cat, i), strs1[i]);
		else
			cr_expect_str_eq(ft_vec_get(vec_cat, i), strs2[i - 3]);
	}
	ft_vec_destroy(vec1, NULL);
	ft_vec_destroy(vec2, NULL);
	ft_vec_destroy(vec_cat, NULL);
}

/*
** ft_vec_del
*/

Test(ft_vector, ft_vec_del)
{
	
	t_vector		vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);
	ft_vec_del(vec, 0, NULL);
	ft_vec_del(vec, 2, NULL);

	cr_expect_eq(ft_vec_len(vec), 1);
	cr_expect_str_eq(ft_vec_get(vec, 0), strs1[1]);

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_map
*/

static void test_map(void **elem)
{
	(void)index;
	*elem = "changed by map";
}

Test(ft_vector, ft_vec_map)
{
	
	t_vector		vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);
	ft_vec_map(vec, &test_map, NULL);
	for (int i = 0; i < 3; ++i)
		cr_expect_str_eq(ft_vec_get(vec, i), "changed by map");

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_set
*/

Test(ft_vector, ft_vec_set)
{
	t_vector	vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);
	ft_vec_set(vec, 0, "Changed by set");
	ft_vec_set(vec, 2, "Changed by set");
	for (int i = 0; i < 3; ++i)
	{
		if (i == 1)
			cr_assert_str_eq(ft_vec_get(vec, i), strs1[i]);
		else
			cr_assert_str_eq(ft_vec_get(vec, i), "Changed by set");
	}

	ft_vec_destroy(vec, NULL);
}

/*
** ft_vec_set_len
*/

Test(ft_vector, ft_vec_set_len)
{
	t_vector	vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 3; ++i)
		ft_vec_add(vec, strs1[i]);

	cr_expect_eq(ft_vec_len(vec), 3);
	ft_vec_set_len(vec, 0);
	cr_expect_eq(ft_vec_len(vec), 0);

	ft_vec_destroy(vec, NULL);
}

/* ft_vec_sort */

static int	sort_positive_int(void *el1, void *el2)
{
	return (**(int **)el1 - **(int **)el2);
}

Test(ft_vector, ft_vec_sort)
{
	int	tab[] = { 9, 7, 0, 3, 4 };
	int	tab_ref[] = { 0, 3, 4, 7, 9 };
	t_vector	vec;

	vec = ft_vec_new(0, 0);

	for (int i = 0; i < 5; ++i)
		ft_vec_add(vec, &tab[i]);
	ft_vec_sort(vec, &ft_bsort, &sort_positive_int);
	for (int i = 0; i < 5; ++i)
		cr_expect_eq(*(int *)ft_vec_get(vec, i), tab_ref[i]);

	ft_vec_destroy(vec, NULL);
}


/*****************************************************************************/
/* VECTOR BEHAVIOUR TESTS                                                    */
/*****************************************************************************/

/* does it resize properly ? */

Test(ft_vector, resize_behaviour)
{
	t_vector		vec;

	vec = ft_vec_new(1, 0);

	/* it should trigger 2 resizes */
	for (int i = 0; i < 4; ++i)
		ft_vec_add(vec, strs2[i]);
	for (int i = 0; i < 4; ++i)
		cr_expect_str_eq(ft_vec_get(vec, i), strs2[i]);

	ft_vec_destroy(vec, NULL);
}
