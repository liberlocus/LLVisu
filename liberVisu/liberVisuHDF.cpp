#include "liberVisuHDF.h"

c_HDF::c_HDF(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, char **varType,int *varLength, int varSize, float **varMatrix){

    _fileName= fileName;
    _nodeNum = nodeNum;
    _cellNum = cellNum;
    _nodePerCell = nodePerCell;
    _temp_cellConnectivity = cellConnectivity;

    _x = x;
    _y = y;
    _z = z;

    _varSize = varSize;
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
    _varMatrix = varMatrix;


}

void c_HDF::doAll(){

    _2DMatrixto1DArray();
    _writeH5();

}

void c_HDF::_2DMatrixto1DArray(){

   _cellConnectivity = new int [_cellNum*_nodePerCell];

   for(int i =0; i<_cellNum; i++){
     for(int j =0; j<_nodePerCell; j++){
       _cellConnectivity[i*_nodePerCell+j] = _temp_cellConnectivity[i][j];
     }
   }

}

void c_HDF::_createDatasetH5_INT(H5File *file, int dim1, int dim2, int dim3, int rank, string varName, int *actual_data){

    IntType datatype(PredType::NATIVE_INT);
    datatype.setOrder(H5T_ORDER_LE);
    hsize_t *fdim; // dim sizes of ds (on disk)
    if(rank == 1){
    fdim = new hsize_t[rank]; // dim sizes of ds (on disk)
    fdim[0] = hsize_t(dim1);
    }
    if(rank == 2){
    fdim = new hsize_t[rank]; // dim sizes of ds (on disk)
    fdim[0] = hsize_t(dim1);
    fdim[1] = hsize_t(dim2);
    }
    DataSpace fspace( rank, fdim );

  string pre="/";
  string fileFullName=pre+varName;

  H5std_string DATASET_NAME( fileFullName );
  DataSet *dataset = new DataSet(file->createDataSet(
  DATASET_NAME, datatype, fspace));
  dataset->write(actual_data, PredType::NATIVE_INT);

    delete [] fdim;
    delete dataset ;

}

void c_HDF::_createDatasetH5(H5File *file, int dim1, int dim2, int dim3, int rank, string varName, float *actual_data){

    IntType datatype(PredType::NATIVE_FLOAT);
    datatype.setOrder(H5T_ORDER_LE);
    hsize_t *fdim; // dim sizes of ds (on disk)
    if(rank == 1){
    fdim = new hsize_t[rank]; // dim sizes of ds (on disk)
    fdim[0] = hsize_t(dim1);
    }
    if(rank == 2){
    fdim = new hsize_t[rank]; // dim sizes of ds (on disk)
    fdim[0] = hsize_t(dim1);
    fdim[1] = hsize_t(dim2);
    }
    DataSpace fspace( rank, fdim );

  string pre="/";
  string fileFullName=pre+varName;

  H5std_string DATASET_NAME( fileFullName );
  DataSet* dataset = new DataSet(file->createDataSet(
  DATASET_NAME, datatype, fspace));
  dataset->write(actual_data, PredType::NATIVE_FLOAT);

    delete [] fdim;
    delete dataset;

}

void c_HDF::_writeH5(){

  //Creating data array

  string extension=".h5";
  string fileFullName=string(_fileName)+extension;
  H5std_string FILE_NAME( fileFullName );
   
  H5File* file = new H5File( FILE_NAME, H5F_ACC_TRUNC );
  /*
   * Create dataspace for the dataset in the file.
   */
  IntType datatype(PredType::NATIVE_INT);
  datatype.setOrder(H5T_ORDER_LE);
  /*
   * Create dataset and write it into the file.
   */
  // Write Node Locations
  _createDatasetH5(file, _nodeNum, 1, 1, 1, "X", _x);
  _createDatasetH5(file, _nodeNum, 1, 1, 1, "Y", _y);
  _createDatasetH5(file, _nodeNum, 1, 1, 1, "Z", _z);
  // Write Cell Connectivity
  _createDatasetH5_INT(file, _cellNum, _nodePerCell, 1, 2, "Cells", _cellConnectivity);
//  // Write Variables
  for (int i=0; i<_varSize; i++){
  _createDatasetH5(file, _varLength[i], 1, 1, 1, _varName[i], _varMatrix[i]);
  }
  delete file;
  cout<< "H5 method exited normally."<<'\n'; 
}

