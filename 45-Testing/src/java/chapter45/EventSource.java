package chapter45;

import java.util.ArrayList;
import java.util.List;

/** A minimal subject that notifies observers — the target of an interaction test. */
public class EventSource {
    public interface EventObserver {
        void onEvent(String event);
    }

    private final List<EventObserver> observers = new ArrayList<>();

    public void addObserver(EventObserver observer) { observers.add(observer); }

    public void fire(String event) {
        for (EventObserver o : observers) o.onEvent(event);
    }
}
