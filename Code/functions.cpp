// computes 1/n!
double invfactorial(int n){ 		// input n
  double out = 1.0;
  while (n > 1){
    out /= n;
    n -= 1;
  }
  return out;
}

// absolute conditioning number
double kabs(double XI[], int n){	// input: summands, size of sum n
  double out = 0;
  for (int i = 0; i < n; i++){
    if (XI[i] > 0)
      out += XI[i];
    else
      out -= XI[i];
  }
  return out;
}

// relative conditioning number
double krel(double XI[], int n){	// input: summands, size of sum n
  double N = kabs(XI,n);		// uses absolute conditioning number
  double D = 0;
  for (int i = 0; i < n; i++){
    D += XI[i];
  }
  if (D < 0)
    {D *= -1;}
  double out = N/D;
  return out;
}

// computes "exact" sum using binary fan in with double precision
double exact(double XI[], int n){	// input: summands, size of sum n
  double DUP[n];
  for (int i = 0; i < n; i++){
    DUP[i] = XI[i];}
  while (n > 1){
    for (int i = 0; i < n/2; i++){
      DUP[i] = DUP[2*i] + DUP[2*i + 1];}
    if( n % 2 == 0)
      { n = n/2;}
    else
      { DUP[n/2] = DUP[n-1];
        n = n/2 + 1;}
  }
  return DUP[0];
}

// single precision accumulation
float alg1(float XI_SP[], int n){	// input: summands, size of sum n
  float S_SP = 0;
  for (int i = 0; i < n; i++){
    S_SP += XI_SP[i];}
  return S_SP;
}


// binary fan-in sum
float alg2(float XI_SP[], int n){	// input: summands, size of sum n
  float DUP[n];
  for (int i = 0; i < n; i++){
    DUP[i] = XI_SP[i];}
  while (n > 1){
    for (int i = 0; i < n/2; i++){
      DUP[i] = DUP[2*i] + DUP[2*i + 1];}
    if( n % 2 == 0)
      { n = n/2;}
    else
      { DUP[n/2] = DUP[n-1];
        n = n/2 + 1;}
  }
  return DUP[0];
}

// double precision accumulation
float alg3(float XI_SP[], int n){	// inputs: summands, size of sum n
  double S_DP = 0;
  for (int i = 0; i < n; i++){
    S_DP += static_cast<double>(XI_SP[i]);
  }
  float S_SP = static_cast<float>(S_DP);
  return S_SP;
}