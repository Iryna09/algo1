//
//  main.cpp
//  algo1
//
//  Created by Iryna on 20/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include "Statistics.h"
#include "Trie.h"
#include "Utils.h"

//given odds of events A:B 1.09:1.0 find probability that
// in n = 6 trials there re at least 3 A
double binomial_case(double odds_A, double oddsB){
  double pA = odds_A/(1.0+odds_A);//from odds to probability
  double res{0};
  int n {6};
  Utils u;
  
  for(int x = 3; x <= 6; ++x)
    res += u.binomialDistribution(x,n,pA);
  
  return res;
}

int main(int argc, const char * argv[])
{
  
  std::unique_ptr<Statistics> stat{new Statistics(10)};
  stat->printVectorX();

  Utils u;

  std::cout.precision(3);
  std::cout<<"Mean of random elements: "<<std::fixed<<u.mean(stat->getVectorX())<<"\n";
  std::cout<<"Median of random elements: "<<std::fixed<<u.median(stat->getVectorX())<<"\n";
  std::cout<<"Mode of random elements: "<<u.mode(stat->getVectorX())<<"\n";
  std::cout<<"Weighted Mean of random elements: "<<std::fixed
           <<stat->weightedMean({1,2,3,4,5,1,2,3,4,5})<<"\n";
  stat->quartiles();
  std::cout<<"Standard Deviation of random elements: "<<std::fixed
           <<u.standardDeviation(stat->getVectorX())<<"\n";

  std::cout<<"Example of binomial dist: "<<binomial_case(1.09, 1.0)<<"\n";

  std::cout<<"Linear regression slope: "<<stat->linearRegressionSlope()<<"\n";

  std::unique_ptr<Trie> trie{new Trie()};
  
  trie->add("ACGT");
  trie->add("GCAT");
  trie->add("AATC");
  trie->add("GCAA");
  trie->add("ACGC");

  std::cout<<"Number of sequences starts with A : "<<trie->find("A")<<"\n";
  std::cout<<"Number of sequences starts with AC : "<<trie->find("AC")<<"\n";
  std::cout<<"Number of sequences starts with GC : "<<trie->find("GC")<<"\n";

  return EXIT_SUCCESS;
}