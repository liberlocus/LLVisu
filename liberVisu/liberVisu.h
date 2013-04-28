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
/*!
LiberLocus Visualization main function definitions
*/

extern void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix);


extern void liberVisuXMF(string fileName, string gridName, string gridType, string topoType, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char **varName, char **varType, int *varLength, int varSize, float **varMatrix);

#endif

