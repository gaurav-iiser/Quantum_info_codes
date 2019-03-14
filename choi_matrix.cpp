#include <iostream>
#include "qpp.h"
#include <Eigen/Eigen>
using Eigen::MatrixXd;
using namespace std;
using namespace qpp;

int main()
{

  MatrixXd m(2,2);
  m(0,0) = 1;
  m(1,0) = 1;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

  MatrixXd m2 = kron(m,m);
  cout<<endl<<"final matrix is"<<endl;

  cout<<m2<<endl;

  MatrixXd id = MatrixXd::Identity(2,2);
  cout<<id<<endl;

}

/*
idea/pseudo code: 
to create a choi matrix given a channel E , do the following:
  ********** J_E = (id \tensor_prod E)(\phi_+) ******************

  1. define a tensor product
  2. define a matrix id(identity of dimension 'd')
  3. define \phi_+
  4. take input E as:
      a. Kraus operators
      b. operation on any given density matrix.
      c. operation on any given complex matrix.
      *d. choose among unitaries, projection, partial/full trace, and transpose sequentially to tell the computer the operation/channel <- but we will write the function first
                                                                                                                                           and later ask the user
  5. whatever J_E is formed, check for its positivity.
      a. If J_E >= 0
      b. else print," given E is not a quantum channel, i.e. it is not CPTP a map"

*/
