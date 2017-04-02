#ifndef INSERT_SORT_H_INCLUDED
#define INSERT_SORT_H_INCLUDED

/// file: insert_sort.h
/// author: lfs
/// date: Mar 14, 2017

/** \brief a template implementing insert sort alg.
 *
 * \param container&
 * \param
 * \return void
 *
 */
template <typename T>
void insert_sort(T& container)
{
    for(int i = 1, j; static_cast<unsigned>(i) < container.size(); ++i) {
        auto val = container[i];
        for(j = i - 1; (container[j] > val) && (j >= 0); --j) {
            container[j + 1] = container[j];
        }
        j = j == -1 ? 0 : j;
        container[j] = val;
    }
}


#endif // INSERT_SORT_H_INCLUDED
