#include "smooth.h"
#include <igl/edge_lengths.h>
#include <cotmatrix.h>
#include <iostream>

void smooth(
    const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &G,
    double lambda,
    Eigen::MatrixXd &U)
{
  // Replace with your code
  // call to generate the cotangenent Laplacian

  Eigen::SparseMatrix<double> cotLaplacian;

  // need to get the edge lengths of the mesh
  Eigen::MatrixXd edgeLengths;
  igl::edge_lengths(V, F, edgeLengths);

  cotmatrix(edgeLengths, F, cotLaplacian);

  std::cout << cotLaplacian << std::endl;

  U = G;
}
