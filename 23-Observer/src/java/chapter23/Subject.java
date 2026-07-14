package chapter23;

/**
 * Subject — maintains the observer list and notifies them of changes.
 */
public interface Subject {
    void registerObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
}
