#ifndef LIBERVISUHDF_H
#define LIBERVISUHDF_H

#include <iostream>
#include <string.h>
#include "H5Cpp.h"
#include "hdf5.h"

#ifndef H5_NO_NAMESPACE
    using namespace H5;
#endif

using namespace std;

class c_HDF{

protected:
    string _fileName;
    int _nodeNum;
    int _cellNum;
    int _nodePerCell;
    int _varSize;
    char **_varName;
    char **_varType;
    int *_varLength;
    float *_x;
    float *_y;
    float *_z;
    int *_cellConnectivity, **_temp_cellConnectivity;
    float **_varMatrix;
    
protected:

    void _2DMatrixto1DArray();
    void _createDatasetH5_INT(H5File *file, int dim1, int dim2, int dim3, int rank, string varName, int *actual_data);
    void _createDatasetH5(H5File *file, int dim1, int dim2, int dim3, int rank, string varName, float *actual_data);
    void _writeH5();

public:

    c_HDF(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, char **varType, int *varLength, int varSize, float **varMatrix);
    ~c_HDF();

    void doAll(); //filecreation

};

#endif
