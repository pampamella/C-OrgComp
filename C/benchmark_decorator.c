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
    
    arquivos[test_belief_propagation] = fopen("test_belief_propagation.csv","r");
    arquivos[test_copy_matrix] = fopen("test_copy_matrix.csv","r");
    arquivos[test_evaluate_functions] = fopen("test_evaluate_functions.csv","r");
    arquivos[test_fibonacci] = fopen("test_fibonacci.csv","r");
//    arquivos[test_gauss_legendre_quadrature] = fopen("test_gauss_legendre_quadrature.csv","r");
//    arquivos[test_laplace_jacobi_4] = fopen("test_laplace_jacobi_4.csv","r");
//    arquivos[test_look_and_say] = fopen("test_look_and_say.csv","r");
    arquivos[test_markov_chain] = fopen("test_markov_chain.csv","r");
    arquivos[test_matrix_multiplication] = fopen("test_matrix_multiplication.csv","r");
    arquivos[test_munchausen_number] = fopen("test_munchausen_number.csv","r");
    arquivos[test_pernicious_numbers] = fopen("test_pernicious_numbers.csv","r");
	
    double dados_test_belief_propagation[3*iteracoes];
    double dados_test_copy_matrix[3*iteracoes];
    double dados_test_evaluate_functions[3*iteracoes];
    double dados_test_fibonacci[6*iteracoes];
    double dados_test_gauss_legendre_quadrature[1*iteracoes];
    double dados_test_laplace_jacobi_4[3*iteracoes];
    double dados_test_look_and_say[3*iteracoes]; 
    double dados_test_markov_chain[3*iteracoes]; 
    double dados_test_matrix_multiplication[3*iteracoes]; 
    double dados_test_munchausen_number[1*iteracoes]; 
    double dados_test_pernicious_numbers[1*iteracoes]; 
    
	double time;
	char line[32];
	if (arquivos[test_belief_propagation] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_belief_propagation])) {
        	sscanf(line, "%lf",&time);
        	dados_test_belief_propagation[i] = time;
        	i++;
    	}	
	}	
	if (arquivos[test_copy_matrix] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_copy_matrix])) {
        	sscanf(line, "%lf",&time);
        	dados_test_copy_matrix[i] = time;
        	i++;
    	}	
	}
	if (arquivos[test_evaluate_functions] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, data)) {
        	sscanf(line, "%lf",&time);
        	dados_test_evaluate_functions[i] = arquivos[test_evaluate_functions];
        	i++;
    	}	
	}	
	if (arquivos[test_fibonacci] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_fibonacci])) {
        	sscanf(line, "%lf",&time);
        	dados_test_fibonacci[i] = time;
        	i++;
    	}	
	}	
//	if (arquivos[test_gauss_legendre_quadrature] != NULL) {
//		int i = 0;
//    	while (fgets(line, sizeof line, arquivos[test_gauss_legendre_quadrature])) {
//        	sscanf(line, "%lf",&time);
//        	dados_test_gauss_legendre_quadrature[i] = time;
//        	i++;
//    	}	
//	}	
//	if (arquivos[test_laplace_jacobi_4] != NULL) {
//		int i = 0;
//    	while (fgets(line, sizeof line, arquivos[test_laplace_jacobi_4] )) {
//        	sscanf(line, "%lf",&time);
//        	dados_test_laplace_jacobi_4[i] = time;
//        	i++;
//    	}	
//	}
//	if (arquivos[test_look_and_say] != NULL) {
//		int i = 0;
//    	while (fgets(line, sizeof line, arquivos[test_look_and_say])) {
//        	sscanf(line, "%lf",&time);
//        	dados_test_look_and_say[i] = time;
//        	i++;
//    	}	
//	}
	if (arquivos[test_markov_chain] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_markov_chain] )) {
        	sscanf(line, "%lf",&time);
        	dados_test_markov_chain[i] = time;
        	i++;
    	}	
	}	
	if ( arquivos[test_matrix_multiplication]  != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_matrix_multiplication])) {
        	sscanf(line, "%lf",&time);
        	dados_test_matrix_multiplication[i] = time;
        	i++;
    	}	
	}	
	if (arquivos[test_munchausen_number] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_munchausen_number])) {
        	sscanf(line, "%lf",&time);
        	dados_test_munchausen_number[i] = time;
        	i++;
    	}	
	}	
	if (arquivos[test_pernicious_numbers] != NULL) {
		int i = 0;
    	while (fgets(line, sizeof line, arquivos[test_pernicious_numbers])) {
        	sscanf(line, "%lf",&time);
        	dados_test_pernicious_numbers[i] = time;
        	i++;
    	}	
	}	

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
//    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                            minimo(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                            media(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                            desvioPadrao(dados_test_gauss_legendre_quadrature,3*iteracoes));
//    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_laplace_jacobi_4,3*iteracoes),
//                                                            minimo(dados_test_laplace_jacobi_4,3*iteracoes),
//                                                            media(dados_test_laplace_jacobi_4,3*iteracoes),
//                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes));
//    fprintf(estatisticas,"%f,%f,%f,%f\n",maximo(dados_test_look_and_say,3*iteracoes),
//                                                            minimo(dados_test_look_and_say,3*iteracoes),
//                                                            media(dados_test_look_and_say,3*iteracoes),
//                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes));
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


