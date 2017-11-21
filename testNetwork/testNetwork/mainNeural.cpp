#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include "learningFunction.h"
using namespace std;

struct wmatrix												//weights matrix type	
{
	int CountOfNeurons;										//comes out of the neuron
															//enters the neuron
	double **weights;
};
const int numberOfLayers = 3;								//кол-во слоев
int addition[numberOfLayers + 1];							//массив с добавлениями к кол-ву нейронов в каждом слое
int CountOfNeurons = 6;

double random(int min, int max);
void print();
void valueOfNeuron(int inputLayer);
void sigm(int inputLayer);
int answer();
wmatrix sweights;											//глобальное объевление,что бы не передавать в ф-ии 

int main() {

	sweights.CountOfNeurons = CountOfNeurons;
	sweights.weights = new double*[CountOfNeurons]; //create big matrix

	for (int i = 0; i < CountOfNeurons; i++)
		sweights.weights[i] = new double[i + 1];

	for (int i = 0; i < sweights.CountOfNeurons; i++) {
		for (int j = 0; j < i + 1; j++) {
			sweights.weights[i][j] = 0;						//обнуление матрицы
		}
	}

	srand((unsigned)time(NULL));

	int numOfNeuInLayer[] = { 2,3,1 };						//кол-во нейронов в каждом слое

	addition[0] = 0;
	addition[4] = 6;

	for (int i = 1; i <= numberOfLayers; i++) {
		addition[i] = addition[i - 1] + numOfNeuInLayer[i - 1];
		cout << "addition to neurons in" << i << " layer is " << addition[i] << endl;
	}

	for (int i = 0; i < numberOfLayers; i++)
		for (int k = addition[i]; k < addition[i + 1]; k++) {
			for (int j = addition[i + 1]; j < addition[i + 2]; j++) {
				sweights.weights[j][k] = random(0, 1);
				cout << sweights.weights[j][k] << "	";
			}
			cout << endl;
		}
	cout << endl;

	for (int i = 0; i < numOfNeuInLayer[0]; i++) {
		sweights.weights[i][i] = rand() % 2 + 0;			//1 или 0 во входных значениях
	}

	cout << endl;
	valueOfNeuron(0);
	valueOfNeuron(1);
	print();
	cout << "answer is " << answer() << endl;
	cout << gotWeights(sweights.weights[0][0]) << endl; 
//	cout << "vot " << lalka();
	sweights.weights[2][0] = setWeigth(sweights.weights[2][0], sweights.weights[0][0], 0.1, 0.1);
	cout << sweights.weights[2][0];
	system("pause");

}

double random(int min, int max) {
	double random = (double)rand() / (RAND_MAX + 1) * (max - min) + min;
	return random;
}

void print() {
	{

		for (int i = 0; i < sweights.CountOfNeurons; i++) {
			for (int j = 0; j < i + 1; j++) {
				cout << sweights.weights[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void valueOfNeuron(int inputLayer) {

	for (int j = addition[inputLayer + 1]; j < addition[inputLayer + 2]; j++)
		for (int k = addition[inputLayer]; k < addition[inputLayer + 1]; k++) {

			sweights.weights[j][j] = sweights.weights[j][j] + sweights.weights[k][k] * sweights.weights[j][k];
		}

	sigm(inputLayer);
}

void sigm(int inputLayer) {
	for (int j = addition[inputLayer + 1]; j < addition[inputLayer + 2]; j++) {
		sweights.weights[j][j] = (1 / (1 + exp(-sweights.weights[j][j])));
		cout << "[" << j << "]""[" << j << "]" << " " << sweights.weights[j][j] << endl;
	}
}

int answer() {

	if ((sweights.weights[CountOfNeurons - 1][CountOfNeurons - 1]) > 0.5)
		return 1;
	else
		return 0;
}
float getWeight(int row, int cow) {
	return sweights.weights[row][cow];
}
