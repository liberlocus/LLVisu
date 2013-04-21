#ifndef LIBERVISUXMF_H
#define LIBERVISUXMF_H

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#include <liberVisuHDF.h>

using namespace std;

class c_XMF{
/*! Class definition for serial XMF format**/

protected:
    string _fileName; /*! absolute path to filename */
    string _gridName; /*! grid name decribed in XDMF documentation */
    string _gridType; /*! grid type decribed in XDMF documentation */
    string _topoType; /*! topology type decribed in XDMF documentation */

    int _nodeNum;     /*! number of nodes in the mesh */ 
    int _cellNum;     /*! number of cells in the mesh */
    int _nodePerCell; /*! number of nodes per cell in the mesh */
    int _varSize;
    char **_varName, **_temp_varName;
    char **_varType, **_temp_varType;// = NULL;
    int *_varLength, *_temp_varLength;
    float *_x;        /*! pointer to the array that holds the x position of the nodes */
    float *_y;        /*! pointer to the array that holds the y position of the nodes */
    float *_z;        /*! pointer to the array that holds the z position of the nodes */
    int **_cellConnectivity;
    float **_varMatrix;
//  Related to HDF
    c_HDF *HDF;       /*! pointer to HDF object */
    
protected:

    void writeXMF();

public:

    c_XMF(string fileName, string _gridName, string _gridType, string _topoType, int num_nodes, float *x, float *y, float *z, int num_cells, int node_per_cell, int **cellConnectivity, char ** varName, char **varType, int *varLength, int varSize, float **varMatrix);
    ~c_XMF();

    void doAll(); //filecreation

};

#endif
