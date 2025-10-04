# tictactoe.py
import sys

def print_board(board):
    # board is a list of 9 items (index 0..8)
    print()
    print(f" {board[0]} | {board[1]} | {board[2]} ")
    print("---+---+---")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("---+---+---")
    print(f" {board[6]} | {board[7]} | {board[8]} ")
    print()

def available_moves(board):
    return [i for i, v in enumerate(board) if v == " "]

def check_winner(board):
    wins = [
        (0,1,2), (3,4,5), (6,7,8),  # rows
        (0,3,6), (1,4,7), (2,5,8),  # cols
        (0,4,8), (2,4,6)            # diags
    ]
    for a,b,c in wins:
        if board[a] == board[b] == board[c] and board[a] != " ":
            return board[a]  # returns 'X' or 'O'
    if " " not in board:
        return "Draw"
    return None  # game still on

def ask_move(player, board):
    moves = available_moves(board)
    while True:
        try:
            s = input(f"Player {player} — choose a cell (1-9): ").strip()
            if s.lower() in ("q", "quit", "exit"):
                print("Quitting game.")
                sys.exit(0)
            pos = int(s) - 1
            if pos not in range(9):
                print(" ➜ Enter a number from 1 to 9.")
                continue
            if pos not in moves:
                print(" ➜ That cell is already taken. Pick another.")
                continue
            return pos
        except ValueError:
            print(" ➜ Invalid input. Enter a number 1-9, or 'q' to quit.")

def play_game():
    board = [" "] * 9
    current_player = "X"

    print("Tic-Tac-Toe (terminal)")
    print("Cells are numbered 1 through 9 as follows:")
    print(" 1 | 2 | 3 ")
    print("---+---+---")
    print(" 4 | 5 | 6 ")
    print("---+---+---")
    print(" 7 | 8 | 9 ")
    print("\nEnter 'q' at any time to quit.\n")

    while True:
        print_board(board)
        pos = ask_move(current_player, board)
        board[pos] = current_player

        result = check_winner(board)
        if result == "X" or result == "O":
            print_board(board)
            print(f"🎉 Player {result} wins! Congratulations!")
            break
        elif result == "Draw":
            print_board(board)
            print("It's a draw!")
            break

        # swap player
        current_player = "O" if current_player == "X" else "X"

def main():
    while True:
        play_game()
        again = input("Play again? (y/n): ").strip().lower()
        if again not in ("y", "yes"):
            print("Thanks for playing — goodbye!")
            break

if __name__ == "__main__":
    main()
