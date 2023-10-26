from Animal import Animal, Bird, Mammal

# Function to display startup message
def displayStartMessage():
    print("Welcome to the animal generator!")
    print("This program creates Animal objects.")

# Function to display info for a list of animals
def displayAnimals(animals):
    for a in animals:
        print(a)
        
# Function to get the animal class from user input
def getAnimalClass():
    user_input = "0"
    valid_input = False
    # Loop until user provides valid input
    while not valid_input:
        print("Would you like to create a mammal or bird?\n" +
                "1. Mammal\n" + 
                "2. Bird\n")
        user_input = input("Which would you like to create? ")

        if user_input == "1" or user_input == "2":
            valid_input = True
        else:
            print(user_input + " is not valid.")
    return user_input

# Main function
def main():
    # Display Start message
    displayStartMessage()
    # Loop until user does not want to make more animals
    user_loop = 'y'
    animals = []
    while (user_loop == 'y'):
        # Get Animal Class from user
        animal_class = getAnimalClass() == "1" and "Mammal" or "Bird"

        # Get User input for type and name
        animal_type = input("\nWhat type of " + animal_class + " would you like to create? ")
        animal_name = input("What is the " + animal_class + "'s name? ")

        # If mammal
        if animal_class == "Mammal":
            hair_color = input("What color is the mammal's hair? ")
            new_mammal = Mammal(hair_color, animal_type, animal_name)
            animals.append(new_mammal)
        else:
            can_fly = input("Can this bird fly? ")
            new_bird = Bird(can_fly, animal_type, animal_name)
            animals.append(new_bird)

        # Prompt for user input to continue loop
        user_loop = input("\nWould you like to add more animals (y/n)? ")
    
    # Print info for all animals
    print("\nAnimal List: ")
    displayAnimals(animals)

main()
