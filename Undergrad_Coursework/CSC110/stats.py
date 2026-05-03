"""
Michael Masterton
CSc 110
Project - 3
This project has 4 functions that calculate the mean value of a list,\
    the variance of the list based on the mean value, the standard deviation\
        based on the variance, and finally the range based on the difference\
            of the highest and lowest values of the list
"""

def mean(numbers):
    """
    This function returns the value of the sum of the values in the list\
        divided by the amount of values in the list, rounded to 2 decimal places
    Args:
        numbers = list
        toal = sum of the values of the list
    Returns:
        total divided by the amount of values in the list\
            rounded to 2 decimal places
    """
    index = 0
    total = 0
    while index < len(numbers):
        total += numbers[index]
        index += 1
    meanvalue = round((total / len(numbers)), 2)
    return(meanvalue)

def variance(numbers):
    """
    This function returns the value of the sum of the difference squared of the\
        value and the mean value, then the sum is divided by the amount of values - 1
    Args:
        meanvalue = mean of the list
        total = sum of the difference squared of the list
    Returns:
        total divided by the amount of values in the list\ 
            minus 1, rounded to 2 decimal places
    """
    meanvalue = mean(numbers)
    index = 0
    total = 0
    while index < len(numbers):
        total += ((numbers[index] - meanvalue)**2) #Sum of (x - mean)^2
        index += 1
    totalvariance = round((total / (len(numbers)- 1)), 2)
    return(totalvariance)

def sd(numbers):
    """
    This function returns the value of the square root of the variance
    Args:
        totalvariance = variance of the list
    Returns:
        square root of totalvariance rounded to 2 decimal places
    """
    index = 0
    totalvariance = variance(numbers)
    standarddev = round((totalvariance ** (1/2)), 2)
    return(standarddev) 

def list_range(numbers):
    """
    This function returns the difference between the highest and lowest values of a\
        list
    Args:
        high = highest value of the list
        low = lowest value of the list
    Returns:
        returns the difference between the highest and lowest values
    """
    index = 0
    high = numbers[index]
    low = numbers[index]
    while index < len(numbers):
        if numbers[index] < low:
            low = numbers[index]
            index += 1
        elif numbers[index] > high:
            high = numbers[index]
            index += 1
        else:
            index += 1
    listrange = high - low
    return(listrange) 