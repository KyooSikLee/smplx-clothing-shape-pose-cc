#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void readFileToBuffer(string filename, double** buffer, int index);
void forward(double* weight, double* input, double* output, int numRow, int numCol);
void addBias(double* matrix, double* bias, int count);

#define NUM_LAYER 4

int main() {
    double* layerWeights[NUM_LAYER];
    double* layerBias[NUM_LAYER];
    for (int layer=0; layer < NUM_LAYER; layer++) {
        string weightFilename = "layer" + to_string(layer) + "weights";
        string biasFilename= "layer" + to_string(layer) + "bias";
        readFileToBuffer(weightFilename, layerWeights, layer);
        readFileToBuffer(biasFilename, layerBias, layer);
    }

    int dimensions[5] = {20752, 128, 64, 128, 5283}; // TO_BE_CHANGED

    double input[20752] = {1}; // TO_BE_CHANGED
    double output[20752];

    // UnrealEngine ParallelFor 
    for (int layer=0; layer < NUM_LAYER; layer++) {
        forward(layerWeights[layer], input, output, dimensions[layer+1], dimensions[layer]);
        addBias(output, layerBias[layer], dimensions[layer+1]);
        memcpy(input, output, 20752*4);
    }
    for (int i=0; i< 5283; i++) {
        cout<<output[i]<<" ";
    }
}

void readFileToBuffer(string filename, double** buffer, int index) {
    ifstream file (filename, ios::in|ios::binary|ios::ate);
    int size = file.tellg();
    char* memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();
    buffer[index] = (double*)memblock;
}

void forward(double* weight, double* input, double* output, int numRow, int numCol) {
    for (int row=0; row < numRow; row++) {
        double sum = 0.0;
        for (int k=0; k<numCol; k++) {
            sum += weight[row * numCol + k] * input[k];
        }
        output[row] = sum;
    }
}

void addBias(double* matrix, double* bias, int count) {
    for (int i=0; i<count; i++) {
        matrix[i] += bias[i];
    }
}
