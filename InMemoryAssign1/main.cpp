#include <cmath>
#include <iostream>
#include <stdio.h>
#include <time.h>


void funAssign(int iterations){

    float time_diff = 0.0 ;
    int dummy = 0;
    // for strides, increment from 8 bytes
    for(int i=3 ; i <  14; i++){
        
        //array size increament from 1kb
        for (int j= 10; j<=21; j++){
            clock_t start_time = clock();
            int *arr = new int[pow(2,j)];
            
            //number of iteration
            for(int m =0 ; m< iterations; m++){
                //loop traverse with strides
                for(int k = 0;k < pow(2,j) ;k= k + pow(2,i)){
                    dummy = arr[k];
                }
            }
            time_diff = time_diff + ((float(clock() - start_time) /  CLOCKS_PER_SEC )* 1000000);
            printf("%f,%d,%d\n",time_diff/iterations, long(pow(2,j)),int(pow(2,i)));
            delete [] arr;
        }
        
    }
    
}

int main()
{

    int iterations = 100000; //number of times array triversed
    funAssign(iterations);
    return 0 ;
    
}