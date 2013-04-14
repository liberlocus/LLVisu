#include <iostream>
#include <string.h>
#include <fstream>

//#include "liberHDF.h"

using namespace std;

class c_XMF{
public:
    const char* _fileName;
    char *_gridName;// = NULL; 
    char *_gridType;// = NULL;
    char *_topoType;// = NULL;

    int _nodeNum;
    int _cellNum;
    int _nodePerCell;
    int _varSize;
    char **_varName, **_temp_varName;
    char **_varType, **_temp_varType;// = NULL;
    int *_varLength, *_temp_varLength;
    float *_x;
    float *_y;
    float *_z;
    int **_cellConnectivity;

    float **_varMatrix;

//    c_HDF *HDF;
public:
    c_XMF(const char* fileName,  char *_gridName, char *_gridType, char *_topoType, int num_nodes, float *x, float *y, float *z, int num_cells, int node_per_cell, int **cellConnectivity, char ** varName, char **varType,  int *varLength, int varSize, float **varMatrix);

    void fileCreation();

private:

    void writeXMF();

};
