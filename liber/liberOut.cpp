#include "liberOut.h"

using namespace std;

void liberOut(const char* fileName, char* gridName, char* gridType, char* topoName,int cellNum, int nodePerCell, int nodeNum, int varSize, char** varName, char** varType, float** varMatrix, float *x, float *y, float *z, int** cellConMatrix){

Output *output1=NULL;
output1 = new Output();

////// set all the input parameters correctly
output1->setNames(fileName,gridName, gridType,topoName);
output1->setGeometryValues(cellNum,nodePerCell,nodeNum,x, y, z, cellConMatrix);
output1->setVariables(varSize, varName, varType, varMatrix);
//
output1->createVTKObject();
output1->createXMFObject();

delete output1;

}

Output::~Output(){

}

void Output::setNames(const char *fileName, char *gridName, char *gridType, char *topoType){

  _fileName=fileName;
  _gridName=gridName;
  _gridType=gridType;
  _topoType=topoType;
}

void Output::setVariables( int varSize, char** varName, char** varType, float** varMatrix){

  _varSize=varSize;
  _varName=varName;
  _varType=varType;
  _varMatrix = varMatrix; 

}

void Output::setGeometryValues(int cellNum, int nodePerCell, int nodeNum, float *x, float *y, float *z, int **cellConMatrix){

  _cellNum=cellNum;
  _nodePerCell=nodePerCell;
  _nodeNum=nodeNum;
  _x = x;
  _y = y;
  _z = z;

  _actualCellConMatrix = cellConMatrix ;

}

void Output::createVTKObject(){

    VTK = new c_VTK(_fileName,_nodeNum, _x, _y, _z, _cellNum, _nodePerCell, _actualCellConMatrix,_varName, _varSize, _varMatrix);
    VTK->fileCreation();

}

void Output::createXMFObject(){

    XMF = new c_XMF(_fileName, _gridName, _gridType, _topoType, _nodeNum, _x, _y, _z, _cellNum, _nodePerCell, _actualCellConMatrix,_varName, _varType, _varLength,_varSize, _varMatrix);
    XMF->fileCreation();

}

