""" 
Michael Masterton
CSc110-001
Project 1
This Program has 4 functions that compute the area of 4 chosen geometric shapes 
"""

def rectangle_area(base, height):
    '''
    This function returns the area of a rectangle based off its two parameters
        Args:
            Base: the bottom length of the rectangle
            Height: the height of the rectangle
        Returns:
            The sum of base times height 
    '''
    area = base * height 
    return area

def triangle_area(a, b, c):
    ''' 
    This function returns the area of a triangle based on its three parameters and the use of Heron's Formula 
        Args:
            a: side 1
            b: side 2
            c: side 3
            s: semiperimeter based on a, b, and c 
        Returns:
            The sum based on Herons formula
    '''

    s = (a + b + c) / 2 # Calculates the Semiperimeter
    area = (s * (s-a) * (s-b) * (s-c)) ** (1/2) # Heron's formula used to calculate the area
    return area

def trapezoid_area(base_1, base_2, height):
    '''
    This function calculates the area of a trapezoid based on its three parameters
        Args:
            Base_1: the length of one of the bases of the trapezoid
            Base_2: the length of the other base of the trapezoid
            Height: linear distance between the two bases
        Returns:
            The sum of the bases times the height divided by two
    '''

    area = (1/2) * (base_1 + base_2) * height
    return area

def circle_area(radius):
    ''' 
    This function calculates the are of a circle given its single parameter
        Args:
            Radius: half the diameter of the cirlce
        Returns:
            The sum of the radius squared times an approximation of pi to 4 decimal places, all rounded to 2 decimal places
    '''

    area = round( (3.1415 * (radius ** 2) ), 2)
    return area
