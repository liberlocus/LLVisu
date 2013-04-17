/*
  liberOut.h - Scientific Visualization Library.
  Created by Liberlocus, Feb 2, 2013.
  Released into the public domain.
*/
#ifndef LIBERVISUOUT_H
#define LIBERVISUOUT_H

#include <string>
#include <iostream>
#include <fstream>

#include "liberVisuVTK.h"
//#include "H5Cpp.h"
//#include "hdf5.h"
//#include "liberVisuXMF.h"

//#ifndef H5_NO_NAMESPACE
//    using namespace H5;
//#endif

using namespace std;

void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix){

    c_VTK *VTK = new c_VTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix);
    VTK->doAll();
//    delete VTK;

    cout << "VTK file is created." << '\n';

}
//void liberVisuXMF(string, string, string, string, int,int,int,int, char**, char**, float**, float*, float*, float*, int**);

#endif

