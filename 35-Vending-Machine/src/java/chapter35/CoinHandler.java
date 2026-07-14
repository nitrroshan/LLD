package chapter35;

/**
 * Chain of Responsibility — a coin acceptor link. Each handler accepts one
 * denomination (returning its value) or forwards the coin to the next handler.
 * If no handler accepts it, handle() returns 0 (coin rejected).
 */
public abstract class CoinHandler {
    private CoinHandler next;

    public CoinHandler setNext(CoinHandler next) {
        this.next = next;
        return next;   // return next so links can be chained fluently
    }

    public int handle(Coin coin) {
        if (canHandle(coin)) {
            return coin.getValue();
        }
        if (next != null) {
            return next.handle(coin);
        }
        return 0;   // no handler accepted this coin
    }

    protected abstract boolean canHandle(Coin coin);
}
