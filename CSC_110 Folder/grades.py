"""
Michael Masterton
CSc 110
Project 2
This program has 4 functions that calculates grades:
The percent grade based on score and total points,
The letter grade of A-E or X based on the percent,
If the letter grade is a passing grade,
And the results of these three other functions
"""

def point_grade(score, total_points):
    """
    This function calculates the percent grade using division of \
        its two parameters multiplied by 100 and rounded to 2 decimal places
    Args: 
        score: total points received (the dividend)
        total_points: maximum points able to be received (the divisor)
    Returns:
        The quotient of score / total_points multiplied by 100 \
            as a float rounded to 2 decimal places to obtain percent
    """
    percent = round(((score / total_points) * 100), 2)
    return percent

def letter_grade(grade):
    """
    This function returns the string letter grade based on its set parameters \
        and percent
    Args: 
        grade: percent
        grade_int: integer value of grade
    Returns:
        The chosen string letter grade for a set 10 point range that \
            the grade_int falls within
    """
    grade_int = int(grade)
    if grade_int >= 90 and grade_int <= 100:
        #If the percent value is any value betwen 90.0 and 100.0 it is an A
        return("A")
    elif grade_int >= 80 and grade_int < 90:
        #If the percent value is any value between 80.0 and is less than 90.0 it is a B
        return("B")
    elif grade_int >= 70 and grade_int < 80:
        #If the percent value is any value between 70.0 and is less than 80.0 it is a C
        return("C")
    elif grade_int >= 60 and grade_int < 70:
        #If the percent value is any value between 60.0 and is less than 70.0 it is a D
        return("D")
    elif grade_int >= 0 and grade_int < 60:
        #If the percent value is any value between 0.0 and is less than 60.0 it is an E
        return("E")
    else:
        #If the percent value is any value less than 0.0 or greater than 100.0 it is a X
        return("X")

def pass_or_fail(letter_grade):
    """
    This function determines if the letter grade is passing or not \
        based on a letter range
    Args: 
        letter_grade: 1 character string value determining \
             the range of the grade percent
    Returns:
        Pass or Fail
    """
    if len(letter_grade) > 1:
        #If letter grade is longer than 1 character it causes an error
        print("Error")
    elif letter_grade != "A" and letter_grade != "B" \
        and letter_grade != "C" and letter_grade != "D":
        #If the letter grade is not A, B, C, D the grade is failing or uncalculatedable
        return("Fail")
    else:
        #If the letter grade does equal A, B, C, or D it is passing
        return("Pass")

def get_grade_results(score, total_points):
    """
    This function uses 2 parameters and applies the prior 3 \
        functions to print a string showing percent, letter grade \
            and if the grade is passing or not
    Args: 
        score: total points recieved (dividend)
        total_points: maximum points able to be recieved (divisor)
    Returns:
        a string showing percent, letter grade, and if the grade is passing
    """
    grade = point_grade(score, total_points)
    #Calculates the percent based on score and total points
    letter_grade(grade)
    #Assigns a letter grade based on percent
    pass_or_fail(letter_grade(grade))
    #Determines if the letter grade is a passing one or not
    return ("Your grade is ") + str(grade) + " "\
        '(' + (letter_grade(grade) + " " + '-' \
            + " " + pass_or_fail(letter_grade(grade))) + ')'