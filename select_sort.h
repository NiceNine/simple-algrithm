#ifndef SELECT_SORT_H_INCLUDED
#define SELECT_SORT_H_INCLUDED

/// file:select_sort.h
/// author: lfs
/// date: Mar 14, 2017

/** \brief a template implementing select sort alg.
 *
 * \param container&
 * \param
 * \return void
 *
 */
template <typename T>
void select_sort(T& container)
{
    for(unsigned i = 0, min_val_pos; i < container.size() - 1; ++i) {
        min_val_pos = i;
        for(unsigned k = i + 1; k < container.size(); ++k) {
            if(container[k] < container[min_val_pos]) min_val_pos = k;
        }
        std::swap(container[i], container[min_val_pos]);
    }
}

#endif // SELECT_SORT_H_INCLUDED
