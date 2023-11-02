import random

# Plays
plays = ["Rock", "Paper", "Scissors"]

# Function to display game message and get input
def status_message(starting=False):
    user_input = "0"
    valid_input = False
    # Set messages to display
    initial_message = "What would you like to do?\n\n"
    play_message = "1. Play again\n"
    third_message = "2. View Statistics\n"
    if starting:
        initial_message = "Welcome to Rock, Paper, Scissors!\n\n"
        play_message = "1. Start new game\n"
        third_message = "2. Load Game\n"
    # Loop until valid input
    while not valid_input:
        print(initial_message + 
              play_message +   
              third_message + 
              "3. Quit\n")
        user_input = input("Enter choice: ")

        if (user_input == "1" or user_input == "2" or user_input == "3"):
            valid_input = True
        else:
            print("Please enter 1, 2, or 3.\n")
    
    return user_input

# Finds winner ( returns 0 for a tie, 1 for computer win, and 2 for player win )
def find_winner(player_choice, computer_choice):
    # Find winner
    scissor_loss = (player_choice == 0 and computer_choice == 2)
    scissor_win = (player_choice == 2 and computer_choice == 0)
    if (computer_choice == player_choice):
        return 0
    elif (computer_choice > player_choice or scissor_win) and not scissor_loss:
        return 1
    else:
        return 2

# get user's play
def get_user_play(round_num):
    user_input = "0"
    valid_input = False

    while not valid_input:
        print("\nRound " + str(round_num+1) + "\n\n" + 
              "1. Rock\n" + 
              "2. Paper\n" +
              "3. Scissors\n")
        user_input = input("What will it be? ")

        if (user_input == "1" or user_input == "2" or user_input == "3"):
            valid_input = True
        else:
            print("Please enter 1, 2, or 3 for your play.\n")
    
    return int(user_input)-1

# play_game
def play_game(round_num):
    # Get user choice
    user_play = get_user_play(round_num)
    # Get computer choice
    computer_play = random.randint(0, 2)
    # Find winner
    winner = find_winner(user_play, computer_play)
    # Messages for win/ loss/ tie
    messages = ["tie", "lose", "win"]
    # Display winner
    print("You chose " + plays[user_play] + ". The computer chose " + plays[computer_play] + ". You " + messages[winner] + "!\n")

    return winner

# Function to show stats
def show_stats(wins, losses, ties):
    win_loss = wins
    if losses != 0:
        win_loss = wins/losses
    print("Wins: " + str(wins) + 
          "\nLosses: " + str(losses) + 
          "\nTies: " + str(ties) + 
          "\n\nWin/Loss Ratio: " + str(round(win_loss, 2)) + "\n")
    
# Get Stats from file
def get_stats(file):
    wins = 0
    losses = 0
    ties = 0
    for i, line in enumerate(file):
        if i == 0:
            wins = int(line.strip())
        elif i == 1:
            losses = int(line.strip())
        elif i == 2:
            ties = int(line.strip())
    return wins, losses, ties

# Main Function
def main():
    player_file = None
    wins = 0
    losses = 0
    ties = 0
    name = ""
    user_input = "0"

    # Loop until player is loaded
    while user_input != "3" and not player_file:
        user_input = status_message(True)
        # New Game
        if user_input == "1":
            name = input("What is your name? ")
            print("\nHello " + name + " let's play!")
            player_file = open(name + ".rps", "w")
        # Load Game
        elif user_input == "2":
            name = input("What is your name? ")
            try:
                # Raise error if file not found
                player_file = open(name + ".rps", "r+")
            except FileNotFoundError:
                print("\n" + name + ", your file could not be found.\n")
                continue
            
            wins, losses, ties = get_stats(player_file)
            print("\nWelcome back " + name + " let's play!")
            # Set User Input for playing
            user_input = 1
    
    # Loop until user wants to quit
    while user_input != "3":
        if user_input == "1":
            winner = play_game(wins+losses+ties)
            if winner == 0:
                ties += 1
            elif winner == 1:
                losses += 1
            else:
                wins += 1
        elif user_input == "2":
            print(name + " here are your game play statistics...")
            show_stats(wins, losses, ties)

        user_input = status_message()

    # Write player data
    try:
        # Clear file
        player_file.seek(0)
        player_file.truncate(0)
        player_file.write(str(wins) + "\n" + str(losses) + "\n" + str(ties))
    except Exception as e:
        print("Sorry " + name + ", your game could not be saved.")
        print(e)
    else:
        print(name + ", your game has been saved")
    # Close file
    player_file.close()

main()
