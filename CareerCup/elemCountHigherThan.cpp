#include <iostream>
#include <type_traits>
#include <vector>
#include <unordered_map>

/* find elements that appear more than N / k times from an array with size N
  N / k info really important, size of map is K
*/

/*
*  something like tetris 
* use a map that keeps key-value pair --> element-count --> O(k) spatial complexity
* whenever the map size reaches K then decrement count of all elements, if count is 0 delete map entry
* repeat step for all elements
* remaining elements are possible candidates to solution --> O(n)
* check count for each of the remaning elements --> k * O(n)
*/


/*
 @input size is N
 get items that appear >= N / k
*/
template <
    typename T,
    typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
>
std::vector<T> getElementsAppCount(std::vector<T>& input, const int divide) {
    std::vector<T> result;
    std::unordered_map<T, int> tetris_map;
    const int k = input.size() / divide;

    for (const auto& num : input) {
        if (tetris_map.size() == divide) {
            // decrement items and erase entries with 0 as value
            auto it = tetris_map.begin();
            while (it != tetris_map.end()) {
                --it->second;
                if (it->second == 0)
                    it = tetris_map.erase(it);
                else
                    ++it;
            }
        }

        if (tetris_map.find(num) != tetris_map.end())
            ++tetris_map[num];
        else
            tetris_map[num] = 1;
    }

    for (const auto& map_entry : tetris_map) {
        auto num = map_entry.first;
        int count = 0;
        for (const auto& entry : input) {
            if (entry == num)
                ++count;
            if (count >= k) {
                result.push_back(num);
                break;
            }
        }
    }

    std::cout << "Items that appear >= " << k << " are: ";
    for (const auto& elem : result)
        std::cout << elem << " ";

    std::cout << "\n##################################\n";
    return result;
}

int main() {
    std::vector<int> input{ 4, 3, 3, 2, 1, 2, 3, 4, 4, 7 };
    getElementsAppCount(input, 3);
    getElementsAppCount(input, 2);
    getElementsAppCount(input, 4);
    getElementsAppCount(input, 6);
}