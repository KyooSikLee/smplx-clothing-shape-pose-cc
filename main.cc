#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

void matmul(double* matrixA, double* matrixB, double* matrixC, int numARow, int numACol);
void addBias(double* matrix, double* bias, int count);
int readFileToBuffer(char* filename, double* buffer);

#define NUM_LAYER 4

int main() {

    double* layerWeights[NUM_LAYER];
    double* layerBias[NUM_LAYER];
    ifstream file ("layer0", ios::in|ios::binary|ios::ate);
    int size = file.tellg();
    char* memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    double* layer0weights = (double*)memblock;//reinterpret as doubles

    //128 * 20752

    double input[20752] = {1};
    double output[128];
    matmul(layer0weights, input, output, 128, 20752);
    for (int i=0; i< 129; i++) {
        cout<<output[i]<<" ";
    }
}

void matmul(double* matrixA, double* matrixB, double* matrixC, int numARow, int numACol) {
    for (int row=0; row < numARow; row++) {
        double sum = 0.0;
        for (int k=0; k<numACol; k++) {
            sum += matrixA[row * numACol + k] * matrixB[k];
        }
        matrixC[row] = sum;
    }
}

void addBias(double* matrix, double* bias, int count) {
    for (int i=0; i<count; i++) {
        matrix[i] += bias[i];
    }
}
