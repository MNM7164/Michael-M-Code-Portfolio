"""
Michael Masterton
CSc 110
Project - 6
This program is based on a provided starter code and 4 functions have been
modified in order to complete the program
"""
def load_game():
    '''
    This function takes no arguements and creates a dictionary
    of integers as keys and a list of strings as values that is to be displayed 
    at the start of the game in sequence based on the key
    Args:
        None
    Returns:
        A dictionary
    '''
    game_file = open("game.txt", "r")
    #Opens game.txt file in read mode as a variable
    game = {}
    #Is the dictionary of text at the start of the game

    for lines in game_file:
        #Iterates over each line in game.txt
        line = lines.strip("\n").split("\t")
        #strips the lines by new line and then splits it by tab 
        if int(line[0]) not in game:
            #If the integer of the first value of the list is not a key
            #in the dictionary alread
            game[int(line[0])] = []
            #Creates a blank list to ensure the value will be in the form of
            #a list
            game[int(line[0])].append(line[1])
            #Add the value into the list
        else:
            #If the integer of the first value of the list is a key already
            game[int(line[0])].append(line[1])
            #Add values to the list of values
        
    
    game_file.close()
    #Stops reading and closes the game.txt file
    return game

def load_objects():
    '''
    This function takes no arguements and creates a dictionary
    of tuples as keys and a list of strings as values
    Args:
        None
    Returns:
        A dictionary 
    '''
    object_file = open("objects.txt", "r")
    #Opens the objects.txt file in read mode
    objects = {}
    #Is the dictionary of objects

    for lines in object_file:
        #Iterates over each line of the objects.txt file
        line = lines.strip("\n").split("\t")
        #strips the lines by new line and then splits it by tab
        #to create a list
        objects[int(line[0]), int(line[1]), line[2]] = line[3:]
        #The integer of the first two values along side the third value 
        #of the list are put together as a tuple and then added to the 
        #dictionary as keys, the rest of the values of the list stay as a list
        #and are added to the dictionary as values

    object_file.close()
    #Stops reading and closes the objects.txt file
    return objects

def load_travel_table():
    '''
    This function takes no arguements and creates a dictionary
    of tuples as keys and a string as their value
    Args:
        None
    Returns:
        A dictionary
    '''
    travel_file = open("travel_table.txt", "r")
    #Opens the travel_table.txt file in read mode
    travel_table = {}
    #Is a dictionary of the travel table

    for lines in travel_file:
        #Iterates over each line of the travel_table.txt file
        line = lines.strip("\n").split("\t")
        #strips the lines by new line and then splits it by tab
        #to create a list
        travel_table[int(line[0]), int(line[1])] = line[2]
        #The first two values of the list are integers that are put together
        #as a tuple and then added to the dictionary as keys, the remaining 
        #value of the list is a string that is added to the dictionary
        #as a value

    travel_file.close()
    #Stops reading and closes the travel_table.txt file
    return travel_table

def print_instructions():
    '''
    This function takes no arguments and prints
    the exacts contents of the instructions.txt file
    Args:
        none
    Returns:
        the exact text in instructions.txt
    '''
    f = open("instructions.txt", "r")
    #Opens the instructions.txt file in read mode
    for lines in f:
        #Iterates over each line of the instructions.txt file
        line = lines.strip("\n")
        #Strips the lines by new line
        print(line)
        #Prints the stripped lines
    f.close()
    #Stops reading and closes the instructions.txt file

def get_location(location, game, objects, player_objects):
    '''
    This function gets the next location from the game data.
    It doesn't return anything, it prints messages related to
    objects (if the user has them or not) and location information
    Args:
        location: integer
        game: dictionary with location and string information
        objects: dictionary of location, binary (0 or 1), and object name
        player_objects: list of strings
    Returns:
        None
    '''
    # for each string associated with that location in the game
    # dictionary, print that line
    for line in game[location]:
        print(line)

    # check if location has an object associated with it
    for key, value in objects.items():
        # if there's an object associated with this location
        # and the possible action is to take it (0)
        # and user hasn't taken it yet, print message associate with
        # object
        if key[0] == location and key[1] == 0 and key[2] not in player_objects:
            print(value[0])

        # if there's an object associated with this location
        # and we need to check if the user has it (1)
        if key[0] == location and key[1] == 1:
            if key[2] in player_objects:
                # user has the object
                print(value[1])
            else:
                # user does not have the object
                print(value[0])


def go_to_location(location, travel_table, objects, player_objects, answer):
    '''
    This function checks for the user's input (their answer), the objects
    that are available for the users to take, and the objects the user
    has in their object list
    Args:
        location: integer
        travel_table: dictionary with current location, possible to go
                      location and verb that takes user to to go location
        objects: dictionary of location, binary (0 or 1), and object name
        player_objects: list of strings
        answer: input from the user (string)
    Returns:
        next location (integer)
    '''
    # check if user wants to take an object
    if "take" in answer.lower():
        for key in objects:
            # check if there's an object to take
            if key[0] == location and key[1] == 0:
                # add object to user's object list
                player_objects.append(key[2])

    # check if the user needs to have an object to proceed
    for key in objects:
        # if there's a needed object for this location
        # but the user does not have it, return current location 
        # meaning the user doesn't go anywhere
        if key[0] == location and key[1] == 1 and key[2] not in player_objects:
            return location

    # no objects to take or needed to go anywhere
    # check where to go based on user's answer
    for x_y, verb in travel_table.items():
        if x_y[0] == location and verb in answer.upper():
            return x_y[1]


def play_game():
    '''
    This function is the main game playing function.
    It loads all text files for the game, and asks
    for the player's input
    '''
    # load game.txt
    game = load_game()
    # load objects.txt
    objects = load_objects()
    # load travel_table.txt
    travel_table = load_travel_table()
    # player starts with no objects
    player_objects = []
    # player starts at location 0
    location = 0
    # get info for location 0
    get_location(location, game, objects, player_objects)
    # ask if player wants instructions
    answer = input("> ")
    if "y" in answer.lower():
        print_instructions()
    # go to location 1 (start game for real)
    location += 1
    # this is just a demo with 11 locations
    while location < 12:
        # print info on current location
        get_location(location, game, objects, player_objects)
        # request player input
        answer = input("> ")
        # extra line break
        print()
        # player can exit at any time by inputting "exit"
        if "exit" not in answer.lower():
            # player doesn't want to exit
            # get next location based on player's input
            where_to_go = go_to_location(location, travel_table, objects, 
                                      player_objects, answer)
            # if a possible location was found
            if where_to_go:
                # change location
                location = where_to_go
        else: # user entered "exit"
            location = 12
    print("This is the end of this game demo.")