#include <iostream>
#include <queue>

using min_heap = std::priority_queue<int, std::vector<int>, std::greater<int>>;

void generate_numbers(int num, std::vector<int>& factors) {
    min_heap heap;

    heap.push(1); // all factors at 0 power

    for (int i = 0; i < num; ++i) {
        
        const auto current_min = heap.top();
        std::cout << "num " << i << " is " << heap.top() << "\n";
        
        heap.pop();
        for (const auto& factor : factors) {
            heap.push(current_min * factor);
        }
    }
}

int main() {
    std::vector<int> v{ 2,3,5 };

    generate_numbers(10, v);
}
