#include "liberVisuXMF.h"

c_XMF::c_XMF(string fileName, string gridName, string gridType, string topoType, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, char **varType, int varSize, float **varMatrix){

    _fileName= fileName;
    _gridName=gridName;
    _gridType=gridType;
    _topoType=topoType;
//  Related to Points
    _nodeNum = nodeNum;
    _x = x;
    _y = y;
    _z = z;
////  Related to Cells
    _cellNum = cellNum;
    _nodePerCell = nodePerCell;

    _cellConnectivity = cellConnectivity;
////  Related to CellCenterData
    _varSize = varSize;
    _temp_varName = varName;
    _temp_varType = varType;
    _varName = new char*[_varSize];
    _varType = new char*[_varSize];
    _varLength = new int[_varSize];
    _varMatrix = new float*[_varSize];

    for(int i=0; i<_varSize;i++){
      _varName[i]=varName[i];
      _varType[i]=varType[i];
      if(strcmp(_varType[i],"Cell")==0){
        _varLength[i] = _cellNum;
      }
      else if(strcmp(_varType[i],"Node")==0){
        _varLength[i] = _nodeNum;
      }
    }
////  Related to Variable Matrix
     _varMatrix = varMatrix;

}
