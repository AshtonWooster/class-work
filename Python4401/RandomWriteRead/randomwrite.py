import random

# Function to read in only positive integers
def readPositiveInt(message):
    to_read = -1
    # Loop until a number is provided
    while True:
        try:
            to_read = int(input(message))
        except ValueError:
            print("Invalid input, please enter a number.")
        else:
            if (to_read >= 0):
                break
            else:
                print("Invalid input, please enter a positive number.")

    return to_read

# Function to collect all parameters for writing to file
def collectParameters():
    num_ints = readPositiveInt("How many random numbers do you want? ")
    lower_bound = readPositiveInt("What is the lowest the random number should be? ")

    # Loop until upper_bound >= lower_bound
    upper_bound = -1
    while (upper_bound < lower_bound):
        upper_bound = readPositiveInt("What is the highest the random number should be? ")
        if (upper_bound < lower_bound):
            print("Invalid input, please enter an upper bound greater than the lower bound.")
    
    return num_ints, lower_bound, upper_bound

# Function to write random ints to file
def writeRandInts():
    output_file = None
    # Try to open file
    try:
        output_file = open("randomnum.txt", "a")
    except FileNotFoundError:
        print("The random numbers could not be written to randomnum.txt")
    # If successful then write random ints to
    else:
        num_ints, lower_bound, upper_bound = collectParameters()

        # Generate random integers and write them to file
        for _ in range(num_ints):
            r_int = random.randint(lower_bound, upper_bound)
            output_file.write(str(r_int) + "\n")
        
        print("The random numbers were written to randomnum.txt")
        output_file.close()

writeRandInts()

