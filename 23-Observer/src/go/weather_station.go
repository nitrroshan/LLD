package main

import "fmt"

// WeatherStation is the Concrete Subject — it holds the temperature and pushes
// updates to every registered observer. It knows only the Observer interface.
type WeatherStation struct {
	observers   []Observer
	temperature float64
}

func (w *WeatherStation) SetTemperature(temperature float64) {
	w.temperature = temperature
	fmt.Printf("WeatherStation: temperature -> %.1f°C\n", temperature)
	w.NotifyObservers()
}

func (w *WeatherStation) RegisterObserver(observer Observer) {
	w.observers = append(w.observers, observer)
}

func (w *WeatherStation) RemoveObserver(observer Observer) {
	for i, o := range w.observers {
		if o == observer {
			w.observers = append(w.observers[:i], w.observers[i+1:]...)
			return
		}
	}
}

func (w *WeatherStation) NotifyObservers() {
	// Iterate a copy so an observer may unsubscribe during notification.
	snapshot := make([]Observer, len(w.observers))
	copy(snapshot, w.observers)
	for _, observer := range snapshot {
		observer.Update(w.temperature)
	}
}
