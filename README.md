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
  <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\begin{align*}\left|&space;\frac{x({\bf{d}}&space;&plus;&space;\Delta{\bf{d}})-x({\bf{d}})}{x({\bf{d}})}\right|&=&space;\left|&space;\frac{\sum_i&space;(d_i&plus;\Delta&space;d_i)-\sum_i(d_i)}{\sum_i(d_i)}\right|=&space;\left|&space;\frac{\sum_i&space;\Delta&space;d_i}{\sum_i&space;d_i}&space;\right|&space;\\&\leq&space;\frac{\sum_i&space;\left|&space;\Delta&space;d_i\right|}{\left|&space;\sum_i&space;d_i\right|}&space;=&space;\frac{\sum_i&space;\left|&space;d_i\right|}{\left|&space;\sum_i&space;d_i\right|}\frac{\sum_i&space;\left|&space;\Delta&space;d_i\right|}{\sum_i&space;\left|&space;d_i\right|}&space;=&space;\kappa_r&space;\frac{\left\|&space;\Delta{\bf{d}}\right\|_1}{\left\|&space;{\bf{d}}\right\|_1}\end{align*}" title="\bg_white \inline \begin{align*}\left| \frac{x({\bf{d}} + \Delta{\bf{d}})-x({\bf{d}})}{x({\bf{d}})}\right|&= \left| \frac{\sum_i (d_i+\Delta d_i)-\sum_i(d_i)}{\sum_i(d_i)}\right|= \left| \frac{\sum_i \Delta d_i}{\sum_i d_i} \right| \\&\leq \frac{\sum_i \left| \Delta d_i\right|}{\left| \sum_i d_i\right|} = \frac{\sum_i \left| d_i\right|}{\left| \sum_i d_i\right|}\frac{\sum_i \left| \Delta d_i\right|}{\sum_i \left| d_i\right|} = \kappa_r \frac{\left\| \Delta{\bf{d}}\right\|_1}{\left\| {\bf{d}}\right\|_1}\end{align*}" />.
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
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left|&space;\hat{x}&space;-&space;x\right|/\left|&space;x\right|" title="\bg_white \inline \left| \hat{x} - x\right|/\left| x\right|" />.
We call the former _absolute forward error_ and the latter _relative forward error_. We derive upper bounds for each.
 
 In fact, we show that all three algorithms are backwards stable. That is, the errors are no greater than
 
 <p align="center">
 <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\left|&space;\hat{x}&space;-&space;x\right|&space;\leq&space;\kappa_a&space;p(n)u&space;\qquad&space;\text{and}&space;\qquad&space;\left|&space;\frac{\hat{x}-x}{x}\right|&space;\leq&space;\kappa_r&space;p(n)u," title="\bg_white \inline \left| \hat{x} - x\right| \leq \kappa_a p(n)u \qquad \text{and} \qquad \left| \frac{\hat{x}-x}{x}\right| \leq \kappa_r p(n)u," />
  </p>
 
for some <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;p(n)" title="\bg_white \inline p(n)" />, and for each approximate solution <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\hat{x}" title="\bg_white \inline \hat{x}" />, there exists a vector <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\Delta{\bf{d}}" title="\bg_white \inline \Delta{\bf{d}}" /> (small relative to <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\bf{d}" title="\bg_white \inline \bf{d}" />) that satisfies <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;F(\hat{x},{\bf{d}}&plus;\Delta{\bf{d}})&space;=&space;0" title="\bg_white \inline F(\hat{x},{\bf{d}}+\Delta{\bf{d}}) = 0" />. Here, <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;u&space;=&space;2^{-24}" title="\bg_white \inline u = 2^{-24}" /> denotes _unit round off_.

