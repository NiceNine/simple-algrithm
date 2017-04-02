#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <utility> /**< std::swap */

/// file: merge_sort.h
/// author: lfs
/// date: Mar 14, 2017

/** \brief the key compolent of merge sort
 *
 * \param container&
 * \param unsigned [i, mid], [mid + 1 j]
 * \return void
 *  merge two sorted arrays
 */
template <typename T, typename Y>
void merge_sort_impl_merge(T& container, Y left_begin, Y left_end, Y right_end)
{
    T temp_container;
    auto right_begin = left_end + 1;
    while((left_begin <= left_end) && (right_begin <= right_end)) {
        if(container[left_begin] <= container[right_begin])
            temp_container.push_back(container[left_begin++]);
        else
            temp_container.push_back(container[right_begin++]);
    }

    --right_begin;
    while(left_begin <= left_end)
        container[right_begin--] = container[left_end--];

    for(int i = temp_container.size() - 1; i >=0; --i) {
        container[right_begin--] = temp_container[i];
    }
}

/** \brief a function do the real thing
 *
 * \param container&
 * \param unsigned [i, j]
 * \return void
 *  implemention of merge_sort
 */
template <typename T, typename Y>
void merge_sort_impl(T& container, Y i, Y j)
{
    if(i == j)
        return ;
    auto mid = (i + j)/2;
    merge_sort_impl(container, i, mid);
    merge_sort_impl(container, mid + 1, j);
    merge_sort_impl_merge(container, i, mid, j);
}

/** \brief a temlate implementing merge sort alg.
 *
 * \param container&
 * \param
 * \return void
 *
 */
template <typename T>
void merge_sort(T& container)
{
    merge_sort_impl(container, static_cast<int>(0), static_cast<int>(container.size() - 1));
}

#endif // MERGE_SORT_H_INCLUDED
