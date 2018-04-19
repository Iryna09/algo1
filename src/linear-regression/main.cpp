#include <iostream>
#include <random>
#include <vector>
#include <numeric>

double linear_regression_slope(const std::vector<double>& y,
                               const std::vector<double>& x)
{
  const double n = static_cast<double>(y.size());
  const double s_x = std::accumulate(x.begin(), x.end(), 0.0);
  const double s_y = std::accumulate(y.begin(), y.end(), 0.0);
  
  const double s_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
  const double s_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
  
  return (n*s_xy - s_x*s_y)/(n*s_xx - s_x*s_x);
}

int main(int argc, const char * argv[])
{
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_real_distribution<> urd_X(0.0,5.0); // random number
  std::uniform_real_distribution<> urd_Error(0.0,0.2); // random error

  const size_t n {10};
  const double alpha {2.0};
  const double beta {3.0}; // slope

  std::vector<double> y(n);
  std::vector<double> x(n); // vector of random variables
  std::vector<double> xi(n); // vector of errors

  //initialise vectors
  for(size_t i = 0; i < n; ++i){
    x[i] = urd_X(rng);
    xi[i] = urd_Error(rng);

    y[i] = alpha + beta*x[i] + xi[i]; // adding noise xi
  }
  
  std::cout<<"Linear regression slope: "<<linear_regression_slope(y, x)<<"\n";
  return EXIT_SUCCESS;
}