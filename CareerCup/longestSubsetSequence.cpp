#include <unordered_map>
#include <iostream>

/* 
 * we will use a sequence map 
 * key --> number 
   value --> if first item in sequence the value will consist of last item in that sequance 
         --> if other element it will contain the first item from that sequence at that moment
   for each element we search for previous item X - 1 
                              and next item X + 1 
   --> if we find one of those elements we merge the sequences
 */
std::tuple<int, int> longest_cont_subset(const std::vector<int>& input) {
    auto ret = std::tuple<int, int>(0, 0);
    std::unordered_map<int, int> sequence_map;
    int max_len = 0;

    for (const auto& entry : input) {
        
        // single element sequence --> len is 1 
        int current_len = 1;

        if (sequence_map.find(entry) != sequence_map.end())
            continue;

        int prev_num = entry - 1;
        int next_num = entry + 1;

        int begining = entry;
        int end = entry;

        if (sequence_map.find(prev_num) != sequence_map.end())
            begining = sequence_map[prev_num];

        if (sequence_map.find(next_num) != sequence_map.end())
            end = sequence_map[next_num];

        sequence_map[entry] = begining;
        // item from begining has to have as value the end sequence item
        sequence_map[begining] = end;
        sequence_map[end] = begining;

        current_len = end - begining + 1;
        if (current_len > max_len) {
            std::get<0>(ret) = begining;
            std::get<1>(ret) = end;
            max_len = current_len;
        }
        //std::cout << "Current longest subsequence starting from " << std::get<0>(ret) << " to " << std::get<1>(ret) << "\n";
    }

    std::cout << "We found longest subsequence starting from " << std::get<0>(ret) << " to " << std::get<1>(ret) << "\n";
    return ret;
}

int main() {
    std::vector<int> input{ 1,2,3, 5,6,7,8,4 };
    longest_cont_subset(input);

    std::vector<int> input2{ 1, 6, 10, 4, 7, 9, 5 };
    longest_cont_subset(input2);
}