#ifndef LIBERVISUVTK_H
#define LIBERVISUVTK_H

#include <iostream>
#include <string>

#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkTetra.h>
#include <vtkVoxel.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkXMLPUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPointData.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkDoubleArray.h>

using namespace std;

class c_VTK{

protected:
    string _fileName;
    int _nodeNum;
    int _cellNum;
    int _nodePerCell;
    int _varSize;
    char **_varName;
    float *_x;
    float *_y;
    float *_z;
    int **_cellConnectivity;
    float **_varMatrix;
// Needed by VTK
    vtkSmartPointer<vtkPoints> _points;
    vtkSmartPointer<vtkVoxel> *_voxel; 
    vtkSmartPointer<vtkCellArray> _cellArray;
    vtkSmartPointer<vtkDoubleArray> *_cellCenterData;
    vtkSmartPointer<vtkUnstructuredGrid> _unstructuredGrid;
    vtkSmartPointer<vtkXMLUnstructuredGridWriter> _writer;
    
protected:
    void createPoints();
    void createCells();
    void createCellCenterData();
    void createNodalData();
    void createGrid();
    void writeFile();
    void fileCreation();
    string getIndividualFileName();

public:
    c_VTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, int varSize, float **varMatrix);
    ~c_VTK();
    void doAll();

};

//void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix){
//
//    c_VTK *VTK = new c_VTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix);
//    VTK->doAll();
//    delete VTK;
//
//}

#endif
