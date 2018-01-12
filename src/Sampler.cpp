
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
  double L = 0;
  Pruning(site, GetRoot());
  for (int i=0; i<4; i++)
    L += (GetRoot()->condl[i])/4.0;
	return log(L);
}

void Sampler::Pruning(int site, Node* node)	{

  // store the 4 likelihoods in attribute node.condl (double[4])

  if (! node->left) // if we are on a leaf, read the data
  {
    int state = data->GetState(node->GetNodeName(), site);
    if (state == -1) // indel in alignment
    {
      for (int j=0; j<4; j++)
        node->condl[j] = 1.0;
    }
    else // only one possibility is allowed
      node->condl[state] = 1.0;
  }
  else 
  {
    double lhs, rhs, v, q, p;

    // update the sons likelihoods
    Pruning(site, node->left); 
    Pruning(site, node->right);

    for (int sk = 0; sk < 4; sk++)
    {
      // Left computation
      lhs = 0;
      v = node->left->GetBranchLength();
      q = exp(- rate * v);
      p = 1 - q;
      for(int i = 0; i < 4; i++)
        lhs += ( q * (i==sk) + p * 1/4) * node->left->condl[i];

      // Right computation
      rhs = 0;
      v = node->right->GetBranchLength();
      q = exp(- rate * v);
      p = 1 - q;
      for(int j = 0; j < 4; j++)
        rhs += ( q * (j==sk) + p * 1/4) * node->right->condl[j];

      node->condl[sk] = lhs * rhs;
    }
  }
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


