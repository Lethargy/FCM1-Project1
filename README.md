# FCM1 Project1
Project 1 for Foundations of Computational Mathematics I at Florida State University.

# Summary
We compare three addition algorithms and demonstrate their theoretical error bounds. Using various sums, we verify that these sums are correct, and that they are stable, as assured by the mathematics. We also verify that addition is a well conditioned problem.

# Problem Statement
We numerically verify (1) the conditioning upper bound on addition problems, and (2) the stability of three addition algorithms. The three algorithms in question are the recursive cumulative sum in single precision IEEE arithmetic, the binary fan-in tree, and the cumulative sum again in double precision (algorithms 1, 2, and 3 hereafter).  Before the stability analysis, we show that the three algorithms produce correct results (as correct as they can be, given their limitations). The shortcomings of
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\mathcal{F}(\beta,t,L,U)" title="\bg_white \inline \mathcal{F}(\beta,t,L,U)" />
relative to
<img src="https://latex.codecogs.com/svg.latex?\mathbb{R}">
are reproduced analogously using the shortcomings of single precision floats relative to double precision floats.

# Mathematics
We pose the problem in the following way: find
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x&space;\in&space;\mathbb{R}" title="\bg_white \inline x \in \mathbb{R}" />
that satisfies

<p align="center">
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;F(x,{\bf{d}})=(d_1&plus;d_2&plus;\cdots&plus;d_n)-x=0" title="\bg_white F(x,{\bf{d}})=(d_1+d_2+\cdots+d_n)-x=0" />
</p>

given fixed <img src="https://latex.codecogs.com/svg.latex?{\bf{d}}=(d_1,\cdots,d_n)^T\in\mathbb{R}^n" /> [[6]](#6). Under the constraint
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;F(x,{\bf{d}})=0" title="\bg_white \inline F(x,{\bf{d}})=0" />,
we may view <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x" title="\bg_white \inline x" />
as a function of
<img src="https://latex.codecogs.com/svg.image?\inline&space;{\bf{d}}" title="\inline {\bf{d}}" />.
This
<img src="https://latex.codecogs.com/svg.image?\inline&space;x({\bf{d}})" title="\inline x({\bf{d}})" />
is well conditioned because

<p align="center">
  <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\begin{align*}\left|&space;\frac{x({\bf{d}}&space;&plus;&space;\Delta{\bf{d}})-x({\bf{d}})}{x({\bf{d}})}\right|&=&space;\left|&space;\frac{\sum_i&space;(d_i&plus;\Delta&space;d_i)-\sum_i(d_i)}{\sum_i(d_i)}\right|=&space;\left|&space;\frac{\sum_i&space;\Delta&space;d_i}{\sum_i&space;d_i}&space;\right|&space;\\&\leq&space;\frac{\sum_i&space;\left|&space;\Delta&space;d_i\right|}{\left|&space;\sum_i&space;d_i\right|}&space;=&space;\frac{\sum_i&space;\left|&space;d_i\right|}{\left|&space;\sum_i&space;d_i\right|}\frac{\sum_i&space;\left|&space;\Delta&space;d_i\right|}{\sum_i&space;\left|&space;d_i\right|}&space;=&space;\kappa_r&space;\frac{\left\|&space;\Delta{\bf{d}}\right\|_1}{\left\|&space;{\bf{d}}\right\|_1}\end{align*}" title="\bg_white \inline \begin{align*}\left| \frac{x({\bf{d}} + \Delta{\bf{d}})-x({\bf{d}})}{x({\bf{d}})}\right|&= \left| \frac{\sum_i (d_i+\Delta d_i)-\sum_i(d_i)}{\sum_i(d_i)}\right|= \left| \frac{\sum_i \Delta d_i}{\sum_i d_i} \right| \\&\leq \frac{\sum_i \left| \Delta d_i\right|}{\left| \sum_i d_i\right|} = \frac{\sum_i \left| d_i\right|}{\left| \sum_i d_i\right|}\frac{\sum_i \left| \Delta d_i\right|}{\sum_i \left| d_i\right|} = \kappa_r \frac{\left\| \Delta{\bf{d}}\right\|_1}{\left\| {\bf{d}}\right\|_1}\end{align*}" />.
</p>

One may bound the absolute error
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left|&space;x({\bf{d}}&plus;\Delta{\bf{d}})&space;-&space;x({\bf{d}})\right|&space;\leq&space;\kappa_a&space;\left\|&space;\Delta{\bf{d}}\right\|_1" title="\bg_white \inline \left| x({\bf{d}}+\Delta{\bf{d}}) - x({\bf{d}})\right| \leq \kappa_a \left\| \Delta{\bf{d}}\right\|_1" />
in a similar way [[2]](#2). Here,
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\kappa_r&space;=&space;\sum_i&space;\left|&space;d_i\right|&space;/&space;\left|&space;\sum_i&space;d_i\right|" title="\bg_white \inline \kappa_r = \sum_i \left| d_i\right| / \left| \sum_i d_i\right|" /> 
and 
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\kappa_a&space;=&space;\sum_i&space;\left|&space;d_i\right|" title="\bg_white \inline \kappa_a = \sum_i \left| d_i\right|" />
denote the relative and absolute _condition numbers_.

The three algorithms merely approximate 
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x({\bf{d}})" title="\bg_white \inline x({\bf{d}})" />.
In this investigation, we consider two sources of error that prevent us from attaining 
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x({\bf{d}})" title="\bg_white \inline x({\bf{d}})" />
 exactly [[1]](#1):
 
 1. finite precision representation of real numbers. These not only perturb the data <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;d_1,\dots,d_n" title="\bg_white \inline d_1,\dots,d_n" />, but also restrict the range of values that <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x" title="\bg_white \inline x" /> may take.
 2. accumulation of errors due to floating point arithmetic.

If
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\hat{x}" title="\bg_white \inline \hat{x}" />
is an approximation of
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x" title="\bg_white \inline x" />,
then two quantities of interest are 
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left|&space;\hat{x}&space;-&space;x\right|" title="\bg_white \inline \left| \hat{x} - x\right|" />
and
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left|&space;({\hat{x}&space;-&space;x})/{x}\right|" title="\bg_white \inline \left| ({\hat{x} - x})/{x}\right|" />.
 
# References
<a id="1">[1]</a>
Gallivan, K. A. _Set 2: Representation, Conditioning and Error_, Lecture Notes. Foundations of Computational Math I, Florida State University.

<a id="2">[2]</a>
Gallivan, K. A. _Set 3: Finite Precision Arithmetic and Numerical Stability_, Lecture Notes. Foundations of Computational Math I, Florida State University.

<a id="3">[3]</a>
Gallivan, K. A. _Set 4: Numerical Stability Examples_, Lecture Notes. Foundations of Computational Math 1, Florida State University.

<a id="4">[4]</a>
J. D. Hunter, "Matplotlib: A 2D Graphics Environment", Computing in Science & Engineering, vol. 9, no. 3, pp. 90-95, 2007.

<a id="5">[5]</a>
Kincaid, D. & Cheney, W. (2002) _Numerical Analysis: Mathematics of Scientific Computing_. Brooks/Cole.

<a id="6">[6]</a>
Quarteroni, A., Sacco, R., & Saleri, R. (2000). _Numerical Mathematics_. Springer.
