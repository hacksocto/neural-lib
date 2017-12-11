#include "stdafx.h"
#include "learningFunction.h"
#include "mainNeural.h"
#include "matrix.h"

//int inputLayer[] = { 0,1 };

void main() {
	int expected;
	int epoch = 100;
	double **weights;
	int neuronsPerLayer[] = { 2,3,1 };
	int layersNum = 3, neuronsNum = 0;
	neuronsNum = neuronsCounter(neuronsPerLayer, layersNum);
	weights = matrixCreation(neuronsPerLayer, layersNum);
	for (int i = 0; i < epoch; i++) {
		cout << "epoch #" << i << "\t" << "Enter inputs" << "\n";
		for (int j = 0; j < neuronsPerLayer[0]; j++){
			cout << "I" << j << ":";
			cin >> weights[j][j];
		}
		cout << "expected:";
		cin >> expected;
		weights = forwardWay(weights, neuronsPerLayer, layersNum, expected);
		writeToFile("weights.txt", weights, neuronsNum);
																				//добавить метод ОРО
	}
	system("pause");
}




/*
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