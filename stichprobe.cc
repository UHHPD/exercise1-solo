#include<iostream>
#include<fstream>
#include<cmath>

int main() {
  //define variables
  int number;
  int N = 234;                                              //numbers
  double mean_sum = 0;
  double variance_sum = 0;
  double mean, variance, variance_dif, standard_deviation;
  int i_one = 0;
  int i_two = 0;

  //calculate mean of datensumme
  std::ifstream fin_one("datensumme.txt");
  while(i_one<N){
    fin_one >> number;
    mean_sum += number;
    i_one++;
  }
  fin_one.close();
  mean = mean_sum / N;

  //calculate variance of datensumme
  std::ifstream fin_two("datensumme.txt");
  while(i_two<N){
    fin_two >> number;
    variance_dif = number - mean;
    variance_sum += variance_dif * variance_dif;
    i_two++;
  }
  fin_two.close();
  variance = variance_sum / N;

  //calculate standard deviation
  standard_deviation = sqrt(variance);

  //print/cout the results
  std::cout << "mean: " << mean << std::endl;
  std::cout << "variance: " << variance << std::endl;
  std::cout << "standard_deviation: " << standard_deviation << std::endl;
}