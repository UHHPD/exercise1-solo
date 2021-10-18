#include<iostream>
#include<fstream>

int main(){
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  int number_one,number_two, sum;
  int i=0;
  while(i<234){
    fin >> number_one;
    fin >> number_two;
    sum = number_one + number_two;
    fout << sum << std::endl;
    i++;
  }
  fin.close();
  fout.close();
}