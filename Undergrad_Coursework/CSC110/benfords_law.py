"""
Michael Masterton 
CSc 110
Project - 5
This program has 4 functions that analyzes data from a file and checks
to see if the data follows Benford's Law, meaning it checks to see if
the numbers are real or made up
"""

def csv_to_list(file_name):
    """
    This function opens and reads a file and then creates a list
    of numbers that are in the file
    Args:
        file_name: name of the file
    Returns:
        list of all the numbers from the file in order
        that they occur in the file
    """
    f = open(file_name, 'r') #opens desired file in read mode
    list = []
    for line in f:
        string = line.strip("\n").split(",")
        #removes line breaks and creates a string seperated by commas
        for i in range(len(string)):
            if string[i][0].isnumeric() == True:
                #if the starting character of the string is a number
                list.append((string[i]))
                #add string to the list
    return list

def count_start_digits(numbers):
    """
    This function creates a dictionary that shows the occurance
    of each number in a string
    Agrs:
        numbers: string of numbers
    Returns:
        a dictionary showing the occurance of 1-9 in order
    """
    dictionary = {}
    for i in range(len(numbers)):
        if int(numbers[i][0]) > 0:
            #if the first character of a number is greater than 0
            if int(numbers[i][0]) not in dictionary:
                #if the number has not appeared yet
                dictionary[int(numbers[i][0])] = 1
            else:
             dictionary[int(numbers[i][0])] += 1
    return dictionary

def digit_percentages(dictionary):
    """
    This function creates a dictionary that calculates the how often each 
    number occurs based on how many numbers there are, as a percent
    Args:
        dictionary: a dictionary showing the occurance of 1-9 in order
    Returns:
        a dictionary showing the percent occurance of each number 
    """
    new_dictionary = {}
    sum = 0
    for value in dictionary.values():
        sum += value
        #how many numbers there are in total
    for key, value in dictionary.items():
        new_dictionary[key] = round((value/sum) * 100, 2)
        #how many times does this number occure divided by how many
        #numbers there are, multiplied by 100 and rounded to 2
        #decimal places to show the percent
    return new_dictionary

def check_benfords_law(dictionary):
    """
    This function checks to see if the percent occuranc of each number
    falls within a range to pass Benford's Law
    Args:
        dictionary: a dictionary showing the percent occurance of 1-9 in order
    Returns:
        a boolean
    """
    b_law = [30, 17, 12, 9, 7, 6, 5, 5, 4]
    #Benfords law states that the number 1 occurs about 30% of the time,
    #number 2 17%, number 3 12%, number 4 9%, number 5 7%, number 6 6%,
    #numbers 7 and 8 5%, and the number 9 4% of the time
    passes = True
    for i in range(len(b_law)):
        high = b_law[i] + 10
        #Benford's law has a range of up to + 10%
        low = b_law[i] - 5
        #Benford's law has a range of up to - 5%
        if dictionary[i + 1] >= high or dictionary[i + 1] <= low:
            #If a number occurs outside the accepted range of that number in
            #Benford's law then it does not follow Benford's law
            return False
        return passes