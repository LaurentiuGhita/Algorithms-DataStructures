#include <iostream>
#include <vector>

/*
* input is an array with a single unique element and all others appear k times
* find the unique element
*/

/*
* Ideea is to iterate through all bits and perform a bit sum  and compute sum % k 
* if sum % k is 1 ==> that bit is a bit from the unique number 
* repeate for all bits ==> obtain all bits from unique number
*
*/

int findUnique(const std::vector<int>& input, const int k, const int bit_count = 32) {
    
    int result = 0;

    for (auto i = 0; i < bit_count; ++i) {
        int sum = 0;
        for (const auto& num : input) {
            int mask = 1 << i; // bit i
            sum += (mask & num); // add bit i from current number to sum
        }

        sum %= k;
        
        // add bit to result
        result |= sum;
    }

    std::cout << "Unique item from input is " << result << ", the other elements appear " << k << " times\n";
    return result;
}


int main() {
    std::vector<int> v{ 1, 2,2,2, 4,4,4, 5,5,5, 6,6,6 };
    findUnique(v, 3);

    std::vector<int> v2{ 1, 2,2,2,2, 4,4,4,4 , 5,5,5,5, 6,6,6,6 };
    findUnique(v2, 4);

    std::vector<int> v3{ 2,3,5,1,2,2,5,3,5,3 };
    findUnique(v3, 3);
}

