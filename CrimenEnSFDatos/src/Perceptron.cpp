//============================================================================
// Name        : Perceptron.cpp
// Author      : Brasburg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Perceptron {
	float producto(float *pesos, int *entradas, int largo);
	float pesos[3];
	float umbral;
	float tazaAprendizaje;
	int resultado(float sum);
  public:
	Perceptron();
	void aprender(int *entradas,int esperado);
	int clasificar(int *entradas);
};

Perceptron::Perceptron(){
	for(int i = 0; i< 3;i++){
		pesos[i] = 0;
	}
	umbral = 0.4;
	tazaAprendizaje = 0.2;
}

float Perceptron::producto(float pesos[], int *entradas, int largo){
	float sum = 0;
	for(int i = 0; i < largo;i++){
		sum = pesos[i]*entradas[i];
	}
	return sum;
}

int Perceptron::resultado(float sum){
	return (sum > umbral);
}

void Perceptron::aprender(int *entradas,int esperado){
	int error = esperado - clasificar(entradas);
	if(error != 0){
		for(int i = 0; i < 3;i++){
			pesos[i] = pesos[i] + tazaAprendizaje * error * entradas[i];
		}
	}
	printf("%f %f %f \n", pesos[0],pesos[0],pesos[0]);
}

int Perceptron::clasificar(int *entradas){
	return resultado(producto(pesos,entradas,3));
}

int main() {
	Perceptron p;
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 2;j++){
			for(int x = 0; x < 2;x++){
				int e[] = {i,j,x};
				int result = i or x or j;
				p.aprender(e,result);
			}
		}
	}
	int total = 0;
	int correcto = 0;
	for(int i = 0;i < 2;i++){
			for(int j = 0;j < 2;j++){
				for(int x = 0; x < 2;x++){
					int e[] = {i,j,x};
					int result = i or x or j;
					printf("Or(%i,%i,%i) = %i \n",i,j,x,p.clasificar(e));
					if(p.clasificar(e) == result){
						correcto++;
					}
					total++;
				}
			}
	}
	printf("La taza fue %i / %i", correcto,total);
	return 0;
}

