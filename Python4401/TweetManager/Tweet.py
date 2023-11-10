import time

# Tweet Class
class Tweet:
    # Constructor
    def __init__(self, author, text):
        self.__author = author
        self.__text = text
        self.__age = time.time()
    # To String
    def __str__(self):
        return self.__author + " - " + self.get_age() + "\n" + self.__text
    # Get Author
    def get_author(self):
        return self.__author
    # Get Text
    def get_text(self):
        return self.__text
    # Get Age
    def get_age(self):
        diff_time = time.time() - self.__age
        seconds = int(diff_time)
        minutes = seconds // 60
        hours = minutes // 60

        # Return highest unit of time
        if hours > 0:
            return str(hours) + "h"
        elif minutes > 0:
            return str(minutes) + "m"
        else:
            return str(seconds) + "s"
