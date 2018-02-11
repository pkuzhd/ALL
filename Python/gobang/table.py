class table:
    """docstring for table"""
    def __init__(self, player_b, player_w):
        self.player_b = player_b
        self.player_w = player_w
        self.round = 0
        self.color
        self.chess_dct = {}
        self.chess_lst = []

    def run(self):
        """进行对局，返回胜者"""
        return 'b'

    def run_step(self, pos, color):
        """走一步，无返回值"""
        pass

    def back_step(self):
        """悔棋，无返回值"""
        pass

    def is_win(self):
        """判断输赢，返回胜者"""
        return 'b'

    def log(self):
        """记录日志，无返回值"""
        pass


