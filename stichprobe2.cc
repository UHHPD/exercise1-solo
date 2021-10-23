#include<iostream>
#include<fstream>
#include<cmath>

int main() {
  //define variables
  int N_data = 234;                 //numbers in datensumme
  int N = 26;                 //number of means/variances
  int N_consecutive_numbers = 9;    //consecutive numbers
  double mean_sum, mean, variance_sum, variance_dif, variance, mean_means, mean_variances;
  double sum_means = 0;
  double sum_variances = 0;
  int index;
  int numbers[234];                 //array for the numbers of datensumme
  double means[26];                 //array for the means
  double variances[26];             //array for the variances
  //read/save numbers from datensumme into an array
  std::ifstream fin_data("datensumme.txt");
  for(int i = 0; i < N_data; ++i){
    fin_data >> numbers[i];
  }
  fin_data.close();
  //calculate mean/variances for N_consecutive_numbers
  for(int i = 0; i < N; ++i){
    //calculation of the mean
    mean_sum = 0;
    for(int j = 0; j < N_consecutive_numbers; ++j){
      index = j + 9*i;
      mean_sum += numbers[index];
    }
    mean = mean_sum / N_consecutive_numbers;
    //calculation of the variance (Bessel's correction)
    variance_sum = 0;
    for(int j = 0; j < N_consecutive_numbers; ++j){
      index = j + 9*i;
      variance_dif = numbers[index] - mean;
      variance_sum += variance_dif * variance_dif;
    }
    variance = variance_sum / (N_consecutive_numbers - 1);
    //write mean/variance into arrays
    means[i] = mean;
    variances[i] = variance;
  }
  //write means/variances to mittelwerte.txt/variances.txt
  std::ofstream fout_mean("mittelwerte.txt");
  std::ofstream fout_variance("varianzen.txt");
  for(int i = 0; i < N; ++i){
    fout_mean << means[i] << std::endl;
    fout_variance << variances[i] << std::endl;
  }
  fout_mean.close();
  fout_variance.close();
  //calculate mean of means/variances
  for(int i = 0; i < N; ++i){
    sum_means += means[i];
    sum_variances += variances[i];
  }
  mean_means = sum_means / N;
  mean_variances = sum_variances / N;
  //print/cout the results
  std::cout << "Mean of means: " << mean_means << std::endl;
  std::cout << "Mean of variances: " << mean_variances << std::endl;
}