
#include "Sampler.h"

// int main(int argc, char* argv[])	{

// 	// name of the datafile
// 	string datafile = argv[1];

// 	// name of the MCMC run
// 	string name = argv[2];

// 	// create the MCMC sampler
// 	Sampler* sampler = new Sampler(datafile);

// 	// run the sampler forever...
// 	sampler->Run(name);
// }

int N = 10;
double t = 5.0;

double logposterior(double u) {
    return -(t+1)*u + N*log(t*u);
}

double propose_u_from(double u, double delta) {
	double V = Random::Uniform();
	double ustar = u + delta*(V-0.5);
	if (ustar<0) return -ustar;
	return ustar;
}


int     main(void) {
	int Ncycles = 100000;
	int Naccept = 0;

	// Condition initiale
	double u = 1.0;

	// Metropolis 
	for (int i=0; i<Ncycles; i++){
		// backup of u
		double bku = u; 
		double logpost1 = logposterior(u);

		// propose u*
		double delta = 1.0;
		u = u + delta*(Random::Uniform()-0.5);
		if (u<0) u = -u;

		double logpost2 = logposterior(u);

		// compute ratio of final/initial probs
		double logalpha = logpost2 - logpost1;

		// decide wether accept or not
		if (log(Random::Uniform()) < logalpha) { 
			Naccept++; 
		} else {
			u = bku;
		}

		// print out current value
		std::cout << u << std::endl;
	}
	std::cout << std::endl << "final: " << u << " with " ;
	std::cerr << double(Naccept)/Ncycles*100 << "% of accepted changes" << std::endl;
	return EXIT_SUCCESS;
}