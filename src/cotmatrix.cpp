#include "cotmatrix.h"


void cotmatrix(
  const Eigen::MatrixXd & l,
  const Eigen::MatrixXi & F,
  Eigen::SparseMatrix<double> & L)
{
  // Inputs
  // l is the edge lengths of the mesh can be called with igl::edgelengths
  // F is faces
  // Output
  // L is sparse, symmetric matrx
}
