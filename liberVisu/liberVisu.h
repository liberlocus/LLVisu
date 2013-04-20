/*
  liberOut.h - Scientific Visualization Library.
  Created by Liberlocus, Feb 2, 2013.
  Released into the public domain.
*/
#ifndef LIBERVISUOUT_H
#define LIBERVISUOUT_H

#include "liberVisuVTK.h"
#include "liberVisuXMF.h"

using namespace std;

void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix){

    c_VTK *VTK = new c_VTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix);
    VTK->doAll();
//    delete VTK;

    cout << "VTK file is created." << '\n';

}

void liberVisuXMF(string fileName, string gridName, string gridType, string topoType, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char **varName, char **varType, int *varLength, int varSize, float **varMatrix){

    c_XMF *XMF = new c_XMF(fileName, gridName, gridType, topoType, nodeNum, x, y, z, cellNum, nodePerCell, cellConnectivity, varName, varType, varLength, varSize, varMatrix);
    XMF->doAll();
//    delete XMF;

    cout << "XMF file is created." << '\n';

}

#endif

