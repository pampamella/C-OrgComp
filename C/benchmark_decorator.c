#include <stdio.h>
#define numeroDeTestes 11
#define iteracoes 3

#include<math.h>

typedef enum {
    test_belief_propagation = 0,
    test_copy_matrix,
    test_evaluate_functions,
    test_fibonacci,
    test_gauss_legendre_quadrature,
    test_laplace_jacobi_4,
    test_look_and_say,
    test_markov_chain,
    test_matrix_multiplication,
    test_munchausen_number,
    test_pernicious_numbers
} testes;

float maximo(float dados[], int tamanho){
    float max = dados[0];
    for(int i = 0;i<tamanho;i++){
        if(dados[i]>max){
            max = dados[i];
        }
    }
    return max;
}

float minimo(float dados[], int tamanho){
    float min = dados[0];
    for(int i = 0;i<tamanho;i++){
        if(dados[i]<min){
            min = dados[i];
        }
    }
    return min;
}

float media(float dados[], int tamanho){
    float soma = 0;
    for(int i = 0;i<tamanho;i++){
        soma+=dados[i];
    }
    return soma/tamanho;
}

float desvioPadrao(float dados[], int tamanho){
    float DP=0;
    printf("%d",tamanho);
    float med = media(dados,tamanho);
    printf("%f",media);
    for(int i = 0;i<tamanho;i++){
        DP+= pow(dados[i]-med,2);
    }
    DP = DP/tamanho;
    DP = sqrt(DP);
    return DP;
}

void main(){
    printf("%d",test_copy_matrix);
    FILE* arquivos[numeroDeTestes];
    FILE* estatisticas = fopen("estatisticas_C.csv","w");

    float dados_test_belief_propagation[3*iteracoes] = {1,2,3,4,5,6,7,8,9}; 
    float dados_test_copy_matrix[3*iteracoes]= {2,3,4,5,6,7,8,9,10}; 
    float dados_test_evaluate_functions[3*iteracoes]= {3,4,5,6,7,8,9,10,11}; 
    float dados_test_fibonacci[3*iteracoes]= {1,1,1,1,1,1,1,1,1}; 
    float dados_test_gauss_legendre_quadrature[3*iteracoes]= {2,3,4,5,6,7,8,9,10}; 
    float dados_test_laplace_jacobi_4[3*iteracoes]= {1,1,1,1,1,1,1,1,1}; 
    float dados_test_look_and_say[3*iteracoes]= {1,1,1,1,1,1,1,1,1}; 
    float dados_test_markov_chain[3*iteracoes]= {1,1,1,1,1,1,1,1,1}; 
    float dados_test_matrix_multiplication[3*iteracoes]= {1,1,1,1,1,1,1,1,1}; 
    float dados_test_munchausen_number[1*iteracoes] = {3,4,5}; 
    float dados_test_pernicious_numbers[1*iteracoes]= {1,2,3}; 

    arquivos[test_belief_propagation] = fopen("test_belief_propagation.csv","r");
    arquivos[test_copy_matrix] = fopen("test_copy_matrix.csv","r");
    arquivos[test_evaluate_functions] = fopen("test_evaluate_functions.csv","r");
    arquivos[test_fibonacci] = fopen("test_fibonacci.csv","r");
    arquivos[test_gauss_legendre_quadrature] = fopen("test_gauss_legendre_quadrature.csv","r");
    arquivos[test_laplace_jacobi_4] = fopen("test_laplace_jacobi_4.csv","r");
    arquivos[test_look_and_say] = fopen("test_look_and_say.csv","r");
    arquivos[test_markov_chain] = fopen("test_markov_chain.csv","r");
    arquivos[test_matrix_multiplication] = fopen("test_matrix_multiplication.csv","r");
    arquivos[test_munchausen_number] = fopen("test_munchausen_number.csv","r");
    arquivos[test_pernicious_numbers] = fopen("test_pernicious_numbers.csv","r");

    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_belief_propagation,3*iteracoes),
                                                            minimo(dados_test_belief_propagation,3*iteracoes),
                                                            media(dados_test_belief_propagation,3*iteracoes),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_copy_matrix,3*iteracoes),
                                                            minimo(dados_test_copy_matrix,3*iteracoes),
                                                            media(dados_test_copy_matrix,3*iteracoes),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_evaluate_functions,3*iteracoes),
                                                            minimo(dados_test_evaluate_functions,3*iteracoes),
                                                            media(dados_test_evaluate_functions,3*iteracoes),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_fibonacci,3*iteracoes),
                                                            minimo(dados_test_fibonacci,3*iteracoes),
                                                            media(dados_test_fibonacci,3*iteracoes),
                                                            desvioPadrao(dados_test_fibonacci,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_gauss_legendre_quadrature,3*iteracoes),
                                                            minimo(dados_test_gauss_legendre_quadrature,3*iteracoes),
                                                            media(dados_test_gauss_legendre_quadrature,3*iteracoes),
                                                            desvioPadrao(dados_test_gauss_legendre_quadrature,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_laplace_jacobi_4,3*iteracoes),
                                                            minimo(dados_test_laplace_jacobi_4,3*iteracoes),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_look_and_say,3*iteracoes),
                                                            minimo(dados_test_look_and_say,3*iteracoes),
                                                            media(dados_test_look_and_say,3*iteracoes),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_markov_chain,3*iteracoes),
                                                            minimo(dados_test_markov_chain,3*iteracoes),
                                                            media(dados_test_markov_chain,3*iteracoes),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_matrix_multiplication,3*iteracoes),
                                                            minimo(dados_test_matrix_multiplication,3*iteracoes),
                                                            media(dados_test_matrix_multiplication,3*iteracoes),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_munchausen_number,1*iteracoes),
                                                            minimo(dados_test_munchausen_number,1*iteracoes),
                                                            media(dados_test_munchausen_number,1*iteracoes),
                                                            desvioPadrao(dados_test_munchausen_number,1*iteracoes));
    fprintf(estatisticas,"%f,%f,%f,%f",maximo(dados_test_pernicious_numbers,1*iteracoes),
                                                            minimo(dados_test_pernicious_numbers,1*iteracoes),
                                                            media(dados_test_pernicious_numbers,1*iteracoes),
                                                            desvioPadrao(dados_test_pernicious_numbers,1*iteracoes));


}


