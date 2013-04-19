#ifndef LIBERVISUXMF_H
#define LIBERVISUXMF_H

#include <iostream>
#include <string>
#include <string.h>


//#include <liberVisuHDF.h>

using namespace std;

class c_XMF{

protected:
    string _fileName;
    string _gridName;
    string _gridType;
    string _topoType;

    int _nodeNum;
    int _cellNum;
    int _nodePerCell;
    int _varSize;
    char **_varName, **_temp_varName;
    char **_varType, **_temp_varType;// = NULL;
    int *_varLength;
    float *_x;
    float *_y;
    float *_z;
    int **_cellConnectivity;
    float **_varMatrix;
    
protected:

    void writeXMF();

public:

    c_XMF(string fileName, string _gridName, string _gridType, string _topoType, int num_nodes, float *x, float *y, float *z, int num_cells, int node_per_cell, int **cellConnectivity, char ** varName, char **varType, int varSize, float **varMatrix);
    ~c_XMF();

    void doAll(); //filecreation


};

//void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix){
//
//    c_VTK *VTK = new c_VTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix);
//    VTK->doAll();
//    delete VTK;
//
//}

#endif
