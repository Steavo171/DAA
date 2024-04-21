import matplotlib.pyplot as plt
import numpy as np

arr = np.array([500,1000,1500,2000,2500,3000])

insertion = np.array([0.001,0.008,0.014,0.02,0.029,0.029])
# insertion = np.array([0,0,0.003,0.002,0.014,0.016])
merge = np.array([0,0,0.004,0.006,0.006,0.008])
# merge = np.array([0,0,0.001,0,0,0])

plt.plot(arr, insertion, label='Insertion Sort')
plt.plot(arr, merge, label='Merge Sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Insertion Sort vs Merge Sort')

plt.show()