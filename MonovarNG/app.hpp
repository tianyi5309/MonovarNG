//
//  app.hpp
//  MonovarNG
//
//  Created by tianyi on 6/19/18.
//  Copyright © 2018 tianyi. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "config.hpp"
#include "vcf.hpp"
#include "pileup.hpp"

#include <stdio.h>

using namespace std;

class App {
    // Main application, controls the algorithm flow
    
    double mutationThreshold; // threshold for variant calling
    double pFalsePositive; // p_e, prior probability for false positive 
    double pDropout; // p_ad, prior probability for allelic dropout
    
    int numThreads; // number of threads for multiprocessing
    
    bool useConsensusFilter; // whether to use Consensus Filter (CF) 
    
    int numCells; // Number of cells processed
    int numPos; // Number of positions being processed
    
    VCFDocument output;
    
    vector<Pileup> positions;
    
public:
    App(Config config, vector<string> bamIDs, vector<Pileup> pileupRows);
    
    void runAlgo();
    // Runs main algorithm
};

#endif /* app_hpp */