
from lists import Queue  # Import the Queue class
from overflow import overflow  # Import the overflow function

# This function duplicates and returns the board. You may find this useful
def copy_board(board):
    current_board = []
    height = len(board)
    for i in range(height):
        current_board.append(board[i].copy())
    return current_board

# This function is your evaluation function for the board
def evaluate_board(board, player):
    score = 0
    for row in board:
        for cell in row:
            if player * cell > 0:  # Player's pieces
                score += abs(cell)
            elif cell != 0:  # Opponent's pieces
                score -= abs(cell)
                
    if is_winning(board, player):
        return float('100000')  # Winning board
    elif is_winning(board, -player):
        return float('-100000')  # Losing board
    else:
        return score

def is_winning(board, player):
    for row in board:
        for cell in row:
            if player * cell < 0:
                return False
    return True

def can_place_gem(board, row, col, player):
    return board[row][col] == 0 or player * board[row][col] > 0

def place_gem(board, row, col, player):
    new_board = copy_board(board)
    new_board[row][col] += player

    # Initialize the queue for the overflow process
    a_queue = Queue()

    # Process overflow using the imported overflow function
    overflow(new_board, a_queue)

    return new_board

class GameTree:
    class Node:
        def __init__(self, board, depth, player, move=None, tree_height=1):
            self.board = board
            self.depth = depth
            self.player = player
            self.children = []
            self.score = None
            self.move = move  # Store the move that led to this node
            self.tree_height = tree_height
            self._generate_children()

        def _generate_children(self):
            if self.depth >= self.tree_height or is_winning(self.board, self.player) or is_winning(self.board, -self.player):
                self.score = evaluate_board(self.board, self.player)
                return
            
            for i in range(len(self.board)):
                for j in range(len(self.board[i])):
                    if can_place_gem(self.board, i, j, self.player):
                        new_board = place_gem(self.board, i, j, self.player)
                        child_node = GameTree.Node(new_board, self.depth + 1, -self.player, move=(i, j), tree_height=self.tree_height)
                        self.children.append(child_node)

    def __init__(self, board, player, tree_height=1):
        self.player = player
        self.board = copy_board(board)
        self.root = self.Node(self.board, 0, self.player, tree_height=tree_height)
        self.minimax(self.root, self.player)

    def minimax(self, node, player):
        if node.score is not None:
            return node.score

        if node.depth % 2 == 1:  # Maximize score
            max_eval = float('-inf')
            best_move = None
            for child in node.children:
                eval = self.minimax(child, player)
                if eval > max_eval:
                    max_eval = eval
                    best_move = child.move
            node.score = max_eval
        else:  # Minimize score
            min_eval = float('inf')
            best_move = None
            for child in node.children:
                eval = self.minimax(child, player)
                if eval < min_eval:
                    min_eval = eval
                    best_move = child.move
            node.score = min_eval

        return node.score

    def get_move(self):
        best_move = None

        # Determine if we're selecting the most positive or most negative score based on tree height.
        if self.root.depth % 2 == 1:
            best_score = float('-inf') 
        else:
            best_score = float('inf') 

        for child in self.root.children:
            if child.score is not None:
                if (self.root.depth % 2 == 1 and child.score > best_score): 
                    best_score = child.score
                    best_move = child.move
                elif (self.root.depth % 2 != 1 and child.score < best_score): 
                    best_score = child.score
                    best_move = child.move

        if best_move is not None:
            return best_move  # Return the best move found during the loop
        else:
            # Fallback in case no valid move is found (should not happen with correct minimax evaluation)
            return (0, 0)

    def clear_tree(self):
        self.root = None
