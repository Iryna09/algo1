//
//  Utils.h
//  algo1
//
//  Created by Iryna on 22/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#ifndef algo1_Utils_h
#define algo1_Utils_h
#include <vector>
#include <numeric>
#include <map>

class Utils{
public:
  // mean: sum all elements / number of elements
  template<typename T>
  static T mean(const std::vector<T>& v){
    T sum = accumulate(v.begin(),v.end(),0.0);
    return sum/static_cast<T>(v.size());
  }
  
  // median = middle element in sorted array,
  // or average of 2 middle elements if
  // array contains even number of elements
  template<typename T>
  static T median(const std::vector<T>& v){
    //make copy to avoid rearranging of original vector
    std::vector<T> temp(v);
    sort(temp.begin(),temp.end());
    
    return median(temp,0,temp.size()-1);
  }
  
  //assume v sorted
  template<typename T>
  static T median(const std::vector<T>& v, size_t begin, size_t end){

    size_t n = end-begin+1;
    if(n%2 == 0)
      return (v[n/2+begin-1] + v[n/2+begin])/2.0;

    return v[n/2+begin];
  }

  // mode = most frequent element in array
  template<typename T>
  static T mode(const std::vector<T>& v){
    // use map to store frequencies of elements
    std::map<T,int> m;
    for(int e: v){
      auto it = m.find(e);
      if(it == m.end()) // seeing 'e' first time
        m[e] = 1;
      else
        ++(m[e]); //saw before, increment
    }
    int result{0}, maxCount{0};
    
    // go through map to find element with highest count
    for(auto it = m.begin(); it != m.end(); ++it){
      if(it->second > maxCount){
        maxCount = it->second;
        result = it->first;
      }
    }
    return result;
  }
 
  template<typename T>
  static T standardDeviation(const std::vector<T>& x){
    T mu = mean(x);
    T res{0};
    
    for(size_t i{0}; i < x.size(); ++i)
      res +=pow((x[i]-mu),2.0);
    
    res/=x.size();
    
    return sqrt(res);
  }

  template<typename T>
  static T factorial(T n){
    if (n == 1.0 or n == 0.0)
      return 1.0;
    return n * factorial(n-1);
  }
  
  template<typename T>
  static T nChoosek(T n, T k){
    return factorial(n)/(factorial(k)*factorial(n-k));
  }
  
  static double binomialDistribution(int x, int n, double p){
    return nChoosek(n,x) * pow(p,x) * pow(1.0-p,n-x);
  }

  static double geometricDistribution(int n, double p){
    return pow((1.0-p),n-1)*p;
  }

};

#endif
