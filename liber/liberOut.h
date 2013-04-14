/*
  liberOut.h - Library for multidisciplinary output code.
  Created by Liberlocus, Feb 2, 2013.
  Released into the public domain.
*/
#include <string>
//#include <string.h>
#include <iostream>
#include <fstream>

//#include "H5Cpp.h"
//#include "hdf5.h"
#include "liberVTK.h"
#include "liberXMF.h"

//#ifndef H5_NO_NAMESPACE
//    using namespace H5;
//#endif

using namespace std;

void liberOut(const char*, char*, char*, char*,int,int,int,int, char**, char**, float**, float*, float*, float*, int**);

#ifndef output_h
#define output_h

class Output{
  /*!This is Output class

  */
   public:
/*! SetNames: smth stmh */
    void setNames(const char*, char*, char*,char*);
/*! SetVariables: smth stmh */
    void setVariables(int, char**, char**, float**);
    void setGeometryValues(int,int,int, float*, float*, float*, int**);   

// Output Related
    void createVTKObject();
    void createXMFObject();
//Constructor deconstrutor
    ~Output();  
  private:

    //data
    const char *_fileName;// = NULL; 
    char *_gridName;// = NULL; 
    char *_gridType;// = NULL;
    char *_topoType;// = NULL;

    float *_x, *_y, *_z;
    int *_cellConMatrix;
    int **_actualCellConMatrix;
    int _varSize;
    char **_varName;// = NULL;
    char **_varType;// = NULL;
    int *_varLength;
    float **_varMatrix;
    int _cellNum;
    int _nodePerCell;
    int _nodeNum;
    c_VTK *VTK;
    c_XMF *XMF;

}; 


#endif

