# Function to read in values until valid input
def readFloat(message):
    toRead = 0.0
    # Loop until a number is provided
    while True:
        try:
            toRead = float(input(message))
        except ValueError:
            print("Invalid input, please enter a number.")
        else:
            break
    return toRead

# Read in all values
initial_x = readFloat("Enter the initial position as a decimal: ")
initial_v = readFloat("Enter the initial velocity as a decimal: ")
acceleration = readFloat("Enter the acceleration as a decimal: ")
elapsed_time = readFloat("Enter the elapsed time as a decimal: ")

# Calculate given: xf = x0 + v0*t + (a*t^2)/2
final_x = initial_x + initial_v * elapsed_time + (acceleration * pow(elapsed_time, 2))/2

# Output the final position
print("The final position of the object is " + str(final_x) + " meters.")