## Algorithm 1
It has been shown [[2]](#2) that if
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\xi&space;=&space;(\xi_1,\dots,\xi_n)^T" title="\bg_white \inline \xi = (\xi_1,\dots,\xi_n)^T" />
is a vector of floating point numbers, then the errors have the approximate bounds

<p align="center">
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\begin{align*}\left|&space;\hat{x}_1(\xi)&space;-&space;x(\xi)\right|&space;&\leq&space;\kappa_a&space;n&space;u&space;\\\left|&space;\frac{\hat{x}_1(\xi)&space;-&space;x(\xi)}{x(\xi)}\right|&space;&\leq&space;\kappa_r&space;nu.\end{align*}&space;" title="\bg_white \begin{align*}\left| \hat{x}_1(\xi) - x(\xi)\right| &\leq \kappa_a n u \\\left| \frac{\hat{x}_1(\xi) - x(\xi)}{x(\xi)}\right| &\leq \kappa_r nu\end{align*} " />
</p>

If instead we require the data
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;{\bf{d}}&space;=&space;(d_1,\dots,d_n)^T" title="\bg_white \inline {\bf{d}} = (d_1,\dots,d_n)^T" />
to be real valued, then this does not change the bounds (provided that they are within range, i.e. not too large). Indeed for each
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;d&space;\in&space;\mathbb{R}" title="\bg_white \inline d \in \mathbb{R}" />
(within range), there exists
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\xi&space;\in&space;\mathcal{F}(\beta,t,L,U)" title="\bg_white \inline \xi \in \mathcal{F}(\beta,t,L,U)" />
and
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\delta&space;\in&space;(-u,u)" title="\bg_white \inline \delta \in (-u,u)" />
for which
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;d&space;=&space;\xi(1&plus;\delta)." title="\bg_white \inline d = \xi(1+\delta)." />.
Thus substitution of
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\bf{d}" title="\bg_white \inline \bf{d}" />
into
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\xi" title="\bg_white \inline \xi" />
does not change the order of
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;p(n)\in\mathcal{O}(n)." title="\bg_white \inline p(n)\in\mathcal{O}(n)." />

To show that
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\hat{x}_1({\bf{d}})" title="\bg_white \inline \hat{x}_1({\bf{d}})" />
is backwards stable, recall [[4]](#4) that we may express
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\hat{x}_1({\bf{d}})" title="\bg_white \inline \hat{x}_1({\bf{d}})" />
in the form

<p align="center">
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\hat{x}_1({\bf{d}})&space;=&space;\sum_{i=1}^n&space;d_i&space;(1&plus;\eta_i)," title="\bg_white \hat{x}_1({\bf{d}}) = \sum_{i=1}^n d_i (1+\eta_i)" />
</p>

where
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left|&space;\eta_i\right|&space;\leq&space;nu" title="\bg_white \inline \left| \eta_i\right| \leq nu" />.
Hence,
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\hat{x}_1({\bf{d}})" title="\bg_white \inline \hat{x}_1({\bf{d}})" />
actually solves the problem with data

<p align="center">
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;{\bf{d}}&space;&plus;&space;\Delta{\bf{d}}&space;=&space;\left(d_1(1&plus;\eta_1),\dots,d_n(1&plus;\eta_n)&space;\right)^T." title="\bg_white {\bf{d}} + \Delta{\bf{d}} = \left(d_1(1+\eta_1),\dots,d_n(1+\eta_n) \right)^T." />
</p>

Our backward error (using the
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;L_1" title="\bg_white \inline L_1" />
norm) is

<p align="center">
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\left\|&space;\Delta{\bf{d}}\right\|_1&space;=&space;\left\|&space;\left&space;(&space;d_1\eta_1,\dots,d_n\eta_n&space;\right&space;)^T\right\|_1&space;=&space;\sum_{i=1}^{n}\left|d_i\eta_i&space;\right|&space;\leq&space;\left\|{\bf{d}}&space;\right\|_1&space;\left\|&space;\eta&space;\right\|_1" title="\bg_white \left\| \Delta{\bf{d}}\right\|_1 = \left\| \left ( d_1\eta_1,\dots,d_n\eta_n \right )^T\right\|_1 = \sum_{i=1}^{n}\left|d_i\eta_i \right| \leq \left\|{\bf{d}} \right\|_1 \left\| \eta \right\|_1" />
  </p>
  
which is small relative to
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\left\|{\bf{d}}&space;\right\|_1" title="\bg_white \inline \left\|{\bf{d}} \right\|_1" />
because each
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;\eta_i" title="\bg_white \inline \eta_i" />
is small.

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
