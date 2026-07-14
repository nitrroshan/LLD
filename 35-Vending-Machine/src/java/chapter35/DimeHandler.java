package chapter35;

public class DimeHandler extends CoinHandler {
    @Override
    protected boolean canHandle(Coin coin) {
        return coin == Coin.DIME;
    }
}
