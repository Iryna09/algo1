//
//  Statistics.cpp
//  algo1
//
//  Created by Iryna on 22/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <map>
#include "Statistics.h"
#include "Utils.h"

Statistics::Statistics(int n): n(n), x(n), y(n), xi(n){
  
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_real_distribution<> urd_X(0.0,5.0); // random number
  std::uniform_real_distribution<> urd_Error(0.0,0.2); // random error
  
  const double alpha {2.0};
  const double beta {3.0}; // slope
  
  // initialise vectors
  for(size_t i = 0; i < n; ++i){
    x[i] = urd_X(rng);
    xi[i] = urd_Error(rng);
    
    y[i] = alpha + beta*x[i] + xi[i]; // adding noise xi
  }
  
}


// mean where each element is multiplied by its weight
double Statistics::weightedMean(const std::vector<int>& w){
  
  double sXW = std::inner_product(x.begin(),x.end(), w.begin(), 0.0);
  double sW = accumulate(w.begin(),w.end(),0.0);
  
  return sXW/sW;
}

// there is some additional noise into vector of random variables
// calculate slope with noise
double Statistics::linearRegressionSlope(){
  
  const double n = static_cast<double>(y.size());
  const double s_x = std::accumulate(x.begin(), x.end(), 0.0);
  const double s_y = std::accumulate(y.begin(), y.end(), 0.0);
  
  const double s_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
  const double s_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
  
  return (n*s_xy - s_x*s_y)/(n*s_xx - s_x*s_x);
  
}

size_t Statistics::size(){
  return n;
}

void Statistics::printVectorX(){
  for(int e: x)
    std::cout<<e<<" ";
  std::cout<<"\n";
}

const std::vector<double> Statistics::getVectorX(){
  return x;
}


// Q_1 median of first half, Q_2 median, Q_3 median of second half
void Statistics::quartiles(){
  std::vector<double> quartiles(3);
  std::vector<double> t(x);
  
  sort(t.begin(),t.end());
  size_t size = t.size();
  
  Utils u;
  quartiles[0] = u.median(t, 0, size/2-1);
  quartiles[1] = u.median(t, 0, size-1);
  
  if(size % 2 == 0)
    quartiles[2] = u.median(t, size/2, size-1);
  else
    quartiles[2] = u.median(t, size/2+1, size-1);
  
  std::cout.precision(1);
  std::cout<<"Quartiles:"<<std::endl;
  for(auto q: quartiles)
    std::cout<<std::fixed<<q<<"\n";
}


