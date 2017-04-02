#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "common.h"

using namespace std;

int main()
{
    vector<int > vect_int;
    while(true) {
        init(vect_int);
        quick_sort(vect_int);
        my_print(vect_int);
    }
    cout << "Hello world!" << endl;
    return 0;
}
