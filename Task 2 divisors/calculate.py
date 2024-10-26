a = 4e-16
b = 1e-5
c = 34.564

x = 1e18

y_ms = a * (x**2) + b * x + c  # y in milliseconds


y_years = y_ms / (1000 * 60 * 60 * 24 * 365.25) # ms in years
print(f"{y_ms} ms\n{y_years} years")