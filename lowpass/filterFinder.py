import numpy as np
from scipy import signal
import math
import matplotlib.pyplot as plt

# Low-pass filter
w0 = 2*np.pi*5; # pole frequency (rad/s)
num = w0        # transfer function numerator coefficients
den = [1,w0]    # transfer function denominator coefficients
lowPass = signal.TransferFunction(num,den) # Transfer function
samplingFreq = float(input("SamplingFreq"))
dt = 1.0/samplingFreq;
discreteLowPass = lowPass.to_discrete(dt,method='gbt',alpha=0.5)
print(discreteLowPass)
print("the filter equation is: ")
print(f"yFiltered =\n{-discreteLowPass.den[1]} * lastFiltered +\n{discreteLowPass.num[0]} * yInput +\n{discreteLowPass.num[1]} * lastInput")