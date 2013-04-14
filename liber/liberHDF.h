#ifndef LIBERHDF_H
#define LIBERHDF_H

#include <iostream>
#include <string.h>
#include "H5Cpp.h"
#include "hdf5.h"

#ifndef H5_NO_NAMESPACE
    using namespace H5;
#endif

using namespace std;

class c_HDF{
public:
    const char* _fileName;
    int _nodeNum;
    int _cellNum;
    int _nodePerCell;

    int *_cellConnectivity, **_temp_cellConnectivity;

    int _varSize;
    
    char **_varName;
    char **_varType;
    int *_varLength;
    float *_x;
    float *_y;
    float *_z;

    float **_varMatrix;

public:
    c_HDF(const char* fileName, int _nodeNum, float *x, float *y, float *z, int cellNum, int _nodePerCell, int **cellConnectivity, char ** varName, char **_varType, int *varLength, int varSize, float **varMatrix);
    void fileCreation();

private:
    void _2DMatrixto1DArray();
    void _createDatasetH5_INT(H5File *file, int dim1, int dim2, int dim3, int rank, char *varName, int *actual_data);
    void _createDatasetH5(H5File *file, int dim1, int dim2, int dim3, int rank, char *varName, float *actual_data);
    void _writeH5();

};

#endif
