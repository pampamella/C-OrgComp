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

double maximo(double dados[], int tamanho, int teste, int flag, int jump){
	if(flag == 1) {
		teste += tamanho;
		tamanho = tamanho*2;
	}
    double max = dados[teste];
    for(int i = teste;i<tamanho;i+=jump){
        if(dados[i]>max){
            max = dados[i];
        }
    }
    return max;
}

double minimo(double dados[], int tamanho, int teste, int flag, int jump){
	if(flag == 1) {
		teste += tamanho;
		tamanho = tamanho*2;
	}
    double min = dados[teste];
    for(int i = 0;i<tamanho;i+=jump){
        if(dados[i]<min){
            min = dados[i];
        }
    }
    return min;
}

double media(double dados[], int tamanho, int teste, int flag, int jump){
	if(flag == 1) {
		teste += tamanho;
		tamanho = tamanho*2;
	}
    double soma = 0;
    for(int i = teste;i<tamanho;i+=jump){
        soma+=dados[i];
    }
    return soma/tamanho;
}

double desvioPadrao(double dados[], int tamanho, int teste, int flag, int jump){
	if(flag == 1) {
		teste += tamanho;
		tamanho = tamanho*2;
	}
    double DP=0;
//    printf("%d",tamanho);
    double med = media(dados,tamanho, teste, flag, jump);
//    printf("%lf",media);
    for(int i = teste;i<tamanho;i+=jump){
        DP+= pow(dados[i]-med,2);
    }
    DP = DP/tamanho;
    DP = sqrt(DP);
    return DP;
}

