/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:30:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/01 15:18:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ABSTRACT DATA TYPE for array
*/

#ifndef ARRAY_H
# define ARRAY_H
# include <stdbool.h>
# include "libft/internal/array_int.h"

typedef void *t_array; /* abstraction */

t_array	*ft_array_new(int capacity);

/*
** Append the element el to the end of the array arr.
**
** Time complexity: O(1). Will increase if array resizing is required
** for storing the new element.
*/

void	ft_array_append(t_array a, void *el);

/*
** Set the element at index i to el.
** NOTE: No out of bounds check is performed, so make sure the value of is is
** relevant.
**
** Time complexity: O(1) (in all cases).
*/

void	ft_array_set(t_array a, void *el, size_t index);

/*
** Get the element at index i of a.
** NOTE: No out of bounds check is performed, so make sure the value of i is
** relevant.
**
** Time complexity: O(1) (in all cases).
*/

void	*ft_array_get(t_array a, size_t index);

size_t	ft_array_length(t_array a);

/*
** Set the length of the array to length. Useful if the size of the array
** needs to be truncated for some reason, without using successive removes.
*/

void	ft_array_set_length(t_array_int *a, size_t length);

size_t	ft_array_size(t_array a);

size_t	ft_array_capacity(t_array a);

/*
** Duplicates an array.
**
** Time complexity: O(n) where n is the number of elements in a.
*/

t_array	ft_array_dup(t_array a);

/*
** Concatenate two arrays in as a new one. No destroy operation is done
** on the two arrays passed as arguments.
**
** Time complexity: O(n + m) where n is the number of elements in the first
** array, and m the number of elements in the second one.
*/

t_array	ft_array_concat(t_array a1, t_array a2);

/*
** Merge two sorted arrays into a new one.
** The cmp function is used to compare the elements.
*/

t_array	ft_array_merge(t_array a1, t_array a2,
			int (*cmp)(void *el1, void *el2));

/*
** Perform the union operation on the two arrays passed as arguments, and
** put the result in a new array. The cmp function is used to know how to
** compare two items between arrays.
**
** Time complexity: O(n^2). The complexity is high because of the many
** searches that need to be performed in order to copy a2. If the two
** arrays are sorted, then it is recommended to use ft_array_sunion for
** lower time complexity.
*/

