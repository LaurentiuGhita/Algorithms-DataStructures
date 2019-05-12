#include <iostream>
#include <unordered_map>
#include <sstream>

void possibilites_print(const int n, int k, std::vector<int>& path) {
    if (n == 0) {
        for (const auto& step : path)
            std::cout << step << " ";
        std::cout << "\n";
    }
    else if(n > 0){
        for (int i = 1; i <= k; ++i) {
            std::vector<int> new_list = path;
            // append to current path
            new_list.push_back(i);
            possibilites_print(n - i, k, new_list);
        }
    }
}


// S[n] = S(n-1) + S(n-2) + ... + S(n-k)
int possibilites_count(const int n, int k) {
    std::unordered_map<int, int> resultsMap;
    resultsMap[0] = 1;

    if (n == 0)
        return 1;

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        int total = 0;

        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0)
                total += resultsMap[i - j];
        }

        resultsMap[i] = total;
    }

    std::cout << "count is " << resultsMap[n] << "\n";
}

int main() {
    std::vector<int> path;
    possibilites_print(4, 2, path);
    possibilites_count(4, 2);
 }

