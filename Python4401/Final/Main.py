# Ashton Wooster
# Main

from Noise import Noise
from Screen import Screen
import time
import math

screen = Screen()

# Constants
FREQUENCY = 10
OCTAVES = 1
AMPLITUDE = 1
PERSISTENCE = 2
AMPLIFICATION = 4/5
X_PIXELS = 50

# Main Function
def main():
    # Find length and width to make the pixels close to squares 
    x_bounds, y_bounds = screen.get_bounds()
    y_pixels = math.ceil((y_bounds[0] - y_bounds[1]) / ((x_bounds[1] - x_bounds[0]) / X_PIXELS))

    noise_grid = Noise(X_PIXELS, y_pixels)
    noise_grid.set_grid(noise_grid.noise(FREQUENCY, OCTAVES, AMPLITUDE, PERSISTENCE, AMPLIFICATION))
    screen.render_grid(noise_grid, x_bounds, y_bounds)
    screen.update_screen()
    screen.main_loop()

main()
