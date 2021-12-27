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
We pose the problem in the following way: find <img src="https://render.githubusercontent.com/render/math?math=x \in \mathbb{R}"> that satisfies

<img src="https://latex.codecogs.com/svg.image?\bg_white&space;F(x,{\bf{d}})=(d_1&plus;d_2&plus;\cdots&plus;d_n)-x=0" title="\bg_white F(x,{\bf{d}})=(d_1+d_2+\cdots+d_n)-x=0" />

given fixed <img src="https://latex.codecogs.com/svg.latex?{\bf{d}}=(d_1,\cdots,d_n)^T\in\mathbb{R}^n" /> [[6]](#6). Under the constraint
<img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;F(x,{\bf{d}})=0" title="\bg_white \inline F(x,{\bf{d}})=0" />,
we may view <img src="https://latex.codecogs.com/svg.image?\bg_white&space;\inline&space;x" title="\bg_white \inline x" />
as a function of
<img src="https://latex.codecogs.com/svg.image?\inline&space;{\bf{d}}" title="\inline {\bf{d}}" />.

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
