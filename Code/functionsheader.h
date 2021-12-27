#pragma once

double invfactorial(int n);		// computes 1/n!
double kabs(double XI[], int n);	// absolute conditioning number
double krel(double XI[], int n);	// relative conditioning number
double exact(double XI[], int n);	// computes exact sum
float alg1(float XI_SP[], int n);	// single precision accumulation
float alg2(float XI_SP[], int n);	// binary fan-in sum
float alg3(float XI_SP[], int n);	// double precision accumulation
