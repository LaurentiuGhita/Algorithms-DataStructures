#include <iostream>
#include <vector>
#include <type_traits>
#include <queue>
#include <random>

/*
* Input: Am N x N matrix sorted by row and column matrix
* Question: Find Kth largest element
*/

template <typename T>
using Invoke = typename T::type;

template <typename Condition>
using EnableIf = Invoke<std::enable_if<Condition::value>>;

template <typename T, typename = EnableIf<std::is_arithmetic<T>>>
using numeric_matrix = std::vector<std::vector<T>>;

template <typename T, typename = EnableIf<std::is_arithmetic<T>>>
using numeric_min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/*
* k th largest element is in upper half of K x K submatrix 
* items above secondary diagonal and from secondary diagonal are possible candidates
* using a priority as a min heap 
* using template aliases to make sure we have a numeric matrix 
*/
template <typename T>
T getKThLargetElem(const numeric_matrix<T>& input_matrix, const int k) {
    T ret = input_matrix[0][0];
    numeric_min_heap<T> heap;

    // add to heap only elements that are above secondary diagonal
    int matrix_limit = k > input_matrix.size() ? input_matrix.size() : k;
    
    for (int i = 0; i < matrix_limit; ++i) {
        for (int j = 0; j < matrix_limit - i; ++j)
            heap.push(input_matrix[i][j]);
    }

    for (int i = 0; i < k - 1; ++i)
        heap.pop();

    ret = heap.top();

    return ret;
}

int main() {
    constexpr int dimension = 5;
    auto m = numeric_matrix<int>(dimension, std::vector<int>(dimension, 0));

    m[0][0] = 1;
    m[0][1] = 10;
    m[0][2] = 12;
    m[0][3] = 30;
    m[0][4] = 50;

    m[1][0] = 5;
    m[1][1] = 11;
    m[1][2] = 13;
    m[1][3] = 32;
    m[1][4] = 51;

    m[2][0] = 7;
    m[2][1] = 15;
    m[2][2] = 17;
    m[2][3] = 33;
    m[2][4] = 60;

    m[3][0] = 9;
    m[3][1] = 34;
    m[3][2] = 55;
    m[3][3] = 77;
    m[3][4] = 80;

    m[4][0] = 100;
    m[4][1] = 105;
    m[4][2] = 107;
    m[4][3] = 109;
    m[4][4] = 110;

    int k;
    while (std::cin >> k) {
        std::cout << k << " th largest elem is " << getKThLargetElem(m, k) << "\n";
    }
}