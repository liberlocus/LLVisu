#include "liberXMF.h"

c_XMF::c_XMF(const char* fileName, char *gridName, char *gridType, char *topoType, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, char **varType,  int *varLength, int varSize, float **varMatrix){

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
    _temp_varLength = varLength;
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

void c_XMF::writeXMF(){

   char* extension=".xmf";
   string fileFullName=string(_fileName)+string(extension);
   ofstream outmyfile;
   
   outmyfile.open(fileFullName.c_str());
   outmyfile << "<?xml version=\"1.0\" ?>" << '\n';
   outmyfile << "<!DOCTYPE Xdmf SYSTEM \"Xdmf.dtd\" []>" << '\n';
   outmyfile << "<Xdmf Version=\"2.0\">" << '\n';
   outmyfile << " <Domain>" << '\n';
   outmyfile << "   <Grid Name=\""<< _gridName <<"\" GridType=\""<< _gridType <<"\">" << '\n';
   outmyfile << "     <Topology TopologyType=\""<< _topoType <<"\" NumberOfElements=\"" << _cellNum << "\">" << '\n';
   outmyfile << "       <DataItem Dimensions=\"" << _cellNum <<" " << _nodePerCell << "\" NumberType=\"Float\" Precision=\"4\" Format=\"HDF\">" << '\n';
   outmyfile << "        "<< _fileName <<".h5:/Cells" << '\n';
   outmyfile << "       </DataItem>" << '\n';
   outmyfile << "     </Topology>" << '\n';
   outmyfile << "     <Geometry GeometryType=\"X_Y_Z\">" << '\n';
   outmyfile << "       <DataItem Dimensions=\"" << _nodeNum << "\" NumberType=\"Float\" Precision=\"4\" Format=\"HDF\">" << '\n';
   outmyfile << "        "<< _fileName <<".h5:/X" << '\n';
   outmyfile << "       </DataItem>" << '\n';
   outmyfile << "       <DataItem Dimensions=\"" << _nodeNum << "\" NumberType=\"Float\" Precision=\"4\" Format=\"HDF\">" << '\n';
   outmyfile << "        "<< _fileName <<".h5:/Y" << '\n';
   outmyfile << "       </DataItem>" << '\n';
   outmyfile << "       <DataItem Dimensions=\"" << _nodeNum << "\" NumberType=\"Float\" Precision=\"4\" Format=\"HDF\">" << '\n';
   outmyfile << "        "<< _fileName <<".h5:/Z" << '\n';
   outmyfile << "       </DataItem>" << '\n';
   outmyfile << "     </Geometry>" << '\n';
                for(int i=0; i<_varSize ; i++){
   outmyfile << "     <Attribute Name=\""<< _varName[i] << "\" AttributeType=\"Scalar\" Center=\""<<_varType[i]<<"\">"<< '\n';
   outmyfile << "       <DataItem Dimensions=\"" << _varLength[i] << "\" NumberType=\"Float\" Precision=\"4\" Format=\"HDF\">" << '\n';
   outmyfile << "        "<< _fileName <<".h5:/" << _varName[i] << '\n';
   outmyfile << "       </DataItem>" << '\n';
   outmyfile << "     </Attribute>" << '\n';
                }
   outmyfile << "   </Grid>"<< '\n';
   outmyfile << " </Domain>"<< '\n';
   outmyfile << "</Xdmf>"<< '\n';
   
   outmyfile.close();

}

void c_XMF::fileCreation(){

//     HDF = new c_HDF(_fileName,_nodeNum, _x, _y, _z, _cellNum, _nodePerCell, _cellConnectivity,_temp_varName, _temp_varType, _temp_varLength, _varSize, _varMatrix);
//     HDF->fileCreation();
     
     writeXMF();
     
}
