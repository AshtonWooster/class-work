# Function to get all the values in the file
def getValuesFromFile(file):
    nums = []
    for line in file:
        # Try to convert to an int
        num = None
        try:
            num = int(line)
        except ValueError:
            print("Could not convert \"" + line.strip() + "\" to int.")
        # If successful add to list
        else:
            nums.append(num)
    return nums

# Function to calculate sum of numbers in list
def getSum(list):
    sum = 0
    for x in list:
        sum += x
    return sum

# Function to get the average of numbers
def getAverage(sum, count):
    return sum/count

# Function to get the min and max of list
def getMinMax(nums):
    min = nums[0]
    max = nums[0]
    for x in nums:
        if x < min:
            min = x
        elif x > max:
            max = x
    
    return min, max

# Function to print all results
def calculateStats():
    # Loop and try to open the file until successful
    numbers_file = None
    while not numbers_file:
        try:
            file_name = input("Please enter the name of the file: ")
            numbers_file = open(file_name, "r")
        except FileNotFoundError:
            print("Please enter a valid file name.")
        # If successful, calculate and print results
        else:
            nums = getValuesFromFile(numbers_file)
            sum = getSum(nums)
            count = len(nums)
            min, max = getMinMax(nums)

            # Print Results
            print("File Name: " + file_name)
            print("Sum: " + str(sum))
            print("Count: " + str(count))
            print("Average: " + str(getAverage(sum, count)))
            print("Maximum: " + str(max))
            print("Minimum: " + str(min))
            print("Range: " + str(max-min))

            numbers_file.close()

# Loop until user enters anything other than y
user_input = "y"
while user_input == "y":
    calculateStats()
    user_input = input("Would you like to evaluate another file? (y/n) ")
