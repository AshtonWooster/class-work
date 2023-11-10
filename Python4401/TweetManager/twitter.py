import pickle
from Tweet import Tweet

# Valid menu inputs
valid_menu_inputs = [1, 2, 3, 4]
# Locally saved tweets
tweets = []

# Load in tweets
try:
    with open("tweets.pickle", "rb") as save:
        tweets = pickle.load(save)
except Exception as e:
    pass

# Tweet Menu function
def displayMenu():
    print("Tweet Menu\n" +
          "-—————\n" +
          "1. Make a Tweet\n" +
          "2. View Recent Tweets\n" + 
          "3. Search Tweets\n" +
          "4. Quit\n")
    
# Get menu input
def get_menu_input():
    user_input = ""
    valid_input = False
    # Loop Until Valid input
    while (not valid_input):
        try:
            displayMenu()
            user_input = int(input("What would you like to do? "))
            
            if user_input in valid_menu_inputs:
                valid_input = True
            else:
                print("Please select a valid option\n")
        except:
            print("Please enter a numeric value.\n")
    
    return user_input

# Make Tweet
def make_tweet():
    # Get Name and tweet
    name = input("\nWhat is your name? ")
    message = ""
    # While message is an invalid length
    valid_input = False
    while not valid_input:
        message = input("What is your tweet?\n")
        if len(message) > 140:
            print("\nTweets can only be 140 characters!\n")
        else:
            valid_input = True
    # Add to list and confirm to user
    tweets.append(Tweet(name, message))
    print(name + ", your tweet has been saved.\n")

# View Tweets
def view_tweets():
    # If no tweets exist
    if len(tweets) < 1:
        print("There are no recent tweets.\n")
        return

    print("Recent Tweets\n-——————")
    for tweet in tweets:
        print(str(tweet) + "\n")

# Search Tweets
def search_tweets():
    # If no tweets exist
    if len(tweets) < 1:
        print("There are no tweets to search.\n")
        return

    # Find all tweets with message
    search = input("What would you like to search for? ")
    searched = []
    for tweet in tweets:
        if search in tweet.get_text():
            searched.append(tweet)
    
    # Display tweets
    print("Search Results\n-——————")
    if len(searched) < 1:
        print("No tweets contained " + search)
    else:
        for tweet in searched:
            print(str(tweet) + "\n")

# Save Files
def save_tweets():
    try:
        # Open file and pickle.dump each tweet into file
        with open("tweets.pickle", "wb") as save_file:
            save_file.seek(0)
            save_file.truncate(0)
            pickle.dump(tweets, save_file)
    except:
        print("Data could not be saved.")

# Main Function
def main():
    user_input = 0
    while user_input != 4:
        user_input = get_menu_input()
        if user_input == 1:
            make_tweet()
        elif user_input == 2:
            view_tweets()
        elif user_input == 3:
            search_tweets()

    print("Thank you for using the Tweet Manager!")
    save_tweets()

main()
