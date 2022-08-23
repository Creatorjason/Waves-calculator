#include <stdio.h> 
#include <math.h> 
#define PI 3.141593

int main(void){
    int k;
    double 
    A1, 
    A2, 
    freqA, 
    freqB, 
    heightA, 
    heightB, 
    lengthA, 
    lengthB,
    T1, 
    T2, 
    w1, 
    w2, 
    sum, 
    new_period, 
    new_height, 
    time_increment, 
    t; 
    double maximum_wave = 0; // initial value

    printf("Enter wave period (s) and wave height (ft) \n"); 
    printf("for wave 1 (integer value): \n");
    scanf("%lf %lf",&T1,&heightA);
    printf("Enter wave period (s) and wave height (ft) \n"); 
    printf("for wave 2 (integer value): \n");
    scanf("%lf %lf",&T2,&heightB);
    lengthA = 5.13*T1*T1;
    lengthB = 5.13*T2*T2;
    printf("Wavelengths (in ft) are: %.3f %.3f \n",lengthA,lengthB);
    new_period = T1*T2;
    time_increment = new_period/200;
    A1 = heightA/2;
    A2 = heightB/2;
    freqA = 1/T1;
    freqB = 1/T2;
    
    for (k=0; k<=200; k++) {
        // The loop variable k<=t..where t is time, 
        //implies that the data is collected over a given time 
        // for testing purpose, use unity
      t = k*time_increment;
      w1 = A1*sin(2*PI*freqA*t);
      w2 = A2*sin(2*PI*freqB*t);
      sum = w1 + w2;
      if (sum > maximum_wave)
         maximum_wave = sum;
       
    }
      new_height = maximum_wave*2; 
      printf("Maximum combined wave height is %.3f ft \n",new_height);
    return 0;
}
