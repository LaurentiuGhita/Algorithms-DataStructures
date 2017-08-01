#ifndef BACKTRACK_H
#define BACKTRACK_H


template <typename T>
struct TypedefHelper
{
	typedef bool (*IsASolutionFP)(int*& a, int k, T input);
	typedef void (*ProcessSolutionFP)(int*& a, int k, T input);
	typedef void (*ConstructCanditatesFP)(int*& a, int k, T input, int*&c, int& ncandidates);
	typedef void (*MakeMoveFP)(int*&a, int k, T input);
	typedef void (*UnMakeMoveFP)(int*&a, int k, T input);
	typedef void (*BacktrackFP)(int*&a, int k, T input);	
};


template <typename T>
struct BacktrackingRoutines
{

	typename TypedefHelper<T>::IsASolutionFP 			IsASolution;
	typename TypedefHelper<T>::ProcessSolutionFP 		ProcessSolution;
	typename TypedefHelper<T>::ConstructCanditatesFP 	ConstructCanditates;
	typename TypedefHelper<T>::MakeMoveFP				MakeMove;
	typename TypedefHelper<T>::UnMakeMoveFP			UnMakeMove;
	typename TypedefHelper<T>::BacktrackFP				Backtrack;
};


template <typename T>
class BacktrackProblem
{
public:
	BacktrackingRoutines<T> m_routines;

	void SetIsASolutionRoutine(typename TypedefHelper<T>::IsASolutionFP fp) { m_routines.IsASolution = fp;}
	void SetProcessSolutionRoutine(typename TypedefHelper<T>::ProcessSolutionFP fp) { m_routines.ProcessSolution = fp; }
	void SetConstructCanditatesRoutine(typename TypedefHelper<T>::ConstructCanditatesFP fp) { m_routines.ConstructCanditates = fp;}
	void SetMakeMoveRoutine(typename TypedefHelper<T>::MakeMoveFP fp) { m_routines.MakeMove = fp; }
	void SetUnMakeMoveRoutine(typename TypedefHelper<T>::UnMakeMoveFP fp) { m_routines.UnMakeMove = fp;}
	void SetBacktrackRoutine(typename TypedefHelper<T>::BacktrackFP fp) { m_routines.Backtrack = fp; }

	void BacktrackAlgorithm(int*&a , int k, T input);
	void Solve(int*&a , int k, T input) { BacktrackAlgorithm(a, k, input); }
	

};

template <typename T>
void BacktrackProblem<T>::BacktrackAlgorithm(int*&a , int k, T input)
{
    int* c = new int[100];
    int nCandidates = 0;

    if(m_routines.IsASolution(a, k, input))
    	m_routines.ProcessSolution(a,k, input);
    else
    {
    	k = k + 1;
    	m_routines.ConstructCanditates(a, k, input, c, nCandidates);
    	for(int i = 0; i < nCandidates; ++i)
    	{
    		a[k] = c[i];
    		BacktrackAlgorithm(a, k, input);
    	}
    }

    delete[](c);
}


#endif
