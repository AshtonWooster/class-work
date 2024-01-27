# Ashton Wooster
# Noise Class for generating a perlin noise grid

import random
import math

# Characters for printing ordered by brightness I got from Paul Bourke
# brightness = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. "
brightness = " -.:=+o#%@"

# Function that returns influence vectors for a grid
def get_influence_vectors(length, width, frequency):
    # Create permutation table
    max_length = 256
    permutations = [i for i in range(max_length)]
    random.shuffle(permutations)

    # Create Influence Vectors
    influence_vectors = []
    i_length = math.ceil(length/frequency)
    i_width = math.ceil(width/frequency)
    for x in range(i_width):
        # Add a new row
        influence_vectors.append([])
        for y in range(i_length):
            # Pick random x and y for the vector, between -frequency and frequency
            vector_x = (permutations[(x*i_length + y) % max_length] / max_length) * frequency * 2 - frequency
            vector_y = (permutations[(x*i_length + y + 1) % max_length] / max_length) * frequency * 2 - frequency
            influence_vectors[x].append((vector_x, vector_y))
    return influence_vectors

# Function to get the dot product of two vectors
def dot_product(a, b):
    return a[0] * b[0] + a[1] * b[1]

# Noise Class
class Noise:
    # Constructor
    def __init__(self, length=50, width=50):
        self.__grid = [[i/width]*length for i in range(width)]

    # To String
    def __str__(self):
        grid_display = ""

        # Format grid as string
        for x in range(len(self.__grid)):
            for y in range(len(self.__grid[0])):
                grid_display += (brightness[math.floor(self.__grid[x][y] * len(brightness))]) + " "
            grid_display += "\n"

        return grid_display
    
    # Function to set the grid
    def set_grid(self, grid):
        self.__grid = grid

    # Function to get the grid
    def get_grid(self):
        return self.__grid

    # Returns a grid with perlin noise from 0-amplitude
    def noise(self, frequency=10, octaves=1, amplitude=1, persistence=2, amplification=(4/5)):
        length = len(self.__grid[0])
        width = len(self.__grid)
        current_layer = [[0]*length for _ in range(width)]
        # Default value
        if octaves == 0:
            return current_layer

        # Get Influence Vectors
        influence_vectors = get_influence_vectors(length, width, frequency)

        # Loop through each rectangle formed by influence boxes
        for x in range(width):
            for y in range(length):
                # Get lengths
                x_left = x % frequency + 0.5
                y_top = y % frequency + 0.5
                x_right = -(frequency - x_left)
                y_bottom = -(frequency - y_top)
                upper_bound = (frequency ** 2)*2 

                # Find dot products of vectors to point and influence vectors
                top_left = dot_product(influence_vectors[x // frequency - 1][y // frequency - 1], (x_left, y_top)) / upper_bound
                top_right = dot_product(influence_vectors[x // frequency][y // frequency - 1], (x_right, y_top)) / upper_bound
                bottom_left = dot_product(influence_vectors[x // frequency - 1][y // frequency], (x_left, y_bottom)) / upper_bound
                bottom_right = dot_product(influence_vectors[x // frequency][y // frequency], (x_right, y_bottom)) / upper_bound

                # Interpolate dot products
                total_top = top_left * (1 - x_left / frequency) + top_right * (1 + x_right / frequency)
                total_bottom = bottom_left * (1 - x_left / frequency) + bottom_right * (1 + x_right / frequency)
                total = total_top * (1 - y_top / frequency) + total_bottom * (1 + y_bottom / frequency)

                # Amplify extremes, using abs to get around issues with roots of negative numbers
                current_layer[x][y] = total != 0 and (math.pow(abs(total), amplification) * amplitude * (abs(total) / total) + 1) / 2 or 0
    
        # Find total scaling for all octaves
        total_scaling = 1
        for i in range(octaves-1):
            total_scaling += math.pow(persistence, -(i+1))

        # Recursively fill grid to add octaves
        next_layer = self.noise(frequency, octaves-1, amplitude, persistence, amplification)
        for x in range(width):
            for y in range(length):
                current_layer[x][y] = (current_layer[x][y] + next_layer[x][y]/persistence) / (total_scaling)

        
        return current_layer
