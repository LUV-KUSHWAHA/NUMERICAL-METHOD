# LEAST SQUARE REGRESSION METHOD
import matplotlib.pyplot as plt

# Step 1: Input number of data points
n = int(input("Enter no. of data points: "))

# Step 2: Initialize lists for x and y values
x, y = [], []

# Step 3: Input data points
for i in range(n):
    x.append(float(input("Enter x[{}]: ".format(i))))
    y.append(float(input("Enter y[{}]: ".format(i))))

# Step 4: Initialize sums
sumx, sumxx, sumy, sumxy = 0, 0, 0, 0

# Step 5: Calculate sums needed for regression formula
for i in range(n): 
    sumx += x[i] 
    sumxx += x[i]**2 
    sumy += y[i] 
    sumxy += x[i] * y[i]

# Step 6: Calculate regression coefficients
b = ( n * sumxy - sumx * sumy ) / ( n * sumxx - sumx * sumx )
a = ( sumy - b * sumx ) / n

# Step 7: Print the coefficients
print("a = {}\nb = {}".format(a, b))

# Create a line plot
plt.plot(x, y)

# Add title and labels
plt.title('Simple Line Graph')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Show the graph
plt.show()

# Step 8: Predict y values for unknown x values
while True:
    w = float(input("Enter unknown x: "))
    p = a + b * w
    print("y = {:.3f}".format(p))  # Print y value rounded to three decimal places


