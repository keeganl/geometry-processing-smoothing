#include "cotmatrix.h"
#include "helperMathFunctions.h"
#include "helperClasses.h"
#include <igl/adjacency_list.h>
#include <iostream>
#include <fstream>
#include <vector>

void cotmatrix(
    const Eigen::MatrixXd &l,
    const Eigen::MatrixXi &F,
    Eigen::SparseMatrix<double> &L)
{
  // Inputs
  // l is the edge lengths of the mesh can be called with igl::edgelengths
  //   for triangles, columns correspond to edges [1,2],[2,0],[0,1]
  // F is faces
  // Output
  // L is sparse, symmetric matrix

  Eigen::SparseMatrix<double> laplacian(F.rows(), F.cols());

  // containing at row i the adjacent vertices of vertex i
  std::vector<std::vector<int> > adjList;
  igl::adjacency_list(F, adjList, true);

  for (int i = 0; i < adjList.size(); i++)
  {
    // i is the vertex
    for (int j = 0; j < adjList[i].size(); j++)
    {
      laplacian.coeffRef(i, j) += cot(l.row(i)[0], l.row(i)[1], l.row(i)[2]);
      laplacian.coeffRef(j, i) += cot(l.row(i)[0], l.row(i)[1], l.row(i)[2]);
      laplacian.coeffRef(i, i) -= cot(l.row(i)[0], l.row(i)[1], l.row(i)[2]);
      laplacian.coeffRef(j, j) -= cot(l.row(i)[0], l.row(i)[1], l.row(i)[2]);
    }
  }

  std::ofstream MyFile("test.txt");
  MyFile << laplacian;
  MyFile.close();

  L = laplacian;
}
