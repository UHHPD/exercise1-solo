#include<iostream>
#include<fstream>

int main() {
  std::ifstream fin("datensumme.txt");
  int number;
  int N = 234;
  double total_sum = 0;
  double mean;
  int i = 0;
  while(i<N){
    fin >> number;
    total_sum += number;
    i++;
  }
  fin.close();
  mean = total_sum / N;
  std::cout << "mean: " << mean << std::endl;
}