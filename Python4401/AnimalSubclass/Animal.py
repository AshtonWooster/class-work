import random

# Different moods for the animals
moods = ["happy", "hungry", "sleepy"]

# Function to get a random mood from the moods list
def getRandomMood():
    return moods[random.randint(0,2)]

# Animal Class
class Animal:
    # Constructor
    def __init__(self, type, name):
        self.__animal_type = type
        self.__name = name
        self.__mood = getRandomMood()
    # To string function
    def __str__(self):
        return (self.__name + " the " + self.__animal_type + " is " + self.__mood)
    # Function to get animal type
    def get_animal_type(self):
        return self.__animal_Type
    # Function to get name
    def get_name(self):
        return self.__name
    # Function to get mood
    def check_mood(self):
        return self.__mood

class Mammal(Animal):
    # Constructor 
    def __init__(self, color, type, name):
        self.__hair_color = color
        super().__init__(type, name)
    # Function to get hair color
    def get_hair_color(self):
        return self.__hair_color

class Bird(Animal):
    # Constructor
    def __init__(self, fly, type, name):
        self.__can_fly = fly
        super().__init__(type, name)
    # Function to get can fly
    def get_can_fly(self):
        return self.__can_fly
    