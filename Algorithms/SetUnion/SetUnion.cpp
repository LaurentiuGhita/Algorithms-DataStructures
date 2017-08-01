#include "SetUnion.h"

void InitSetUnion(SetUnion& setUnion, int n)
{
    // parent of each elemen is himself
    for(int i = 0; i < n; ++i)
    {
        setUnion.m_parent.push_back(i);
        setUnion.m_size.push_back(1); // size of each sub tree is 1
    }

    setUnion.n = n;
}

int Find(SetUnion& setUnion, int n)
{
    if(setUnion.m_parent[n] == n)
        return n;
    else
        return Find(setUnion, setUnion.m_parent[n]);
}


void Union(SetUnion& setUnion, int n1, int n2)
{

    int r1, r2;

    r1 = Find(setUnion, n1);
    r2 = Find(setUnion, n2);

    /* elements in same union*/
    if(r1 == r2)
        return;

    int smaller = r1;
    int bigger = r2;
    if(r1 > r2)
    {
        smaller = r2;
        bigger = r1;
    }

    setUnion.m_parent[smaller] = bigger;
    setUnion.m_size[bigger] += setUnion.m_size[smaller];
}

bool SameComponent(SetUnion& setUnion, int n1, int n2)
{
    return Find(setUnion, n1) == Find(setUnion, n2);
}

int main()
{
    return 0;
}