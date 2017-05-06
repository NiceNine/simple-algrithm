#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

//#include "common.h"

/// file: quick_sort.h
/// author: lfs
/// date: Mar 16, 2017

/** \brief called by quick_sort
 *
 * \param container& c
 * \param sub_tp [fist, last]
 * \return void
 *
 */
template<typename Container>
void quick_sort_impl(Container& c, sub_tp first,  sub_tp last)
{
    if(first >= last)
        return ;
    auto s_l = first - 1;
    for(auto u_f = first, target = c[last]; u_f < last; ++u_f) {
        if(c[u_f] <= target)
            std::swap(c[u_f], c[++s_l]);
    }

    quick_sort_impl(c, first, s_l - 1);
    quick_sort_impl(c, s_l + 1, last);
}

/** \brief a template implementing quick sort alg.
 *
 * \param container&
 * \param
 * \return void
 *
 */
template<typename Container>
void quick_sort(Container& c)
{
    sub_tp first = 0, last = static_cast<sub_tp>(c.size() - 1);
    quick_sort_impl(c, first, last);
}

#endif // QUICK_SORT_H_INCLUDED
