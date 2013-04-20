#include "liberVisu.h"

int main(int argc, char **argv){

  string fileName = "mySolution" ;
  string gridName = "Unstructered" ;
  string gridType = "Uniform" ;
  string topoType = "Hexahedron" ;
  int cellNum = 2;
  int nodePerCell = 8;//Hexahedron
  int nodeNum = 16;
  int varSize = 2;

  float passed_x[16], passed_y[16],passed_z[16];
  float *cellData= NULL;
  float *cellData2= NULL;
//Send coordinates information
    passed_x[0] = 0; 
    passed_x[1] = 0; 
    passed_x[2] = 0; 
    passed_x[3] = 0; 
    passed_x[4] = 1; 
    passed_x[5] = 1; 
    passed_x[6] = 1; 
    passed_x[7] = 1; 
    passed_x[8] = 0; 
    passed_x[9] = 0; 
    passed_x[10] = 0; 
    passed_x[11] = 0; 
    passed_x[12] = 1; 
    passed_x[13] = 1; 
    passed_x[14] = 1; 
    passed_x[15] = 1; 
    passed_y[0] = 0; 
    passed_y[1] = 0; 
    passed_y[2] = 1; 
    passed_y[3] = 1; 
    passed_y[4] = 0; 
    passed_y[5] = 0; 
    passed_y[6] = 1; 
    passed_y[7] = 1; 
    passed_y[8] = 0; 
    passed_y[9] = 0; 
    passed_y[10] = 1; 
    passed_y[11] = 1; 
    passed_y[12] = 0; 
    passed_y[13] = 0; 
    passed_y[14] = 1; 
    passed_y[15] = 1; 
    passed_z[0] = 0; 
    passed_z[1] = 1; 
    passed_z[2] = 0; 
    passed_z[3] = 1; 
    passed_z[4] = 0; 
    passed_z[5] = 1; 
    passed_z[6] = 0; 
    passed_z[7] = 1; 
    passed_z[8] = -1; 
    passed_z[9] = 0; 
    passed_z[10] = -1; 
    passed_z[11] = 0; 
    passed_z[12] = -1; 
    passed_z[13] = 0; 
    passed_z[14] = -1; 
    passed_z[15] = 0; 
    cellData = new float[cellNum];
    cellData2 = new float[cellNum];
    cellData[0] = 20;
    cellData[1] = 30;
    cellData2[0] = 20;
    cellData2[1] = 21;

  char* varName[]={"ATemperature", "APressure"};
  char* varType[]={"Cell", "Cell"};
  int varLength[] = {cellNum, cellNum};

  int **cells=NULL;
  cells = new int *[cellNum];
  for(int i =0; i<cellNum; i++){
    cells[i] = new int [nodePerCell];
  }
//  int dummy_cells[2][8]={{0,1,2,3,4,5,6,7     },
//                         {8,9,10,11,12,13,14,15    }};
  int dummy_cells[2][8]={{0,1,3,2,4,5,7,6     },
                         {8,9,11,10,12,13,15,14    }};

  for(int i=0;i<cellNum;i++){
    for(int j=0;j<nodePerCell;j++){
      cells[i][j]=dummy_cells[i][j];
    }
  };
    
  float **varMatrix=NULL;

  varMatrix = new float *[varSize];
  varMatrix[0]=cellData;
  varMatrix[1]=cellData2;

  /*define cell distribution among processors.*/
  
//  liberOut(fileName,gridName, gridType,topoType, cellNum, nodePerCell,nodeNum,varSize, varName, varType, varMatrix,passed_x, passed_y, passed_z,cells);
  liberVisuVTK(fileName, nodeNum, passed_x, passed_y, passed_z, cellNum, nodePerCell, cells, varName, varSize, varMatrix);
  liberVisuXMF(fileName, gridName, gridType, topoType, nodeNum, passed_x, passed_y, passed_z, cellNum, nodePerCell, cells, varName, varType, varLength, varSize, varMatrix);

//  writeParallelHDF5();
//delete allocated arrays
  delete [] varMatrix;
  varMatrix=NULL;

  for (int i=0;i<cellNum;i++){
    delete [] cells[i];
    cells[i]=NULL;
  }
  delete [] cells;
  cells=NULL;

}
