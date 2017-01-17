from random import choice
import numpy as np
import subprocess

def getPerturbationVector(n):
  if n <= 0:
    return false
  return np.array([choice([-1.0, 1.0]) for i in range(n)])

#theta 1 is new theta, theta 2 is old theta in all cases
def lossFunction(theta1, theta2, player):
  with open("params.txt", "wt") as optfile:
    optfile.write(i) for i in theta1
    optfile.write("\n")
    optfile.write(i) for i in theta2
  with open("success.txt", "wt") as outfile:
    subprocess.call(["shogi", "--optfile=params.txt", "--silent"], stdout=outfile)
    #do 
  success = 1 #1 for first player victory, -1 for second player
  if (success == 1 and player == 1) or (success == -1 and player == 2):
    return -1
  else:
    return 1

#theta is np.array type
def spsa(self, theta, n, a, c, A, alpha, gamma, player):
    delta = getPerturbationVector(n)
    for k in range(n):
      lMinus = lossFunction(theta - (delta * c), theta, player)
      lPlus = lossFunction(theta + (delta * c), theta, player)
      grad = ((lPlus - lMinus)/2*c) * delta
      theta = theta - a*grad
      c = c/(k**gamma)
      a = a/(A + k)**A
    
    
    

  
  