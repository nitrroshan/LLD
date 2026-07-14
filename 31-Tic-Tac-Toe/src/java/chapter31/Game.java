package chapter31;

/**
 * Orchestrates the game: alternates players, applies moves, updates status,
 * and prints the board.
 */
public class Game {
    private final Board board;
    private final Player[] players;
    private int current = 0;
    private GameStatus status = GameStatus.IN_PROGRESS;

    public Game(Board board, Player playerX, Player playerO) {
        this.board = board;
        this.players = new Player[]{playerX, playerO};
    }

    public GameStatus getStatus() {
        return status;
    }

    public void play() {
        board.display();
        while (status == GameStatus.IN_PROGRESS) {
            Player player = players[current];
            Move move = player.makeMove(board);
            if (!board.isValid(move)) {
                System.out.printf("  %s made an invalid move %s, skipping%n", player.getName(), move);
                break;
            }
            board.placeMark(move, player.getSymbol());
            System.out.printf("  %s (%s) plays %s%n", player.getName(), player.getSymbol(), move);
            board.display();

            updateStatus();
            current = 1 - current;
        }
        announceResult();
    }

    private void updateStatus() {
        Symbol winner = board.getWinner();
        if (winner == Symbol.X) {
            status = GameStatus.X_WINS;
        } else if (winner == Symbol.O) {
            status = GameStatus.O_WINS;
        } else if (board.isFull()) {
            status = GameStatus.DRAW;
        }
    }

    private void announceResult() {
        switch (status) {
            case X_WINS:
                System.out.println("  Result: " + players[0].getName() + " (X) wins!");
                break;
            case O_WINS:
                System.out.println("  Result: " + players[1].getName() + " (O) wins!");
                break;
            case DRAW:
                System.out.println("  Result: draw.");
                break;
            default:
                System.out.println("  Result: game ended early.");
        }
    }
}
