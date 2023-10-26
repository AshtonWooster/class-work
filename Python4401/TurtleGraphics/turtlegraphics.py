from turtle import Turtle

turt = Turtle()
turt.speed = 100
turt.fillcolor("black")
SQUARE_SIZE = 80

# Function for the square rows
def drawSquares(num, fill):
    # Stop when num is 0 
    if num == 0:
        return
    
    # if fill then begin filling
    if fill:
        turt.begin_fill()

    # Draw square
    for i in range(4):
        turt.forward(SQUARE_SIZE)
        turt.right(90)
    turt.forward(SQUARE_SIZE)

    # if fill then end filling
    if fill:
        turt.end_fill()

    # Call the function with 1 less square
    drawSquares(num-1, not fill)
    

# Function to draw a grid
def drawRows(row_size, num_rows):
    # End when num rows is 0
    if num_rows == 0:
        return
    
    # Draw a row, fill first square when its an odd row
    drawSquares(row_size, num_rows % 2 == 1)

    # Reset position
    turt.right(90)
    turt.forward(SQUARE_SIZE)
    turt.right(90)
    turt.forward(SQUARE_SIZE*row_size)
    turt.right(180)

    # Call function with 1 less row
    drawRows(row_size, num_rows-1)

# Main function
def main():
    # Place turtle in position
    turt.penup()
    turt.left(90)
    turt.forward(400)
    turt.left(90)
    turt.forward(400)
    turt.right(180)
    turt.pendown()
    turt.pendown()

    # Draw board
    drawRows(8, 8)

main()

Turtle._screen.exitonclick()
