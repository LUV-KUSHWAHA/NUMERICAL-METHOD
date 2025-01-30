# FALSE POSITION METHOD

def function(x):
    return x**2 - 4*x -10

E = 0.0001
condition = True
while condition:
    x1 = float(input("Enter x1: "))
    x2 = float(input("Enter x2: "))
    f1 = function(x1)
    f2 = function(x2)
    if f1*f2 > 0:
        print("f(x1)*f(x2) should be < 0.\n")
    condition = f1*f2 > 0

print("{:<6} {:<12} {:<12} {:<12} {:<12} {:<12} {:<12}".format("Count", "x1", "x2", "x0", "f(x1)", "f(x2)", "f(x0)"))
condition = True
count = 0
while condition:
    count += 1
    x0 = (x1 * f2 - x2 * f1) / (f2 - f1)
    f0 = function(x0)
    print("{:<6} {:<12.3f} {:<12.3f} {:<12.3f} {:<12.3f} {:<12.3f} {:<12.3f}".format(count, x1, x2, x0, f1, f2, f0))
    if f1*f0 > 0:
        x1 = x0
        f1 = f0
    else:
        x2 = x0
        f2 = f0
    condition = abs(f0) > E

print("Root = {:.3f}".format(x0))
