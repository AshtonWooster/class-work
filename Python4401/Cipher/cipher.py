# Cipher 
cipher = {
    "a": "0",
    "b": "1",
    "c": "2",
    "d": "3",
    "e": "4",
    "f": "5",
    "g": "6",
    "h": "7",
    "i": "8",
    "j": "9",
    "k": "!",
    "l": "@",
    "m": "#",
    "n": "$",
    "o": "%",
    "p": "^",
    "q": "&",
    "r": "*",
    "s": "(",
    "t": ")",
    "u": "-",
    "v": "+",
    "w": "<",
    "x": ">",
    "y": "?",
    "z": "="
}

# Function to get a key given value from dictionary
def getKey(dict, value):
    for k, v in dict.items():
        if v == value:
            return k
    # If No key exists, return the original value
    return value

# Function to encrypt a message
def encrypt(message):
    new_message = ""
    for char in message:
        # If the character is in the cipher, use the encrypted character, otherwise just add the same character
        if char in cipher:
            new_message += cipher[char]
        else:
            new_message += char
    return new_message

# Function to decrypt a message
def decrypt(message):
    new_message = ""
    for char in message:
        # add the decrypted char to the message, or the original value if it does not exist
        new_message += getKey(cipher, char)
    return new_message

# Function to handle user input for encoding
def userEncode():
    user_message = input("Enter a message to encode: ")
    print("Encoded Message: " + encrypt(user_message) + "\n")

# Function to handle user input for decoding
def userDecode():
    user_message = input("Enter an encoded message: ")
    print("Decoded Message: " + decrypt(user_message) + "\n")

# Function to handle user choice
def optionSelect(user_input):
    # Encode
    if user_input == "1":
        userEncode()
    # Decode
    elif user_input == "2":
        userDecode()
    # Exit
    else:
        return False
    # Will return False when the user wants to exit, and True otherwise
    return True

# Function to get user input for the main menu
def mainMenu():
    user_input = "0"
    valid_input = False
    # Loop until user provides valid input
    while not valid_input:
        print("Welcome to the Secret Message Encoder/Decoder\n" +
                "1. Encode a message\n" +
                "2. Decode a message\n" +
                "3. Exit\n")
        user_input = input("What would you like to do? ")

        if user_input != "1" and user_input != "2" and user_input != "3":
            print("\n"+user_input+" is not a valid choice.\n")
        else:
            valid_input = True
    return user_input

# Main Function
def main():
    user_choice = 0
    user_continue = True
    # Loop while user wants to continue
    while user_continue:
        user_choice = mainMenu()
        user_continue = optionSelect(user_choice)

main()
