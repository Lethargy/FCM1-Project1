import numpy as np
import matplotlib.pyplot as plt

# --------------------------------------- Test 1 --------------------------------------- 
t1err1 = np.fromfile('Results/test1err1.dat',dtype='float64')
t1err2 = np.fromfile('Results/test1err2.dat',dtype='float64')
t1err3 = np.fromfile('Results/test1err3.dat',dtype='float64')
t1n = 2 + np.arange(14)
t1b = [1/(np.math.factorial(j)) for j in t1n]

fig, ax = plt.subplots(3,1,sharex=True, figsize=(6,9), dpi = 250)
ax[0].plot(t1n,t1err1,'--o',label=r'$e_{\mathrm{rel}}$')
ax[0].plot(t1n,t1b,'--o',label=r'$\frac{1}{n!}$')
ax[0].set_yscale('log')
ax[0].set_ylabel('Algorithm 1')
ax[0].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[0].legend()

ax[1].plot(t1n,t1err2,'--o',label=r'$e_{\mathrm{rel}}$')
ax[1].plot(t1n,t1b,'--o',label=r'$\frac{1}{n!}$')
ax[1].set_yscale('log')
ax[1].set_ylabel('Algorithm 2')
ax[1].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[1].legend()

ax[2].plot(t1n,t1err3,'--o',label=r'$e_{\mathrm{rel}}$')
ax[2].plot(t1n,t1b,'--o',label=r'$\frac{1}{n!}$')
ax[2].set_yscale('log')
ax[2].set_ylabel('Algorithm 3')
ax[2].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[2].set_xlabel(r'$n$')
ax[2].legend();

fig.savefig('../Programming Solutions Document/test1.jpeg',bbox_inches='tight')

# --------------------------------------- Test 2 --------------------------------------- 
t2err1 = np.fromfile('Results/test2err1.dat',dtype='float64')
t2err2 = np.fromfile('Results/test2err2.dat',dtype='float64')
t2err3 = np.fromfile('Results/test2err3.dat',dtype='float64')
t2n = 2 + np.arange(len(t2err1))
t2b = [1/(np.math.factorial((2*j))) for j in t2n]

fig, ax = plt.subplots(3,1,sharex=True, figsize=(6,9), dpi = 250)
ax[0].plot(t2n,t2err1,'--o',label=r'$e_{\mathrm{rel}}$')
ax[0].plot(t2n,t2b,'--o',label=r'$\frac{1}{2n!}$')
ax[0].set_yscale('log')
ax[0].set_ylabel('Algorithm 1')
ax[0].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[0].legend()

ax[1].plot(t2n,t2err2,'--o',label=r'$e_{\mathrm{rel}}$')
ax[1].plot(t2n,t2b,'--o',label=r'$\frac{1}{2n!}$')
ax[1].set_yscale('log')
ax[1].set_ylabel('Algorithm 2')
ax[1].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[1].legend()

ax[2].plot(t2n,t2err3,'--o',label=r'$e_{\mathrm{rel}}$')
ax[2].plot(t2n,t2b,'--o',label=r'$\frac{1}{2n!}$')
ax[2].set_yscale('log')
ax[2].set_ylabel('Algorithm 3')
ax[2].axhline(y=pow(2,-24),ls='--',c='gray',label=r'$u$')
ax[2].set_xlabel(r'$n$')
ax[2].legend();

fig.savefig('../Programming Solutions Document/test2.jpeg',bbox_inches='tight')

# --------------------------------------- Test 3 --------------------------------------- 
t3err = np.fromfile('Results/test3err.dat',dtype='float64')
t3n = -5 + np.arange(len(t3err))
t3ub = 100*2.0**t3n/5050

fig, ax = plt.subplots(1,1,sharex=True, figsize=(5,3.5), dpi = 250)
ax.plot(t3n,t3err,'--o',label=r'$e_{\mathrm{rel}}$')
ax.plot(t3n,t3ub,'--o',label=r'$\kappa_{\mathrm{rel}}\frac{2^p}{|d|}$')
ax.set_yscale('log')
ax.set_xlabel(r'$p$')
ax.legend()
fig.tight_layout();

fig.savefig('../Programming Solutions Document/test3.jpeg', transparent = False)

# --------------------------------------- Test 4 --------------------------------------- 
t4err = np.fromfile('Results/test4err.dat',dtype='float64')
t4n = -5 + np.arange(len(t4err))
t4ub = 11*2.0**np.arange(-5,6)/(2**6 - 2.0**(-5))

