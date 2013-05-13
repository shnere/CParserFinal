#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int main (int argc, char * const argv[]) {
    
	string linea;
	ifstream intermedio ("cuadruples.txt");
	char * pch ;
	bool pending = false;
	std::map<std::string, int> direcciones;
	int i = 1;
    
	if (intermedio.is_open()){

		// Checa datos
		while ( !intermedio.eof() ){
            getline(intermedio,linea);
            const char *arr = linea.c_str();
            pch = strtok ((char *)arr," ,():\t");
            
            while (pch != NULL){
    			// Si es variable
    			if(isalpha(pch[0]) && strcmp(pch, "goto") != 0 && strcmp(pch, "iffalse") != 0 && strcmp(pch, "iftrue") != 0  && strcmp(pch, "ift") != 0){ 
        			if(direcciones.find(pch) == direcciones.end()){
                        //printf("Agrego Variable: %s con %i\n", pch, i);
        				// Si no lo encuentra lo agrega
        				direcciones[pch] = i++; // El i luego lo casteamos a hex
        			}
    			}
                pch = strtok(NULL, " ,():\t");
            }
		}
        intermedio.close();
		ifstream intermedio ("cuadruples.txt");
		
		while ( !intermedio.eof() ){
			
			printf("\n");
			getline (intermedio,linea);
			const char *arr = linea.c_str();
			int lbl;
			
			//Label
			pch = strtok ((char *)arr," ,():\t");
			if(atoi(pch) != 0){

				
				printf("\nLBL%s:\n", pch);
				lbl = atoi(pch);
				if(lbl == 2){
					printf("\tNOP");
					break;
				}	
				while (atoi(pch) == 0) {
					pch = strtok ((char *)arr," ,():\t");
				}

			}else if (pending){
				printf("");
			}

			
			while (pch != NULL){//hasta terminar la linea
				
				if(strcmp(pch, "=") == 0){
					
					char * der = strtok(NULL, " ,():\t");
					char * izq = strtok(NULL, " ,():\t");
					
					if(isdigit(der[0]) == 0){
						printf("\tMOV 0%XH, 0%XH", direcciones.find(izq)->second, direcciones.find(der)->second);
					}else {
						printf("\tMOV 0%XH, #0%XH", direcciones.find(izq)->second, atoi(der));
					}
				}else if(strcmp (pch, "+") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if(strcmp(op1, res) == 0){
						
						
						if(isdigit(op2[0]) == 0){
							printf("\tADD %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tADD %s, #0%XH", "A", atoi(op2));
						}

 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("\tADD %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tADD %s, #0%XH", "A", atoi(op2));
						}
						
						printf("\n\tMOV 0%XH, %s", direcciones.find(res)->second, "A");
					}
					
					
				}else if(strcmp (pch, "-") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tSUBB %s, #0%XH", "A", atoi(op2));
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tSUBB %s, #0%XH", "A", atoi(op2));
						}
						
						printf("\n\tMOV 0%XH, %s", direcciones.find(res)->second, "A");
					}
				}else if(strcmp (pch, "*") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("\tMULT %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tMULT %s, #0%XH", "A", atoi(op2));
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("\tMULT %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tMULT %s, #0%XH", "A", atoi(op2));
						}
						
						printf("\n\tMOV 0%XH, %s", direcciones.find(res)->second, "A");
					}
				}else if(strcmp (pch, "/") == 0){
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * res = strtok(NULL, " ,():\t");
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if(strcmp(op1, res) == 0){
						
						if(isdigit(op2[0]) == 0){
							printf("\tDIV %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tDIV %s, #0%XH", "A", atoi(op2));
						}
						
 					}else {
						
						if(isdigit(op2[0]) == 0){
							printf("\tDIV %s, 0%XH", "A", direcciones.find(op2)->second);
						}else {
							printf("\tDIV %s, #0%XH", "A", atoi(op2));
						}
						
						printf("\n\tMOV 0%XH, %s", direcciones.find(res)->second, "A");
					}
				}else if (strcmp(pch, "==") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 	
					
					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");
					
					printf("\n\tJNZ LBL%s", label);
					pending = true;
					

					
				} else if (strcmp(pch, "!=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 	
					
					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");
					
					printf("\n\tJZ LBL%s", label);
					pending = true;
			
					
				}else if (strcmp(pch, "<") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 	
					
					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");


					printf("\n\tJNC LBL%s", label);
					pending = true;

				}else if (strcmp(pch, ">") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 	
					
					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");
					
					printf("\n\tJC LBL%s", label);
					pending = true;
					
				}else if (strcmp(pch, "<=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 		
					
					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");

					printf("\n\tJNC LBL%s", label);
					printf("\n\tJNZ LBL%s", label);
					pending = true;
					

					
				}else if (strcmp(pch, ">=") == 0) {
					char * op1 = strtok(NULL, " ,():\t");
					char * op2 = strtok(NULL, " ,():\t");
					char * label;
					strtok(NULL, " ,():\t");
					
					
					printf("\tMOV A, 0%XH\n", direcciones.find(op1)->second);
					if (isdigit(op2[0]) != 0) {
						printf("\tSUBB %s, #0%XH", "A", atoi(op2));
					}else {
						printf("\tSUBB %s, 0%XH", "A", direcciones.find(op2)->second);
					} 	 	

					getline(intermedio,linea);
					arr = linea.c_str();
					label = strtok ((char *)arr," ,():\t");
					
					while (strcmp(label, "goto") != 0) {
						label = strtok ( NULL ," ,():\t");
					}
					label = strtok ( NULL ," ,():\t");
					
					printf("\n\tJC %s", label);
					printf("\n\tJNZ %s", label);
					pending = true;
					
					
				}else if (strcmp(pch, "goto") == 0) {
					
					char * dest = strtok(NULL, " ,():\t");
					printf("\tSJMP LBL%s",dest);
	
				}
				pch = strtok(NULL, " ,():\t");
			}

		}

		intermedio.close();
	}
	
	else cout << "No se pudo abrir el archivo de codigo intermedio"<< endl;	
	return 0;
}