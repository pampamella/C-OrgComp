#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]) {
    float hora, min, seg;

    hora = atoi(argv[1]);
    min = atoi(argv[2]);
    seg = atoi(argv[3]);


    FILE *fp;
    fp = fopen("save_time.txt","w");

    fprintf(fp, "%f hrs %f min %f sec\n", hora, min, seg);
    
    printf("Time saved\n");  

    fclose(fp);
    return 0;
}

