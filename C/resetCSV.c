#include<stdio.h>
#define numeroDeTestes 11

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

int main(){
    FILE* arquivos[numeroDeTestes];
    
    arquivos[test_belief_propagation] = fopen("test_belief_propagation_C.csv","w");
    arquivos[test_copy_matrix] = fopen("test_copy_matrix_C.csv","w");
    arquivos[test_evaluate_functions] = fopen("test_evaluate_functions_C.csv","w");
    arquivos[test_fibonacci] = fopen("test_fibonacci_C.csv","w");
    arquivos[test_gauss_legendre_quadrature] = fopen("test_gauss_legendre_quadrature_C.csv","w");
    arquivos[test_laplace_jacobi_4] = fopen("test_laplace_jacobi_4_C.csv","w");
    arquivos[test_look_and_say] = fopen("test_look_and_say_C.csv","w");
    arquivos[test_markov_chain] = fopen("test_markov_chain_C.csv","w");
    arquivos[test_matrix_multiplication] = fopen("test_matrix_multiplication_C.csv","w");
    arquivos[test_munchausen_number] = fopen("test_munchausen_number_C.csv","w");
    arquivos[test_pernicious_numbers] = fopen("test_pernicious_numbers_C.csv","w");

}