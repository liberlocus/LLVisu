#ifndef LIBERVISUVTK_CPP
#define LIBERVISUVTK_CPP

#include "liberVisuVTK.h"

c_VTK::c_VTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, int varSize, float **varMatrix){

    _fileName= fileName;
//  Related to Points
    _nodeNum = nodeNum;
    _x = new float[_nodeNum];
    _y = new float[_nodeNum];
    _z = new float[_nodeNum];
    _x = x;
    _y = y;
    _z = z;
//  Related to Cells
    _cellNum = cellNum;
    _nodePerCell = nodePerCell;

    _cellConnectivity = new int *[_cellNum];
    for(int i =0; i<_cellNum; i++){
     _cellConnectivity[i] = new int [_nodePerCell];
    }
    _cellConnectivity = cellConnectivity;
//  Related to CellCenterData
    _varSize = varSize;
    _varName = new char*[_varSize];
    for(int i=0; i<_varSize;i++){
      _varName[i]=varName[i];
    }
    _varName = varName;

//  Related to Variable Matrix
     _varMatrix = new float*[_varSize];
     for(int i=0; i<_varSize;i++){
       _varMatrix[i] = new float [_cellNum];
     }
     _varMatrix = varMatrix;

}

c_VTK::~c_VTK(){

  
//    delete [] _x;
//    _x = NULL;
//
//    delete [] _y;
//    _y = NULL;
//
//    delete [] _z;
//    _z = NULL;

    for(int i=0; i<_cellNum; i++){
        delete []  _cellConnectivity[i];
        _cellConnectivity[i] = NULL;
    }
    delete [] _cellConnectivity;
    _cellConnectivity = NULL;

    delete [] _varName;
    _varName = NULL;

    for(int i=0; i<_varSize; i++){
        delete []  _varMatrix[i];
        _varMatrix[i] = NULL;
    }
    delete [] _varMatrix;
    _varMatrix = NULL;

}

void c_VTK::createPoints(){

    _points = vtkSmartPointer<vtkPoints>::New();
    for(int i=0; i<_nodeNum; i++){
       _points->InsertNextPoint(_x[i], _y[i], _z[i]);
    }
}

void c_VTK::createCells(){

//  Allocate Cells
    _voxel = new vtkSmartPointer<vtkVoxel>[_cellNum];
    for(int i=0; i<_cellNum; i++){
    _voxel[i] = vtkSmartPointer<vtkVoxel>::New();
    }


    for(int i=0; i<_cellNum; i++){
      for(int j=0; j<_nodePerCell; j++){
        _voxel[i]->GetPointIds()->SetId(j, _cellConnectivity[i][j]);
      }
    }

    _cellArray = vtkSmartPointer<vtkCellArray>::New();
    for(int i=0; i<_cellNum; i++){
      _cellArray->InsertNextCell(_voxel[i]);
    }

}
void c_VTK::createCellCenterData(){

    _cellCenterData = new vtkSmartPointer<vtkDoubleArray>[_varSize];

    for(int i=0; i<_varSize; i++){
      _cellCenterData[i] = vtkSmartPointer<vtkDoubleArray>::New();
    }

    for(int i=0; i<_varSize; i++){
      _cellCenterData[i]->SetName(_varName[i]);
//1 for being scalar, should be 3 for vector quantites
      _cellCenterData[i]->SetNumberOfComponents(1);
      _cellCenterData[i]->SetNumberOfValues(_cellNum);
      for(int j=0; j<_cellNum; j++){
          _cellCenterData[i]->SetValue(j,_varMatrix[i][j]);
      }

    }

}

void c_VTK::createNodalData(){
}

void c_VTK::createGrid(){

    _unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    _unstructuredGrid->SetPoints(_points);
    _unstructuredGrid->SetCells(VTK_VOXEL, _cellArray);
    for(int i=0; i<_varSize; i++){
      _unstructuredGrid->GetCellData()->AddArray(_cellCenterData[i]);
    }

}

string c_VTK::getFileName(){

    string f1, f2, ff;

    f1 = _fileName;
    f2 = ".vtu";

    ff = f1 + f2;
    return ff;

}

void c_VTK::writeFile(){

    _writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();

    string fileName = getFileName();
    _writer->SetFileName(fileName.c_str());

#if VTK_MAJOR_VERSION <= 5
  _writer->SetInput(_unstructuredGrid);
#else
  _writer->SetInputData(_unstructuredGrid);
#endif
  _writer->Write();

}

void c_VTK::doAll(){

    fileCreation();

}

void c_VTK::fileCreation(){

    createPoints();
    createCells();
    createCellCenterData();
    createGrid();
    writeFile();

}

#endif