fig, ax = plt.subplots(1,1,sharex=True, figsize=(5,3.5), dpi = 250)
ax.plot(t4n,t4err,'--o',label=r'$e_{\mathrm{rel}}$')
ax.plot(t4n,t4ub,'--o',label=r'$\kappa_{\mathrm{rel}}\frac{2^p}{|d|}$')
ax.set_yscale('log')
ax.set_xlabel(r'$p$')
ax.legend()
fig.tight_layout();

fig.savefig('../Programming Solutions Document/test4.jpeg',transparent = False)

# --------------------------------------- Test 5 --------------------------------------- 
t5err1 = np.fromfile('Results/test5err1.dat',dtype='float64')
t5err2 = np.fromfile('Results/test5err2.dat',dtype='float64')
t5err3 = np.fromfile('Results/test5err3.dat',dtype='float64')
t5ub1 = np.fromfile('Results/test5ub1.dat',dtype='float64')
t5ub2 = np.fromfile('Results/test5ub2.dat',dtype='float64')
t5ub3 = np.fromfile('Results/test5ub3.dat',dtype='float64')
t5n = 2.0**np.arange(1,16)

fig, ax = plt.subplots(1,3,sharey=True, figsize=(7,3.5), dpi = 250)
i1 = t5err1 != 0
ax[0].loglog(t5n[i1],t5err1[i1],'--o',label=r'$e_{\mathrm{rel}}$')
ax[0].loglog(t5n[i1],t5ub1[i1],'--o',label=r'$\kappa_{\mathrm{rel}}nu$')
ax[0].set_title('Algorithm 1')
ax[0].set_xlabel(r'$n$')
ax[0].legend()

i2 = t5err2 != 0
ax[1].loglog(t5n[i2],t5err2[i2],'--o',label=r'$e_{\mathrm{rel}}$')
ax[1].loglog(t5n[i2],t5ub2[i2],'--o',label=r'$\kappa_{\mathrm{rel}}(1+\log_2n)u$')
ax[1].set_title('Algorithm 2')
ax[1].set_xlabel(r'$n$')
ax[1].legend()

i3 = t5err3 != 0
ax[2].loglog(t5n[i3],t5err3[i3],'--o',label=r'$e_{\mathrm{rel}}$')
ax[2].loglog(t5n[i3],t5ub3[i3],'--o',label=r'$2\kappa_{\mathrm{rel}}u$')
ax[2].set_title('Algorithm 3')
ax[2].set_xlabel(r'$n$')
ax[2].legend()
fig.tight_layout();

fig.savefig('../Programming Solutions Document/test5.jpeg')

# --------------------------------------- Test 6 --------------------------------------- 
t6err1 = np.fromfile('Results/test6err1.dat',dtype='float64')
t6err2 = np.fromfile('Results/test6err2.dat',dtype='float64')
t6err3 = np.fromfile('Results/test6err3.dat',dtype='float64')
t6ub1 = np.fromfile('Results/test6ub1.dat',dtype='float64')
t6ub2 = np.fromfile('Results/test6ub2.dat',dtype='float64')
t6ub3 = np.fromfile('Results/test6ub3.dat',dtype='float64')
t6n = 2.0**np.arange(1,16)

fig, ax = plt.subplots(1,3,sharey=True, figsize=(7,3.5), dpi = 250)
i1 = t6err1 != 0
ax[0].loglog(t6n[i1],t6err1[i1],'--o',label=r'$e_{\mathrm{rel}}$')
ax[0].loglog(t6n[i1],t6ub1[i1],'--o',label=r'$\kappa_{\mathrm{rel}}nu$')
ax[0].set_title('Algorithm 1')
ax[0].set_xlabel(r'$n$')
ax[0].legend()

i2 = t6err2 != 0
ax[1].loglog(t6n[i2],t6err2[i2],'--o',label=r'$e_{\mathrm{rel}}$')
ax[1].loglog(t6n[i2],t6ub2[i2],'--o',label=r'$\kappa_{\mathrm{rel}}(1+\log_2n)u$')
ax[1].set_title('Algorithm 2')
ax[1].set_xlabel(r'$n$')
ax[1].legend()

i3 = t6err3 != 0
ax[2].loglog(t6n[i3],t6err3[i3],'--o',label=r'$e_{\mathrm{rel}}$')
ax[2].loglog(t6n[i3],t6ub3[i3],'--o',label=r'$2\kappa_{\mathrm{rel}}u$')
ax[2].set_title('Algorithm 3')
ax[2].set_xlabel(r'$n$')
ax[2].legend()
fig.tight_layout();

fig.savefig('../Programming Solutions Document/test6.jpeg')