void main(){
    FILE* arquivos[numeroDeTestes];
    FILE* estatisticas = fopen("estatisticas_C.csv","w");
    
    fprintf(estatisticas,"%s,%s,%s,%s,%s\n","experimento", "minimo", "maximo", "desvio padrao", "media");
    
    arquivos[test_belief_propagation] = fopen("test_belief_propagation_C.csv","r");
    arquivos[test_copy_matrix] = fopen("test_copy_matrix_C.csv","r");
    arquivos[test_evaluate_functions] = fopen("test_evaluate_functions_C.csv","r");
    arquivos[test_fibonacci] = fopen("test_fibonacci_C.csv","r");
    arquivos[test_gauss_legendre_quadrature] = fopen("test_gauss_legendre_quadrature_C.csv","r");
    arquivos[test_laplace_jacobi_4] = fopen("test_laplace_jacobi_4_C.csv","r");
    arquivos[test_look_and_say] = fopen("test_look_and_say_C.csv","r");
    arquivos[test_markov_chain] = fopen("test_markov_chain_C.csv","r");
    arquivos[test_matrix_multiplication] = fopen("test_matrix_multiplication_C.csv","r");
    arquivos[test_munchausen_number] = fopen("test_munchausen_number_C.csv","r");
    arquivos[test_pernicious_numbers] = fopen("test_pernicious_numbers_C.csv","r");
	
    double dados_test_belief_propagation[6*iteracoes];
    double dados_test_copy_matrix[6*iteracoes];
    double dados_test_evaluate_functions[6*iteracoes];
    double dados_test_fibonacci[12*iteracoes];
    double dados_test_gauss_legendre_quadrature[6*iteracoes];
    double dados_test_laplace_jacobi_4[6*iteracoes];
    double dados_test_look_and_say[6*iteracoes]; 
    double dados_test_markov_chain[6*iteracoes]; 
    double dados_test_matrix_multiplication[6*iteracoes]; 
    double dados_test_munchausen_number[2*iteracoes]; 
    double dados_test_pernicious_numbers[2*iteracoes]; 
    
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
    	while (fgets(line, sizeof line, arquivos[test_evaluate_functions])) {
        	sscanf(line, "%lf",&time);
        	dados_test_evaluate_functions[i] = time;
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
	if (arquivos[test_gauss_legendre_quadrature] != NULL) {
		int i = 0;
   	while (fgets(line, sizeof line, arquivos[test_gauss_legendre_quadrature])) {
       	sscanf(line, "%lf",&time);
       	dados_test_gauss_legendre_quadrature[i] = time;
       	i++;
   	}	
	}	
	if (arquivos[test_laplace_jacobi_4] != NULL) {
		int i = 0;
   	while (fgets(line, sizeof line, arquivos[test_laplace_jacobi_4] )) {
       	sscanf(line, "%lf",&time);
       	dados_test_laplace_jacobi_4[i] = time;
       	i++;
   	}	
	}
	if (arquivos[test_look_and_say] != NULL) {
		int i = 0;
   	while (fgets(line, sizeof line, arquivos[test_look_and_say])) {
       	sscanf(line, "%lf",&time);
       	dados_test_look_and_say[i] = time;
       	i++;
   	}	
	}
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
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_5000", minimo(dados_test_copy_matrix,3*iteracoes,0,0,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,0,0,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_7000", minimo(dados_test_copy_matrix,3*iteracoes,1,0,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,1,0,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_9000", minimo(dados_test_copy_matrix,3*iteracoes,2,0,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,2,0,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_O_5000", minimo(dados_test_copy_matrix,3*iteracoes,0,1,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,0,1,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_O_7000", minimo(dados_test_copy_matrix,3*iteracoes,1,1,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,1,1,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","copy_matrix_C_O_9000", minimo(dados_test_copy_matrix,3*iteracoes,2,1,3),
                                                            maximo(dados_test_copy_matrix,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_copy_matrix,3*iteracoes,2,1,3),
                                                            media(dados_test_copy_matrix,3*iteracoes,2,1,3));
	
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_40", minimo(dados_test_look_and_say,3*iteracoes,0,0,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,0,0,3),
                                                            media(dados_test_look_and_say,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_45", minimo(dados_test_look_and_say,3*iteracoes,1,0,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,1,0,3),
                                                            media(dados_test_look_and_say,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_48", minimo(dados_test_look_and_say,3*iteracoes,2,0,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,2,0,3),
                                                            media(dados_test_look_and_say,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_O_40", minimo(dados_test_look_and_say,3*iteracoes,0,1,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,0,1,3),
                                                            media(dados_test_look_and_say,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_O_45", minimo(dados_test_look_and_say,3*iteracoes,1,1,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,1,1,3),
                                                            media(dados_test_look_and_say,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","look_and_say_C_O_48", minimo(dados_test_look_and_say,3*iteracoes,2,1,3),
                                                            maximo(dados_test_look_and_say,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_look_and_say,3*iteracoes,2,1,3),
                                                            media(dados_test_look_and_say,3*iteracoes,2,1,3));
	
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_C_25", minimo(dados_test_fibonacci,6*iteracoes,0,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,0,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,0,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,0,0,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_C_35", minimo(dados_test_fibonacci,6*iteracoes,2,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,2,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,2,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,2,0,6));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_C_45", minimo(dados_test_fibonacci,6*iteracoes,4,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,4,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,4,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,4,0,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_C_25", minimo(dados_test_fibonacci,6*iteracoes,1,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,1,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,1,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,1,0,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_C_35", minimo(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,3,0,6));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_C_45", minimo(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,3,0,6),
                                                            media(dados_test_fibonacci,6*iteracoes,3,0,6));
                                                            
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_O_C_25", minimo(dados_test_fibonacci,6*iteracoes,0,1,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,0,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,0,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,0,1,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_O_C_35", minimo(dados_test_fibonacci,6*iteracoes,2,1,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,2,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,2,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,2,1,6));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_recursivo_O_C_45", minimo(dados_test_fibonacci,6*iteracoes,4,1,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,4,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,4,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,4,1,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_O_C_25", minimo(dados_test_fibonacci,6*iteracoes,1,1,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,1,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,1,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,1,1,6));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_O_C_35", minimo(dados_test_fibonacci,6*iteracoes,3,1,6),
                                                            maximo(dados_test_fibonacci,6*iteracoes,3,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,3,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,3,1,6));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","fibonacci_iterativo_O_C_45", minimo(dados_test_fibonacci,6*iteracoes,3,1,6),
                                                            maximo(dados_test_fibonacci,64*iteracoes,3,1,6),
                                                            desvioPadrao(dados_test_fibonacci,6*iteracoes,3,1,6),
                                                            media(dados_test_fibonacci,6*iteracoes,3,1,6));
	
	
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_1500", minimo(dados_test_matrix_multiplication,3*iteracoes,0,0,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,0,0,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_1750", minimo(dados_test_matrix_multiplication,3*iteracoes,1,0,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,1,0,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_2000", minimo(dados_test_matrix_multiplication,3*iteracoes,2,0,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,2,0,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_O_1500", minimo(dados_test_matrix_multiplication,3*iteracoes,0,1,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,0,1,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_O_1750", minimo(dados_test_matrix_multiplication,3*iteracoes,1,1,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,1,1,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","matrix_multiplication_C_O_2000", minimo(dados_test_matrix_multiplication,3*iteracoes,2,1,3),
                                                            maximo(dados_test_matrix_multiplication,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_matrix_multiplication,3*iteracoes,2,1,3),
                                                            media(dados_test_matrix_multiplication,3*iteracoes,2,1,3));
															
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_80000", minimo(dados_test_evaluate_functions,3*iteracoes,0,0,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,0,0,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_90000", minimo(dados_test_evaluate_functions,3*iteracoes,1,0,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,1,0,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_100000", minimo(dados_test_evaluate_functions,3*iteracoes,2,0,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,2,0,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_O_80000", minimo(dados_test_evaluate_functions,3*iteracoes,0,1,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,0,1,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_O_90000", minimo(dados_test_evaluate_functions,3*iteracoes,1,1,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,1,1,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","evaluate_functions_C_O_100000", minimo(dados_test_evaluate_functions,3*iteracoes,2,1,3),
                                                            maximo(dados_test_evaluate_functions,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_evaluate_functions,3*iteracoes,2,1,3),
                                                            media(dados_test_evaluate_functions,3*iteracoes,2,1,3));
	
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_250", minimo(dados_test_belief_propagation,3*iteracoes,0,0,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,0,0,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_500", minimo(dados_test_belief_propagation,3*iteracoes,1,0,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,1,0,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_1000", minimo(dados_test_belief_propagation,3*iteracoes,2,0,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,2,0,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_O_250", minimo(dados_test_belief_propagation,3*iteracoes,0,1,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,0,1,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_O_500", minimo(dados_test_belief_propagation,3*iteracoes,1,1,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,1,1,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","belief_propagation_C_O_1000", minimo(dados_test_belief_propagation,3*iteracoes,2,1,3),
                                                            maximo(dados_test_belief_propagation,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_belief_propagation,3*iteracoes,2,1,3),
                                                            media(dados_test_belief_propagation,3*iteracoes,2,1,3));
	
	
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_5000", minimo(dados_test_markov_chain,3*iteracoes,0,0,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,0,0,3),
                                                            media(dados_test_markov_chain,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_10000", minimo(dados_test_markov_chain,3*iteracoes,1,0,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,1,0,3),
                                                            media(dados_test_markov_chain,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_15000", minimo(dados_test_markov_chain,3*iteracoes,2,0,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,2,0,3),
                                                            media(dados_test_markov_chain,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_O_5000", minimo(dados_test_markov_chain,3*iteracoes,0,1,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,0,1,3),
                                                            media(dados_test_markov_chain,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_O_10000", minimo(dados_test_markov_chain,3*iteracoes,1,1,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,1,1,3),
                                                            media(dados_test_markov_chain,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","markov_chain_C_O_15000", minimo(dados_test_markov_chain,3*iteracoes,2,1,3),
                                                            maximo(dados_test_markov_chain,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_markov_chain,3*iteracoes,2,1,3),
                                                            media(dados_test_markov_chain,3*iteracoes,2,1,3));																												                                                        
   
   fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_100", minimo(dados_test_laplace_jacobi_4,3*iteracoes,0,0,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,0,0,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,0,0,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,0,0,3));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_150", minimo(dados_test_laplace_jacobi_4,3*iteracoes,1,0,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,1,0,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,1,0,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,1,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_200", minimo(dados_test_laplace_jacobi_4,3*iteracoes,2,0,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,2,0,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,2,0,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,2,0,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_O_100", minimo(dados_test_laplace_jacobi_4,3*iteracoes,0,1,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,0,1,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,0,1,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,0,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_O_150", minimo(dados_test_laplace_jacobi_4,3*iteracoes,1,1,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,1,1,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,1,1,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,1,1,3));
	fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","laplace_jacobi_4_C_O_200", minimo(dados_test_laplace_jacobi_4,3*iteracoes,2,1,3),
                                                            maximo(dados_test_laplace_jacobi_4,3*iteracoes,2,1,3),
                                                            desvioPadrao(dados_test_laplace_jacobi_4,3*iteracoes,2,1,3),
                                                            media(dados_test_laplace_jacobi_4,3*iteracoes,2,1,3));
    
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","munchausen_number_C", minimo(dados_test_munchausen_number,1*iteracoes,0,0,1),
                                                            maximo(dados_test_munchausen_number,1*iteracoes,0,0,1),
                                                            desvioPadrao(dados_test_munchausen_number,1*iteracoes,0,0,1),
                                                            media(dados_test_munchausen_number,1*iteracoes,0,0,1));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","munchausen_number_O_C", minimo(dados_test_munchausen_number,1*iteracoes,0,1,1),
                                                            maximo(dados_test_munchausen_number,1*iteracoes,0,1,1),
                                                            desvioPadrao(dados_test_munchausen_number,1*iteracoes,0,1,1),
                                                            media(dados_test_munchausen_number,1*iteracoes,0,1,1));
    
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","pernicious_numbers_C_100000", minimo(dados_test_pernicious_numbers,1*iteracoes,0,0,1),
                                                            maximo(dados_test_pernicious_numbers,1*iteracoes,0,0,1),
                                                            desvioPadrao(dados_test_pernicious_numbers,1*iteracoes,0,0,1),
                                                            media(dados_test_pernicious_numbers,1*iteracoes,0,0,1));
    fprintf(estatisticas,"%s,%lf,%lf,%lf,%lf\n","pernicious_numbers_O_C_100000", minimo(dados_test_pernicious_numbers,1*iteracoes,0,1,1),
                                                            maximo(dados_test_pernicious_numbers,1*iteracoes,0,1,1),
                                                            desvioPadrao(dados_test_pernicious_numbers,1*iteracoes,0,1,1),
                                                            media(dados_test_pernicious_numbers,1*iteracoes,0,1,1));
//   	fprintf(estatisticas,"%lf	,%lf	,%lf	,%lf	\n",maximo(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                           minimo(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                           media(dados_test_gauss_legendre_quadrature,3*iteracoes),
//                                                           desvioPadrao(dados_test_gauss_legendre_quadrature,3*iteracoes));


}


