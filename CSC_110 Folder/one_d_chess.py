"""
Michael Masterton
CSc 110
Project - 4
This project has 8 functions that create a 1-dimensional chessboard with 2
knights and a king per player, displays the current state of the board,
determines if a desired move is a plausible move, how the king piece moves,
how the knight piece moves, determines what piece moves and moves the piece,
determine if the game has concluded, and finally who the winner is of the 
chess match
"""
def create_board():
    """
    This function creates a new 1-dimensional chessboard with the pieces placed 
    properly
    It has no args
    Returns:
        a new 1-D chessboard
    """
    new_board = ["WKi", "WKn", "WKn", #1 white king at the back and 2 white knights
             "EMPTY", "EMPTY", "EMPTY", #3 empty spaces between white and black
             "BKn", "BKn", "BKi"] #2 black knights and 1 black king at the back
    return(new_board)

def printable_board(board):
    """
    This function displays the current state if the chessboard at a chose time
    based on the board input
    Args:
        board: the current list state of the board
    Returns:
        the current state of the board
    """
    current_board = []
    #an updated list of the board after each move
    for index in range(len(board)):
        if board[index] == "EMPTY":
            current_board.append("   ")
            #If the board list has a spot saying Empty it replaces it with 3 blank 
            # spaces in current_board  
        if board[index] != "EMPTY":
            current_board.append(board[index])
            #If the board list does not have an Empty spot it adds 
            # the piece to the new board in the correct spot
    line1 = "+" + ("-" * 53) + "+"
    #line1 creates the +-----------...--+ borders of the board
    line2_1 = "| " + current_board[0] + " | " + current_board[1] + " | "
    line2_2 = current_board[2] + " | " + current_board[3] + " | "
    line2_3 = current_board[4] + " | " + current_board[5] + " | "
    line2_4 = current_board[6] + " | " + current_board[7] + " | " 
    line2_5 = current_board[8] + " |"
    #line2_1 - line2_5 seperate each spot in the list by " | "
    full_board = line2_1 + line2_2 + line2_3 + line2_4 + line2_5
    #full_board creates the board display
    actual_board = line1 + "\n" + full_board + "\n" + line1
    #actaual_board creates the chessboard with the top and bottom borders
    return(actual_board)

def is_valid_move(board, position, player):
    """
    This function determines if a specified move is plausible based on the 3
    parameters
    Args:
        board: current board list
        position: index of the piece to be moved
        player: is the piece a white or black piece?
    Returns:
        a booleen determining if the move is plausible
    """
    Black_piece = "BKn" or "BKi"
    White_piece = "WKn" or "WKi"
    if player == "BLACK":
        if position in range(len(board)) and board[position] == Black_piece:
            return True
        #If the position parameter is in the index of the board list 
        # and if the player is choosing their own colored piece 
        # then the move is valid
        else:
            return False
    if player == "WHITE" :
        if position in range(len(board)) and board[position] == White_piece:
            return True
        #If the position parameter is in the index of the board list 
        # and if the player is choosing their own colored piece 
        # then the move is valid
        else:
            return False

def move_king(board, position, direction):
    """
    This function defines how the king piece acts and moves based on the parameters
    Args:
        board: board list
        position: index of the king in the board list
        direction: which way in the list does the king move?
    Returns:
        the new state of the board after the king has moved
    """
    index = 1
    if direction == "LEFT" and position > 0:
        while index < len(board) - 1:
            if board[position - index] != "EMPTY" or (position - index) == 0:
                #If the next space to the left is either occupied by a piece 
                # or is the end of the board
                board[position - index] = board[position]
                #Moves king to desired spot
                board[position] = "EMPTY"
                #Makes the king's previous spot empty
                return board
            index += 1
            #Since the king moves until it either: reaches the end of the board or 
            # another piece, it can not occupy an empty space unless that space is the 
            # end of the board, so the index is increased until an valid space is found
    elif direction == "RIGHT" and position < 8:
        while index < len(board):
            if board[position + index] != "EMPTY":
                #If the next space to the right is either occupied by a piece 
                # or is the end of the board
                board[position + index] = board[position]
                #Moves king to desired spot
                board[position] = "EMPTY"
                #Makes the king's previous spot empty
                return board
            index += 1
            #Since the king moves until it either: reaches the end of the board or 
            # another piece, it can not occupy an empty space unless that space is the 
            # end of the board, so the index is increased until an valid space is found

def move_knight(board, position, direction):
    """
    This function defines how the knights pieces move based on the parameters
    Args:
        board: board list
        position: index of the desired knight
        direction: which direction will the knight move?
    Returns:
        the new state of the board after the knight has moved
    """
    left_move = int(position - 2) #Move 2 spaces left
    right_move = int(position + 2) #Move 2 spaces right
    #Knights can only move two spaces per turn
    if direction == "LEFT":
        if left_move in range(len(board)):
            #If the move is a valid move 
            # (meaning the piece stays on the board)
            board[left_move] = board[position]
            #Replace desired position with knight
            board[position] = "EMPTY"
            #Replace knight's old position with a blank space
            return board
    else:
        if right_move in range(len(board)):
            #If the move is a valid move 
            # (meaning the piece stays on the board)
            board[right_move] = board[position]
            #Replace desired position with knight
            board[position] = "EMPTY"
            #Replace knight's old position with a blank space
            return board

def move(board, position, direction):
    """
    This function determines what piece will be moved
    based on the parameters
    Args:
        board: board list
        position: index of the desired piece
        direction: what direction will the piece move?
    Returns:
        the new state of the board after the piece is moved
    """
    if board[position] == "WKn" or board[position] == "BKn":
            move_knight(board, position, direction)
            #IF the piece in the position is a knight move knight
    else:
            move_king(board, position, direction)

def is_game_over(board):
    """
    This function determines if the game has ended based on 
    the pieces left in the board
    Args:
        board: board list
    Returns:
        a boolean based on if one of the kings is no longer 
        on the board
    """
    if "WKi" not in board or "BKi" not in board:
        return True
    else:
        return False
    
def whos_the_winner(board):
    """
    This function determines who won based on the pieces left in the board
    Args:
        board: board list
    Returns:
        a string stating which players won if the opposite player's king
        is not in the board anymore    
    """
    if "WKi" not in board:
            return "Black"
    elif "BKi" not in board:
            return "White"
    else:
        return None
    # If both kings are still on the board no one won, 
    # meaning either: the game is still going or 
    # a stalemate was achieved