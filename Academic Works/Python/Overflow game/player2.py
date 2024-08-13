from behindTheScene import GameTree

class PlayerTwo:

    def __init__(self, name = "P2 Bot"):
        self.name = name
        self.tree_height = 1 #(improvement: Bot Smartness)
    #(improvement: Bot Smartness)
    def set_tree_height(self, height):
        self.tree_height = height

    def get_name(self):
        return self.name

    def get_play(self, board):
        tree = GameTree(board, -1)
        (row,col) = tree.get_move()
        return (row,col)