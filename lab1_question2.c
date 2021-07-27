#include <stdio.h>
#include <math.h>
#define rydberg_Constant 2.179e-18

int main(void) {
  int Z =1;//atomic number of hydrogen
  float energy_levels[6];
  printf("The atomic number of the hydrogen %d, the Rydberg constant %g J. \n", Z, rydberg_Constant);
  int n;
  double E;
  for(n = 1; n<7; n++){
    E = -(rydberg_Constant*pow(Z,2))/pow(n,2);
    energy_levels[n-1] = E;
    printf("Energy of the electron when n=%d is E(%d) = %g J. \n", n, n, E);
  }
  printf("%g", energy_levels[0]);
  int k;
  float energy_dif;
  for(k=0;k<6;k++){
    energy_dif = energy_levels[k+1] - energy_levels[k];
    printf("The energy difference between levels %d-%d:E(%d) - E(%d) = %g J.\n", (k+1), k, (k+1), k, energy_dif);
    
  }
  
}