import matplotlib.pyplot as plt
import numpy as np

arr = np.array([5000,10000,15000,20000,25000,30000])

quick = np.array([0,0.005,0,0.007,0.009,0.016])
heap = np.array([0.002,0.008,0.016,0.023,0.021,0.031])

plt.plot(arr, quick, label='Quick Sort')
plt.plot(arr, heap, label='Heap Sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Quick Sort vs Heap Sort')

plt.show()