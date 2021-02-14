#include "smooth.h"
#include <igl/edge_lengths.h>
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
  Eigen::SparseMatrix<double>
      cotLaplacian;

  // need to get the edge lengths of the mesh
  Eigen::MatrixXd edgeLengths;
  igl::edge_lengths(V, F, edgeLengths);

  std::cout << "edge lengths: \n"
            << edgeLengths << "\nedge lengths done\n";
  // Heron's Law of sines https://en.wikipedia.org/wiki/Heron's_formula

  U = G;
}
