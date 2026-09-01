import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('output.csv', header=0, names=['x', 'y', 'z'], skiprows=1)

plt.figure(figsize=(10, 6))
plt.plot(data['x'], data['y'], label='y vs x', color='blue')
plt.plot(data['x'], data['z'], label='z vs x', color='orange')
plt.title('Water Wheel Problem Simulation Results')
plt.xlabel('x')
plt.ylabel('y and z')
plt.legend()
plt.grid()
plt.savefig('simulation_results.png')   