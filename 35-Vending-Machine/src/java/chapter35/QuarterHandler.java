package chapter35;

public class QuarterHandler extends CoinHandler {
    @Override
    protected boolean canHandle(Coin coin) {
        return coin == Coin.QUARTER;
    }
}
