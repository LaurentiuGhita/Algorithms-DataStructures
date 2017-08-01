#ifndef SET_UNION_H
#define SET_UNION_H

#include <iostream>
#include <vector>

struct SetUnion
{
    std::vector<int> m_parent;
    std::vector<int> m_size ; // number of elements in subtree i
    int n; // number of elements in set
};

void InitSetUnion(SetUnion& setUnion);
int Find(SetUnion& setUnion, int n); // find root of n
bool SameComponent(SetUnion&, int, int);

#endif