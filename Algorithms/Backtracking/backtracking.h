#ifndef BACKTRACK_H
#define BACKTRACK_H


	typedef bool (*IsASolutionFP)(int*& a, int k, int input);
	typedef void (*ProcessSolutionFP)(int*& a, int k, int input);
	typedef void (*ConstructCanditatesFP)(int*& a, int k, int input, int*&c, int& ncandidates);
	typedef void (*MakeMoveFP)(int*&a, int k, int input);
	typedef void (*UnMakeMoveFP)(int*&a, int k, int input);
	typedef void (*BacktrackFP)(int*&a, int k, int input);	


struct BacktrackingRoutines
{

	IsASolutionFP 			IsASolution;
	ProcessSolutionFP 		ProcessSolution;
	ConstructCanditatesFP 	ConstructCanditates;
	MakeMoveFP				MakeMove;
	UnMakeMoveFP			UnMakeMove;
	BacktrackFP				Backtrack;
};


template <typename T>
class BacktrackProblem
{
public:
	BacktrackingRoutines m_routines;

	void SetIsASolutionRoutine(IsASolutionFP fp) { m_routines.IsASolution = fp;}
	void SetProcessSolutionRoutine(ProcessSolutionFP fp) { m_routines.ProcessSolution = fp; }
	void SetConstructCanditatesRoutine(ConstructCanditatesFP fp) { m_routines.ConstructCanditates = fp;}
	void SetMakeMoveRoutine(MakeMoveFP fp) { m_routines.MakeMove = fp; }
	void SetUnMakeMoveRoutine(UnMakeMoveFP fp) { m_routines.UnMakeMove = fp;}
	void SetBacktrackRoutine(BacktrackFP fp) { m_routines.Backtrack = fp; }

	void BacktrackAlgorithm(int*&a , int k, T input);
	//void Solve(int*&a , int k, T input) { BacktrackAlgorithm<T>(a, k, input); }
	

};

void BacktrackProblem::BacktrackAlgorithm(int*&a , int k, int input)
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
