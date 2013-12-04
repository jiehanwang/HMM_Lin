// HMM_Lin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

#include "hmm.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//trainhmm
//  	Hmm hmm;
// 	// 	string ini = "sign-init";
// 	// 	string traindata = "sign.train";
// 	// 	hmm.loadProbs(ini);
// 	// 	const char* output = "sign-result";
// 	// 	ifstream istrm(traindata);
// 	// 	int maxIterations = 10;
// 	if (argc<3) {
// 
// 		cerr << "USAGE: trainhmm INIT-HMM RESULT-HMM DATA [MAX-ITERATIONS]" << endl;
// 
// 		exit(1);
// 
// 	}
// 
// 	hmm.loadProbs(argv[1]);
// 	const char* output = argv[2];
// 	ifstream istrm(argv[3]);
// 	int maxIterations = 10;
// 	if (argc>4)
// 		maxIterations = atoi(argv[4]);
// 
// 	vector<vector<unsigned long>*> trainingSequences;
// 	hmm.readSeqs(istrm, trainingSequences);
// 	hmm.baumWelch(trainingSequences, maxIterations);
// 	hmm.saveProbs(output);


	//testviterbi
	Hmm hmm;

	hmm.loadProbs(argv[1]);
	vector<vector<unsigned long>*> seqs;
	hmm.readSeqs(cin, seqs);

	for (unsigned int i = 0; i<seqs.size(); i++) {
		vector<unsigned long>& seq = *seqs[i];
		for (unsigned int j =0; j<seq.size(); j++) {
			hmm.addObservation(seq[j]);
		}
		vector<Transition*> path;
		double jointProb = hmm.viterbi(path);
		cout << "P(path)=" << exp(jointProb-hmm.obsProb()) << endl
			<< "path: " << endl;
		for (unsigned int i = 0; i<path.size(); i++) {
			Transition* trans = path[i];
			if (trans==0) continue;
			cout << hmm.getStr(trans->_obs) << '\t' 
				<< hmm.getStr(trans->_to->state()) << endl;
		}
		hmm.reset();
	}    

	//genseq
// 	Hmm hmm;
// 
// 	if (argc<2) {
// 		cerr << "USAGE: genseq NAME N" << endl
// 			<< "generates N observation sequences using the HMM with the given NAME" << endl;
// 		exit(1);
// 	}
// 	hmm.loadProbs(argv[1]);
// 	int seqs = atoi(argv[2]);
// 	hmm.genSeqs(cout, seqs);

// 

  	return 0;


}

