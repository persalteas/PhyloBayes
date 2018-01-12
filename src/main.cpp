
#include "Sampler.h"

int main(int argc, char *argv[]) {

  if (argc < 3) {
    cerr << "phy_mol    path/to/data.file   run_name" << endl;
    exit(1);
  }

  // name of the datafile
  string datafile = argv[1];

  // name of the MCMC run
  string name = argv[2];

  // create the MCMC sampler
  Sampler *sampler = new Sampler(datafile);

  // run the sampler forever...
  sampler->Run(name);

  uint result = EXIT_SUCCESS;
  string cmd1 = "data/bpcomp -x 8000 10 " + name + ".treelist";
  string cmd2 = "/opt/seaview/seaview " + name + ".treelist.con.tre";
  result += system(cmd1.c_str());
  result += system(cmd2.c_str());

  return result;
}
