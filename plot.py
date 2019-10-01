import matplotlib.pyplot as plt
import numpy as np

#Function for plotting the given function and shading the area under the curve and above the x-axis
def plt_graph(dat,n,xlab,ylab):
    I = np.zeros((2,n))
    I = np.loadtxt(dat,dtype='double')
    plt.plot(I[0,:],I[1,:])#plotting the curve
    plt.fill_between(I[0,:],I[1,:],y2=0,alpha = 0.8)#shading the area under the curve
    
    plt.grid()
    plt.axis('square')
    plt.xlim(-0.3,3.3)
    plt.ylim(-0.3,3.3)
    plt.xlabel(xlab)
    plt.ylabel(ylab)
    plt.show()
    
len = np.loadtxt('data/len.dat',dtype='int')

#plotting the given integrands
plt_graph('data/I1.dat',len,r'$\theta$',r'$f_1(\theta)$')
plt_graph('data/I2.dat',len,r'$\theta$',r'$f_2(\theta)$')
plt_graph('data/I3.dat',len,r'$\theta$',r'$f_3(\theta)$')
plt_graph('data/I4.dat',len,r'$\theta$',r'$f_4(\theta)$')
plt_graph('data/I5.dat',len,r'$\theta$',r'$f_5(\theta)$')
plt_graph('data/I6.dat',len,'t','$f_6(t)$')