t_array	ft_array_union(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Union operation on arrays, like ft_array_union, but optimized for sorted
** arrays.
** NOTE: due to 42's norm restrictions, an additional overhead related to the 
** way the function has been coded may be expected. This will be fixed when norm
** will no longer be required.
**
** Time complexity: O(n)
*/

t_array	ft_array_sunion(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Perform the inter operation on the two arrays passed as arguments, and put
** the result in a new array. The cmp function is used to know how to compare
** two items between arrays.
**
** Time complexity: O(n^2). If the arrays are sorted according to cmp,
** ft_array_sinter is a better choice as it reduces the complexity of the
** operation on sorted arrays.
*/

t_array	ft_array_inter(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Inter operation on arrays, like ft_array_inter, but optimized for sorted
** arrays.
** NOTE: due to 42's norm restrictions, an additional overhead related to the 
** way the function has been coded may be expected. This will be fixed when norm
** will no longer be required.
**
** Time complexity: O(n)
*/

t_array	ft_array_sinter(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Perform substraction operation on a1 and a2, and put the result in a new
** array which is returned.
** Substraction operation on array is a logical operation which excludes
** any element present in the array 2 from the array 1.
** Size of the new array is a1's size.
**
** Time complexity: O(n^2).
** NOTE: If arrays are sorted according to cmp, using ft_array_ssub is prefered
** as it involves lower time complexity.
*/

t_array	ft_array_sub(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Sub operation on arrays, like ft_array_sub, but optimized for sorted
** arrays.
** NOTE: due to 42's norm restrictions, an additional overhead related to the
** way the function has been coded may be expected. This will be fixed when norm
** will no longer be required.
**
** Time complexity: O(n)
*/

t_array	ft_array_ssub(t_array a1, t_array a2, int (*cmp)(void *, void *));

/*
** Insert an element at a given index.
**
** Time complexity: worst = O(n) / best = O(1)
** Additional time will be taken if array needs to be resized in order to
** perform the insert operation, but the time complexity will never exceed O(n).
*/

void	ft_array_insert(t_array a, void *el, size_t index);

/*
** Insert an element in a sorted array. Useful if keeping an array sorted
** through insertions is wanted. Used as a replacement for the traditional
** append function, but for sorted arrays.
** The cmp function is used to compare two elements: the first is the inserted
** element, the second can be any element already present in the array.
**
** Time complexity: worst = O(n) / best = O(1)
*/

void	ft_array_sinsert(t_array a, void *el, int (*cmp)(void *el1, void *el2));

/*
** Sort the array using a given comparison function and sorting algorithm
*/

void	ft_array_sort(t_array_int *a, void (*alg)(void *, size_t, size_t,
				int (*cmp)(void *, void *)), int (*cmp)(void *, void *));

/*
** Determine if array is sorted or not.
** The cmp function should compare two elements and tell if element 1 is
** indeed less than than el2.
**
** Time complexity: worst = O(n) / best = O(1)
*/

bool	ft_array_issorted(t_array a, int (*cmp)(void *el1, void *el2));

/*
** Shift the array in left or right direction, filling the missing elements
** with zero.
** The direction of the shift is specified using shiftdir. -1 means left shift,
** while 1 means right shift.
** The offset describes how many elements needs to be shifted.
**
** Time complexity: O(n)
*/

void	ft_array_shift(t_array a, char shiftdir, size_t offset);

/*
** Rotate the array in left or right direction.
** The direction of the rotation is specified using rotatedir. -1 means
** rotate to the left while 1 means rotate to the right. The number of elements
** to rotate is passed as the offset parameter.
**
** FIXME: the rotate implementation is currently making use of a pretty naive
** approach. Rotations are done one by one, repeatingly until the expected
** number of rotations has been performed. Therefore the time complexity
** involved by such an approach is O(n * d) where d is the number of rotations
** that are performed. It is possible to reduce the complexity to O(n)
** without making use of a temporary array, by using a juggling algorithm.
** Ressource: https://www.geeksforgeeks.org/array-rotation/
**
** Such an algorithm hasn't been implemented because of my low interest
** for the rotate capability in general.
*/

void	ft_array_rotate(t_array a, char rotatedir, size_t offset);

/*
** NOTE: this searching method should not be used if you want the order of
** the elements in the array to stay relevant. If you're using sorted ADT
** arrays, you should absolutely use ft_array_binsearch instead.
**
** Search for the index of a particular element. The cmp function
** is called on every element to check if it corresponds to the one which
** is searched. Return value of zero means that the element is the searched one.
** The reference element used for the search is passed to ft_array_search and
** to the cmp function.
**
** This search function uses linear search combined with transposition
** strategy in order to optimize future searches based on search recurrence.
**
** Time complexity: worst = O(n) / best = O(1).
** NOTE: Transposition strategy attempts to decrease complexity when searching
** for often searched values.
*/

int		ft_array_linsearch(t_array a, void *ref, int cmp(void *ref, void *el));

/*
** NOTE: to get relevant results, the array NEEDS TO BE SORTED according to
** what the cmp function defines as sorted. If you don't want to deal with
** a sorted array and need to perform a search operation, use
** ft_array_linsearch instead.
**
** Use the cmp function to search for an element in the array. The cmp function
** takes the ref parameter as well as each tested array element, and compare
** them. If cmp returns zero, then the searched element has been found. The
** search is performed using a binary search algorithm, thus it is way faster
** than ft_array_linsearch. However, it requires the array to be sorted.
**
** Time complexity: worst && average = O(log(n)) / best = O(1)
*/

int		ft_array_binsearch(t_array a, void *ref, int cmp(void *ref, void *el));

/*
** Determines if array a doesn't have any duplicate. For that, ft_array_uniq
** returns the index of the first duplicate found (beginning at index 0) or -1
** if no duplicate has been found.
**
** Time complexity: worst = O(n^2) / best = O(1). If arrays are sorted according
** to cmp, use ft_array_suniq instead for lower time complexity.
*/

int		ft_array_uniq(t_array a, int cmp(void *, void *));

/*
** Same than ft_array_uniq, but optimized for a sorted array.
*/

int		ft_array_suniq(t_array a, int cmp(void *, void *));

/*
** Delete the element at index i in the array a.
** fn can be provided to do some cleanup related to the element.
** If no such cleanup is needed, NULL can be passed.
**
** Time complexity: worst = O(n) / best = O(1). Smaller index relatively to
** the total size of the array will lead to higher time complexity.
*/

void	ft_array_delete(t_array a, size_t i, void (*fn)(void *el));

/*
** Reverse the order of the elements in the array
**
** Time complexity: O(n)
*/

void	ft_array_reverse(t_array a);

/*
** For each element in the array, execute the fn function.
**
** The fn function can take up to 3 arguments, in that order:
**   - the actual element (passed as void *)
**   - the index of the element in the array (passed as int)
**   - any additional data to use inside the function (passed as void *). This
**   data needs to be passed to ft_array_foreach. If no data is required, NULL
**   can be passed.
**
** The return value of fn is checked after each call: if its return value
** is NOT zero, it means an error occured in fn. If so, the foreach iteration
** will stop and ft_array_foreach will return this non-zero value.
*/

int		ft_array_foreach(t_array a, int (*fn)(), void *data);

/*
** Destroy the array ADT as well as the content of its members if needed.
**
** The function fn is used to do some cleanup for the members of the array
** but NULL can be passed if no such cleanup is needed.
*/

void	ft_array_destroy(t_array a, void (*fn)(void *el));

#endif
