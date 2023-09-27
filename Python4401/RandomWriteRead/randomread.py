# Function to read ints from file
def readInts():
    # Try to open file
    random_ints = None
    try:
        random_ints = open("randomnum.txt", "r")
    except FileNotFoundError:
        print("Cannot read from randomnum.txt, file not found.")
    # If successful then read from file
    else:
        print("List of random numbers in randomnum.txt:")
        # Print all lines in file and get number of lines
        for num_lines, rand_int in enumerate(random_ints):
            print(rand_int.strip())
        print("Random number count: " + str(num_lines + 1))
        random_ints.close()

readInts()