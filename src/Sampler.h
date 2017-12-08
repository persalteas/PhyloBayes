
#include "Random.h"
#include "Data.h"
#include "Tree.h"

class Sampler	{

	public:

	// creates a new MCMC sampler from a sequence datafile
	Sampler(string datafile)	{

		// create data object
		data = new Data(datafile);

		// create random tree, with leaves corresponding to taxa in datafile
		tree = new Tree(data->GetNtaxa(), data->GetNameList());

		// randomly draw the substitution rate from the prior
		SampleRate();
	}
	
	// MCMC
	// run a MCMC chain and regularly save state into files with specified name (+ extensions)
	void Run(string name)	{

		ofstream os((name + ".trace").c_str());
		TraceHeader(os);
		ofstream tos((name + ".treelist").c_str());

		while (1)	{
			Cycle();
			Trace(os);
			WriteTree(tos);
		}
	}

	// -----------------
	// TO BE IMPLEMENTED
	// -----------------

	// log of joint probability of the model
	// (proportional to posterior probability) 
	// ln p(D,T,U) = ln p(D | T,u) + ln p(T,u)
	double GetLogProb();

	// log of prior probability of the model
	// ln p(T,U)
	double GetLogPrior();

	// log likelihood
	// ln p(D | T,u)
	double GetLogLikelihood();

	// log likelihood should be computed independently for each site
	double SiteLogLikelihood(int site);

	// and for each site, should implement a recursive function across all nodes of the tree
	void Pruning(int site, Node* node);

	// during the run, the MCMC sampler cycles over all moves:
	// the Cycle() function should call all types of moves, with good tuning parameters
	void Cycle();

	// Metropolis move on the rate
	int RateMove(double tuning);

	// Metropolis move on divergence times
	int TimeMove(double tuning);

	// Metropolis move on the tree topology
	int TopoMove();


	// -----------------
	// ALREADY IMPLEMENTED
	// -----------------

	// header for the trace file
	void TraceHeader(ostream& os)	{
		os << "lnL\trate\n";
		os.flush();
	}

	// write one line in trace file summarizing current state
	void Trace(ostream& os)	{
		os << GetLogLikelihood() << '\t' << rate << '\n';
		os.flush();
	}

	// write tree into file
	void WriteTree(ostream& os)	{
		tree->WriteToStream(os);
		os.flush();
	}

	// simple accessors
	Node* GetRoot()	{
		return tree->GetRoot();
	}

	int GetNsite()	{
		return data->GetNsite();
	}

	int GetNtaxa()	{
		return data->GetNtaxa();
	}

	// draw random rate from prior distribution
	void SampleRate()	{
		rate = Random::sExpo();
	}

	private:

	Data* data;
	Tree* tree;
	double rate;
};

