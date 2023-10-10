# Student Grades
gradebook = [[61, 74, 69, 62, 72, 66, 73, 65, 60, 63, 69, 63, 62, 61, 64],
             [73, 80, 78, 76, 76, 79, 75, 73, 76, 74, 77, 79, 76, 78, 72],
             [90, 92, 93, 92, 88, 93, 90, 95, 100, 99, 100, 91, 95, 99, 96],
             [96, 89, 94, 88, 100, 96, 93, 92, 94, 98, 90, 90, 92, 91, 94],
             [76, 76, 82, 78, 82, 76, 84, 82, 80, 82, 76, 86, 82, 84, 78],
             [93, 92, 89, 84, 91, 86, 84, 90, 95, 86, 88, 95, 88, 84, 89],
             [63, 66, 55, 67, 66, 68, 66, 56, 55, 62, 59, 67, 60, 70, 67],
             [86, 92, 93, 88, 90, 90, 91, 94, 90, 86, 93, 89, 94, 94, 92],
             [89, 80, 81, 89, 86, 86, 85, 80, 79, 90, 83, 85, 90, 79, 80],
             [99, 73, 86, 77, 87, 99, 71, 96, 81, 83, 71, 75, 91, 74, 72]]

# Function to find the averages of rows and columns in a 2d array
def findColRowAvg(a):
    # Variables
    count_row = len(a)
    count_col = len(a[0])
    avg_row = []
    avg_col = []

    # Fill avg_col
    for i in range(count_col):
        avg_col.append(0)

    # Loop through all values in 2d array
    for y, row in enumerate(a):
        avg_row.append(0)
        for x, item in enumerate(row):
            # Add the value to both respective averages
            avg_row[y] += item / count_col
            avg_col[x] += item / count_row
    
    return avg_row, avg_col

# Function to neatly display array contents as averages
def displayArray(a, message):
    print(message + " Averages")
    
    # Loop and print each value
    for i, item in enumerate(a):
        print(message + " " + str(i+1) + ": " + str(format(item, ".2f")))

# Main Function
def main():
    # Get averages
    student_averages, assignment_averages = findColRowAvg(gradebook)

    # Display Averages
    displayArray(assignment_averages, "Assignment")
    print("\n")
    displayArray(student_averages, "Student")

main()
