package chapter23;

import java.util.ArrayList;
import java.util.List;

/**
 * Concrete Subject — holds the temperature and pushes updates to every
 * registered observer whenever it changes. Knows only the Observer interface.
 */
public class WeatherStation implements Subject {
    private final List<Observer> observers = new ArrayList<>();
    private float temperature;

    public void setTemperature(float temperature) {
        this.temperature = temperature;
        System.out.printf("WeatherStation: temperature -> %.1f°C%n", temperature);
        notifyObservers();
    }

    @Override
    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        // Iterate a copy so an observer may unsubscribe during notification.
        for (Observer observer : new ArrayList<>(observers)) {
            observer.update(temperature);
        }
    }
}
