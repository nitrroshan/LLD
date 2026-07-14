package chapter35;

public class NickelHandler extends CoinHandler {
    @Override
    protected boolean canHandle(Coin coin) {
        return coin == Coin.NICKEL;
    }
}
