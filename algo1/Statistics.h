//
//  Statistics.h
//  algo1
//
//  Created by Iryna on 22/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#ifndef __algo1__Statistics__
#define __algo1__Statistics__

#include <vector>

class Statistics{
  int n{};
  std::vector<double> y;
  std::vector<double> x; // vector of random variables
  std::vector<double> xi; // vector of errors
public:
  Statistics(int n = 0);
  const std::vector<double> getVectorX();
  
  double weightedMean(const std::vector<int>& w);
  void quartiles();

  double linearRegressionSlope();
  
  size_t size();
  void printVectorX();

};

#endif /* defined(__algo1__Statistics__) */
