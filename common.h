#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

/// file: common.h
/// author: lfs
/// date: Mar 16, 2017

template <typename Y>
void init(Y& container)
{
    container.clear();
    std::cout << "Your input: " << std::endl;
    typename Y::value_type val;

    while(std::cin >> val) {
        container.push_back(val);
    }
    std::cin.clear();
    while(std::cin.get() != '\n')
        continue;
}
template <typename T>
void my_print(const T& container, std::string s = "Yourt output:")
{
    std::cout << s << std::endl;
    for(const auto& each:container) {
        std::cout << each << " ";
    }
    std::cout << std::endl;
}
#endif // COMMON_H_INCLUDED

