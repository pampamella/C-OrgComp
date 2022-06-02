
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recursive_fib(int n);
long long int iterative_fib(int n);
// double iterative_fib(int n);

int main(int argc, char* argv[]) {
    int N, M, n1;
    clock_t start, finish;

    // Get the number of iterations from the command line
    N = atoi(argv[1]);
    M = N;

    FILE *fp;
    fp = fopen("test_fibonacci_C.csv","a");

    srand(time(NULL));

    // Perform the Recursive Fibonnacy operations
    start = clock();

    n1 = iterative_fib(N);
    finish = clock();

    fprintf(fp, "%lf\n",(double)(finish-start)/CLOCKS_PER_SEC);
    
    printf("Iterative - Fibonnaci (%d): %lf s --> %d \n", N, (double) (finish - start)/CLOCKS_PER_SEC, n1);
    // Perform the Recursive Fibonnacy operations
    start = clock();

    n1 = recursive_fib(M);
    finish = clock();

    fprintf(fp,"%lf\n", (double)(finish-start)/CLOCKS_PER_SEC);
    printf("Recursive - Fibonnaci (%d): %lf s --> %d \n", M, (double) (finish - start)/CLOCKS_PER_SEC, n1);  

    fclose(fp);
    return 0;
}

double recursive_fib(int n) {
    if(n <= 2) {
        return(1.0);
    }
    else {
        return(recursive_fib(n-2) + recursive_fib(n-1));
    }
}

// Modifed from https://rosettacode.org/wiki/Fibonacci_sequence
long long int iterative_fib(int n) {
     int fib_now = 0, fib_next = 1, temp_fib;
     while(--n > 0) {
         temp_fib = fib_now + fib_next;
         fib_now = fib_next;
         fib_next = temp_fib;
     }
     return fib_next;
}
