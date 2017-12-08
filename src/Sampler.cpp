
#include "Sampler.h"

// -----------------
// TO BE IMPLEMENTED
// -----------------

double Sampler::GetLogPrior()	{
	return 0;
}

double Sampler::GetLogLikelihood()	{
  double logL{};
  for (int i{GetNsite()}; i--;)
    logL += SiteLogLikelihood(i);
	return logL;
}

double Sampler::SiteLogLikelihood(int site)	{
	return log(Pruning(site, GetRoot()));
}

void Sampler::Pruning(int site, Node* node)	{

  double q = exp(- node->GetBranchLength());
  double p = 1 - q;
  double delta =
  if (! node->left)
    return exp(- rate * t) * delta
  
  
  double lhs{};  
  for ()
    lhs +=
  double rhs{};
  for ()
    rhs +=
  
  return lhs * rhs ;
  
}

int Sampler::RateMove(double tuning)	{
	return 0;
}

int Sampler::TimeMove(double tuning)	{
	return 0;
}

int Sampler::TopoMove()	{
	return 0;
}

void Sampler::Cycle()	{
}


