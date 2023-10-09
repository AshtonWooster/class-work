from Animal import Animal

# Function to display startup message
def displayStartMessage():
    print("Welcome to the animal generator!")
    print("This program creates Animal objects.")

# Function to display info for a list of animals
def displayAnimals(animals):
    for a in animals:
        print(a)

# Main function
def main():
    # Display Start message
    displayStartMessage()
    # Loop until user does not want to make more animals
    user_loop = 'y'
    animals = []
    while (user_loop == 'y'):
        # Get User input for type and name
        animal_type = input("\nWhat type of animal would you like to create? ")
        animal_name = input("What is the animal's name? ")
        # Create a new animal object
        new_animal = Animal(animal_type, animal_name)
        # Add the animal object to the animals list
        animals.append(new_animal)
        # Prompt for user input to continue loop
        user_loop = input("\nWould you like to add more animals (y/n)? ")
    
    # Print info for all animals
    print("\nAnimal List: ")
    displayAnimals(animals)

main()