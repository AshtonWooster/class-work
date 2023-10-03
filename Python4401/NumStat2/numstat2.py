import math

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

# Function to get the min and max of a SORTED list
def getMinMaxSorted(nums):
    min = nums[0]
    max = nums[-1]

    return min, max

# Function to get the median of a sorted list
def getMedian(nums):
    length = len(nums)
    midIndex = math.floor(length/2)
    median = nums[midIndex]
    # If even, the median is the average of the two middle values
    if len(nums) % 2 == 0:
        median = (median + nums[midIndex - 1])/2
    
    return median

# Function to get the modes of a list
def getModes(nums):
    # Collect number of times each item appears in list
    count = {}
    for x in nums:
        if x in count:
            count[x] = count[x] + 1
        else:
            count[x] = 1

    # Find the highest total number of items
    highest = 0
    for _, total in count.items():
        if total > highest:
            highest = total
        
    # Return a list with all modes with the highest total number of appearances
    modes = []
    for num, total in count.items():
        if total == highest:
            modes.append(num)
    return modes
    

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
            # If file is empty
            if len(nums) == 0:
                print("There are no numbers in " + file_name)
                break
            nums.sort()
    
            sum = getSum(nums)
            count = len(nums)
            average = getAverage(sum, count)
            min, max = getMinMaxSorted(nums)
            median = getMedian(nums)
            modes = getModes(nums)

            # Print Results
            print("File Name: " + file_name)
            print("Sum: " + str(sum))
            print("Count: " + str(count))
            print("Average: " + str(average))
            print("Maximum: " + str(max))
            print("Minimum: " + str(min))
            print("Range: " + str(max-min))
            print("Median: " + str(median))
            print("Modes: " + str(modes))

            numbers_file.close()

# Loop until user enters anything other than y
user_input = "y"
while user_input == "y":
    calculateStats()
    user_input = input("Would you like to evaluate another file? (y/n) ")
