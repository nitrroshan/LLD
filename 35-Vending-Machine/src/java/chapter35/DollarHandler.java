package chapter35;

public class DollarHandler extends CoinHandler {
    @Override
    protected boolean canHandle(Coin coin) {
        return coin == Coin.DOLLAR;
    }
}
