/*

A non-empty zero-indexed array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:

int solution(vector<int> &A);

that, given a non-empty zero-indexed array A consisting of N integers, returns the number of equi leaders.

For example, given:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.

*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int GetPossibleLeader(vector<int>& A)
{
    int leader = A[0];
    int count = 1;
    
    for(std::size_t i = 1; i < A.size(); ++i)
    {
        if(A[i] == leader)
            count++;
        else
            count--;
            
        if(count == 0)
        {
            leader = A[i];
            count = 1;
        }       
    }
    
    return leader;
}

int GetLeaderAppearances(vector<int>& A, int leaderVal)
{
    int total = 0;
    for(std::size_t i = 0; i < A.size(); ++i)
    {
        if(A[i] == leaderVal)
            ++total;
    }
    
    return total;
}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int leader = GetPossibleLeader(A);
    int count = GetLeaderAppearances(A, leader);
    
    if(static_cast<size_t>(count) < A.size() / 2)
        return 0;
        
    
    int leftLeaderCount = 0;
    int rightLeaderCount = count;
    int equiLeaderCount = 0;
    
    for(size_t i = 0; i < A.size(); ++i)
    {
        int leftSize = i + 1;
        int rightSize = A.size() - leftSize;
        
        if(A[i] == leader)
        {
            leftLeaderCount++;
            rightLeaderCount--;
        }
        
        if(leftLeaderCount > leftSize / 2 && rightLeaderCount > rightSize / 2)
            ++equiLeaderCount;
    }
    
    return equiLeaderCount;
}