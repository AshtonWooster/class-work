# Ashton Wooster
# Screen Class

from turtle import Turtle
import random

# Constants
MARGINS = 10

# Draw rectangle
def draw_rectangle(drawer, color, length, width):
    drawer.fillcolor(color)
    drawer.begin_fill()
    for i in range(4):
        # Draw box
        drawer.forward(i % 2 == 0 and width or length)
        drawer.right(90)
    drawer.end_fill()

# Screen Class
class Screen:
    # Constructor
    def __init__(self):
        turtle = Turtle()
        turtle.screen.tracer(0)

        self.__turtle = turtle
    
    # Get Screen Dimensions as a tuple
    def get_screen(self):
        return (self.__turtle.screen.window_width(), self.__turtle.screen.window_height())
    
    # Get Bounds
    def get_bounds(self):
        window_size = self.get_screen()

        # Calculate bounds for the grid
        x_start = -(window_size[0] / 2) + MARGINS
        x_end = -x_start
        y_start = (window_size[1] / 2) - MARGINS
        y_end = -y_start

        return (x_start, x_end), (y_start, y_end)
    
    # Update screen
    def update_screen(self):
        self.__turtle.screen.update()
    
    # Render Grid
    def render_grid(self, noise, x_bounds, y_bounds):
        chosen_color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))

        # Calcuate pixel size for the noise grid
        noise_grid = noise.get_grid()
        length = len(noise_grid)
        width = len(noise_grid[0])
        w_pixel = (x_bounds[1] - x_bounds[0]) / width
        l_pixel = (y_bounds[0] - y_bounds[1]) / length

        # Move turtle to top left
        self.__turtle.penup()
        self.__turtle.setpos(x_bounds[0], y_bounds[0])

        for x in range(length):
            for y in range(width):
                # Draw each pixel
                value = noise_grid[x][y]
                color = (value * chosen_color[0] / 255, value * chosen_color[1] / 255, value  * chosen_color[2] / 255)
                draw_rectangle(self.__turtle, color, l_pixel, w_pixel)
                self.__turtle.forward(w_pixel)
            # Move to next row
            self.__turtle.right(90)
            self.__turtle.forward(l_pixel)
            self.__turtle.left(90)
            self.__turtle.backward(w_pixel * width)
    
    # Main Loop
    def main_loop(self):
        self.__turtle.screen.mainloop()
