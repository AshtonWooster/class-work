# Read in values from input
initial_x = float(input("Enter the initial position as a decimal: "))
initial_v = float(input("Enter the initial velocity as a decimal: "))
acceleration = float(input("Enter the acceleration as a decimal: "))
elapsed_time = float(input("Enter the elapsed time as a decimal: "))

# Calculate given: xf = x0 + v0*t + (a*t^2)/2
final_x = initial_x + initial_v * elapsed_time + (acceleration * pow(elapsed_time, 2))/2

# Output the final position
print("The final position of the object is " + str(final_x) + " meters.")
