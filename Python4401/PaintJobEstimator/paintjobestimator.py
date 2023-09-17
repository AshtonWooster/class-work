import math

# Constants
GALLONS_PER_SQUARE_FOOT = 1/350
HOURS_PER_SQUARE_FOOT = 6/350
LABOR_COST = 62.25

# Function to read in only positive floats
def readPositiveFloat(message):
    to_read = 0.0
    # Loop until a number is provided
    while True:
        try:
            to_read = float(input(message))
        except ValueError:
            print("Invalid input, please enter a number.")
        else:
            if (to_read > 0):
                break
            else:
                print("Invalid input, please enter a positive number.")

    return to_read

# Function to calculate gallons of paint and cost
def calcPaint(square_feet, price_per_gallon):
    gallons = math.ceil(square_feet * GALLONS_PER_SQUARE_FOOT)
    price = gallons * price_per_gallon

    return gallons, price

# Function to calculate labor hours and price
def calcLabor(square_feet):
    hours = square_feet * HOURS_PER_SQUARE_FOOT
    price = hours * LABOR_COST

    return hours, price

def outputResults(gallons_needed, paint_cost, labor_hours, labor_cost):
    print("\nGallons of paint required: " + str(gallons_needed))
    print("Hours of labor required: " + str(round(labor_hours, 1)))
    print("Price for paint: $" + str(round(paint_cost, 2)))
    print("Total labor cost: $" + str(round(labor_cost, 2)))
    print("Total cost: $" + str(round(labor_cost + paint_cost, 2)) + "\n")

# Loop until user is done with calculations
user_done = False
while not user_done:
    # Read in variables
    square_feet = readPositiveFloat("Please enter the square feet to be painted. ")
    price_per_gallon = readPositiveFloat("Please enter the price per gallon of paint. ")

    # Calculate results
    gallons_needed, paint_cost = calcPaint(square_feet, price_per_gallon)
    labor_hours, labor_cost = calcLabor(square_feet)

    # Output results to user
    outputResults(gallons_needed, paint_cost, labor_hours, labor_cost)
    
    user_done = input("Would you like to do another estimate? (y/n) ") != "y"
