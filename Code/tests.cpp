#include <iostream>
#include <cmath>
#include <fstream>
#include "functionsheader.h"
using namespace std;

void test1() {		// sum of 1/n! to e
  double e = exp(1);	// fd
  int n = 15;

  double XI_DP[n];	// declare "exact" summands
  float XI_SP[n];	// declare "floating point" summands

  for (int i = 0; i < n; i++){
    XI_DP[i] = invfactorial(i);
    XI_SP[i] = static_cast<float>(XI_DP[i]);
  }

  double err1[n-1];	// declare relative errors
  double err2[n-1];
  double err3[n-1];

  for (int k = 2; k < n + 1; k++){
    float XI[k];
    for (int j = 0; j < k; j++){
      XI[j] = XI_SP[k-1-j];
    }
    err1[k-2] = abs(alg1(XI,k)-e)/e;
    err2[k-2] = abs(alg2(XI,k)-e)/e;
    err3[k-2] = abs(alg3(XI,k)-e)/e;
  }

  fstream file;		// output in binary format to avoid loss of precision

  file.open("Results/test1err1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err1), sizeof(err1));
  file.close();

  file.open("Results/test1err2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err2), sizeof(err2));
  file.close();

  file.open("Results/test1err3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err3), sizeof(err3));
  file.close();
}

void test2(){		// sum of (-1)^n / (2n - 1)! to sin(1)
  double fd = sin(1);	// similar to test 1
  int n = 10;

  double XI_DP[n];
  float XI_SP[n];

  for (int i = 0; i < n; i++){
    XI_DP[i] = pow(-1,i)*invfactorial(2*i+1);
    XI_SP[i] = static_cast<float>(XI_DP[i]);
  }

  double err1[n-1];
  double err2[n-1];
  double err3[n-1];

  for (int k = 2; k < n + 1; k++){
    float XI[k];
    for (int j = 0; j < k; j++){
      XI[j] = XI_SP[k-1-j];
    }
    err1[k-2] = abs(alg1(XI,k)-fd)/fd;
    err2[k-2] = abs(alg2(XI,k)-fd)/fd;
    err3[k-2] = abs(alg3(XI,k)-fd)/fd;
  }

  fstream file;

  file.open("Results/test2err1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err1), sizeof(err1));
  file.close();

  file.open("Results/test2err2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err2), sizeof(err2));
  file.close();

  file.open("Results/test2err3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err3), sizeof(err3));
  file.close();
}

void test3(){		// sum of n to n(n+1)/2
  double fd = 5050;	// exact solution known and exactly representable
  int n = 100;
  double XI_DP[n];
  for (int i = 0; i < n; i++){
    XI_DP[i] = i + 1;
  }
  double M;
  double XI[n];
  double err[11];
  double u;

  for (int k = -5; k < 6; k++){
    M = pow(2,k);
    srand(0);
    for (int i = 0; i < n; i++){
      u = 2*((double) rand()/RAND_MAX) - 1;	// generate random numbers
      XI[i] = M*u + XI_DP[i];			// perturb data
    }
    err[k+5] = abs(exact(XI,n)-fd)/fd;		// using "exact" sum
  }

  fstream file;
  file.open("Results/test3err.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err), sizeof(err));
  file.close();
}

void test4(){				// sum of 1/2^n to 2^(6) - 2^(-5)
  double fd = pow(2,6) - pow(2,-5);	// similar to test 3
  int n = 11;
  double XI_DP[n];
  for (int i = 0; i < n; i++){
    XI_DP[i] = pow(2,i-5);
  }
  double M;
  double XI[n];
  double err[11];
  double u;

  for (int k = -5; k < 6; k++){
    M = pow(2,k);
    srand(0);
    for (int i = 0; i < n; i++){
      u = 2*((double) rand()/RAND_MAX) - 1;
      XI[i] = M*u + XI_DP[i];
    }
    err[k+5] = abs(exact(XI,n)-fd)/fd;
  }

  fstream file;
  file.open("Results/test4err.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err), sizeof(err));
  file.close();
}

void test5(){		// sum of i sin((i/2 + 1/i)pi )
  int p = 15;		// summing from 2^1 to 2^15
  int n = pow(2,p);
  double XI_DP[n];
  float XI_SP[n];
  double ij;
  for (int i = 0; i < n; i++){
    double ij = i + 1;
    XI_DP[i] = ij*sin((ij/2 + 1/ij)*M_PI);
    XI_SP[i] = static_cast<float>(XI_DP[i]);
  }
  double err1[p];
  double err2[p];
  double err3[p];

  double ub1[p];
  double ub2[p];
  double ub3[p];

  double fd;
  int m;
  for (int j = 1; j <= p; j++){
    m = pow(2,j);
    fd = exact(XI_DP,m);
    err1[j-1] = abs((alg1(XI_SP,m) - fd)/fd);
    err2[j-1] = abs((alg2(XI_SP,m) - fd)/fd);
    err3[j-1] = abs((alg3(XI_SP,m) - fd)/fd);

    ub1[j-1] = krel(XI_DP,m)*m*pow(2,-24);
    ub2[j-1] = krel(XI_DP,m)*(j+1)*pow(2,-24);
    ub3[j-1] = krel(XI_DP,m)*2*pow(2,-24);
  }

  fstream file;
  file.open("Results/test5err1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err1), sizeof(err1));
  file.close();

  file.open("Results/test5err2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err2), sizeof(err2));
  file.close();

  file.open("Results/test5err3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err3), sizeof(err3));
  file.close();

  file.open("Results/test5ub1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub1), sizeof(ub1));
  file.close();

  file.open("Results/test5ub2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub2), sizeof(ub2));
  file.close();

  file.open("Results/test5ub3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub3), sizeof(ub3));
  file.close();
}

void test6(){		// sum of i sin(i/2 + 1/i)
  int p = 15;
  int n = pow(2,p);
  double XI_DP[n];
  float XI_SP[n];
  double ij;
  for (int i = 0; i < n; i++){
    double ij = i + 1;
    XI_DP[i] = ij*sin((ij/2 + 1/ij));
    XI_SP[i] = static_cast<float>(XI_DP[i]);
  }
  double err1[p];
  double err2[p];
  double err3[p];

  double ub1[p];
  double ub2[p];
  double ub3[p];

  double fd;
  int m;
  for (int j = 1; j <= p; j++){
    m = pow(2,j);
    fd = exact(XI_DP,m);
    err1[j-1] = abs((alg1(XI_SP,m) - fd)/fd);
    err2[j-1] = abs((alg2(XI_SP,m) - fd)/fd);
    err3[j-1] = abs((alg3(XI_SP,m) - fd)/fd);

    ub1[j-1] = krel(XI_DP,m)*m*pow(2,-24);
    ub2[j-1] = krel(XI_DP,m)*(j+1)*pow(2,-24);
    ub3[j-1] = krel(XI_DP,m)*2*pow(2,-24);
  }

  fstream file;
  file.open("Results/test6err1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err1), sizeof(err1));
  file.close();

  file.open("Results/test6err2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err2), sizeof(err2));
  file.close();

  file.open("Results/test6err3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(err3), sizeof(err3));
  file.close();

  file.open("Results/test6ub1.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub1), sizeof(ub1));
  file.close();

  file.open("Results/test6ub2.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub2), sizeof(ub2));
  file.close();

  file.open("Results/test6ub3.dat", ios::out | ios::binary);
  file.write(reinterpret_cast<char *>(ub3), sizeof(ub3));
  file.close();
}