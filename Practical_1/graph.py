import matplotlib.pyplot as plt
import numpy as np

#bubble_sort
num_a = np.array([500,1000,1500,2000,2500,3000])
tc_a = np.array([0.016,0.014,0.027,0.049,0.037,0.061])

#selection_sort
num_b = np.array([500,1000,1500,2000,2500,3000])
tc_b = np.array([0,0,0.016,0.028,0.014,0.027])

plt.plot(num_a, tc_a, label='Bubble sort')
plt.plot(num_b, tc_b, label='Selection sort')
plt.xlabel('Size of array')
plt.ylabel('Time Complexity')
plt.legend()
plt.title('Bubble Sort vs Selection Sort')

plt.show()