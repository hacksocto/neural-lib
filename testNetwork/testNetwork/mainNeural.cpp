#include "stdafx.h"
#include "learningFunction.h"
#include "mainNeural.h"
#include "matrix.h"

//int inputLayer[] = { 0,1 };

void main() {
	int neuronsPerLayer[] = { 2,3,1 };
	int layersNum = 3;
	const char str[] = "sas";

	matrixCreation(neuronsPerLayer, layersNum);
	//fileWrite("weights.txt", str);
	//searchInFile("weights.txt", 1, 1);
	system("pause");
}




/*	valueOfNeuron(0);
	valueOfNeuron(1);
	print();
	cout << "answer is " << answer() << endl;
	system("pause");

	//TRAINING
	int  epochs = 10;
	for (int e = 0;e < epochs;e++) {
		weights_delta_last(sweights.weights[CountOfNeurons - 1][CountOfNeurons - 1], expectedValue()); //считаем дельту весов для последнего слоя

		for (int i = addition[numberOfLayers - 2];i < addition[numberOfLayers - 1];i++) {       //присваиваем новые значения весам ,идущим к последнему слою (52,53,54) |потом изменить числа на цикл|
			sweights.weights[addition[numberOfLayers - 1]][i] = new_weight_last(sweights.weights[i][i], sweights.weights[addition[numberOfLayers - 1]][i]);
		}
		//изменить алг:
		for (int i = addition[numberOfLayers - 2];i < addition[numberOfLayers - 1];i++) {
			double error = error_of_neu(sweights.weights[addition[numberOfLayers - 1]][i]);						//считаем ошибку для каждого нейрона
			for (int k = 0;k < addition[numberOfLayers - 2];k++) {
				sweights.weights[i][k] = new_weight(sweights.weights[i][i], sweights.weights[i][k], error);     //присваиваем новые значения весам,идущим к остальным нейронам.
			}
		}

		for (int i = 0;i < 2;i++) {
			valueOfNeuron(i);
		}
	}
	print();
	cout << "answer is " << answer() << endl;
	system("pause");

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
		//cout << "[" << j << "]""[" << j << "]" << " " << sweights.weights[j][j] << endl;
	}
}

int answer() {

	if ((sweights.weights[CountOfNeurons - 1][CountOfNeurons - 1]) > 0.5)
		return 1;
	else
		return 0;
}


double expectedValue() {
	if ((sweights.weights[0][0] == 1) || (sweights.weights[1][1] == 1)) {
		return 1;
	}
	else return 0;	
}

*/