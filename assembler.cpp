#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main (int argc, char * const argv[]) {
    
	string linea;
	ifstream intermedio ("6.txt");
	char * pch ;

	if (intermedio.is_open()){
		
		while ( !intermedio.eof() ){
			
			printf("\n");
			getline (intermedio,linea);
			const char *arr = linea.c_str();
			
			//Label
			pch = strtok ((char *)arr," ,():\t");
			if(atoi(pch) != 0){
				printf("%s:\n\t", pch);
			}else {
				printf("\t");
			}
			
			while (pch != NULL){//hasta terminar la linea
				
				if(strcmp(pch, "=") == 0){
					
					char * der = strtok(NULL, " ,():\t");
					char * izq = strtok(NULL, " ,():\t");
					
					if(isdigit(der[0]) == 0){
						printf("MOV %s, %s", izq, der);
					}else {
						printf("MOV %s, #%s", izq, der);
					}
				}else if(strcmp (pch, "+") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("ADD %s, %s", res, op2);
						}else {
							printf("ADD %s, #%s", res, op2);
						}

 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("ADD %s, %s", op1, op2);
						}else {
							printf("ADD %s, #%s", op1, op2);
						}
						
						printf("\n\tMOV %s, %s", res, op1);
					}
				}else if(strcmp (pch, "-") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("SUBB %s, %s", res, op2);
						}else {
							printf("SUBB %s, #%s", res, op2);
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("SUBB %s, %s", op1, op2);
						}else {
							printf("SUBB %s, #%s", op1, op2);
						}
						
						printf("\n\tMOV %s, %s", res, op1);
					}
				}else if(strcmp (pch, "*") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("MULT %s, %s", res, op2);
						}else {
							printf("MULT %s, #%s", res, op2);
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("MULT %s, %s", op1, op2);
						}else {
							printf("MULT %s, #%s", op1, op2);
						}
						
						printf("\n\tMOV %s, %s", res, op1);
					}
				}else if(strcmp (pch, "/") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("DIV %s, %s", res, op2);
						}else {
							printf("DIV %s, #%s", res, op2);
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("DIV %s, %s", op1, op2);
						}else {
							printf("DIV %s, #%s", op1, op2);
						}
						
						printf("\n\tMOV %s, %s", res, op1);
					}
				}else if (strcmp(pch, "==") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("EQ %s, %s", op1, op2);
					}else {
						printf("EQ %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
					
				} else if (strcmp(pch, "!=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("NE %s, %s", op1, op2);
					}else {
						printf("NE %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
				}else if (strcmp(pch, "<") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("LT %s, %s", op1, op2);
					}else {
						printf("LT %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
				}else if (strcmp(pch, ">") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("GT %s, %s", op1, op2);
					}else {
						printf("GT %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
				}else if (strcmp(pch, "<=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("LTE %s, %s", op1, op2);
					}else {
						printf("LTE %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
				}else if (strcmp(pch, ">=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					if (isdigit(op2[0]) == 0) {
						printf("GTE %s, %s", op1, op2);
					}else {
						printf("GTE %s, #%s", op1, op2);
					}
					
					printf("\n\tMOV %s, %s", res, op1);
				}else if (strcmp(pch, "goto") == 0) {
					
					char * dest = strtok(NULL, " ,():\t");
					printf("SJMP %s",dest);
				}else if (strcmp(pch, "iffalse") == 0) {
					char * var = strtok(NULL, " ,():\t");
					char * dest = strtok(NULL, " ,():\t");
					dest = strtok(NULL, " ,():\t");
					
					printf("CJNE %s,#0,%s", var, dest);
				}
				pch = strtok(NULL, " ,():\t");
			}

		}

		intermedio.close();
	}
	
	else cout << "No se pudo abrir el archivo de codigo intermedio"<< endl;	
	return 0;
}