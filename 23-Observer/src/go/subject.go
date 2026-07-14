package main

// Subject maintains the observer list and notifies them of changes.
type Subject interface {
	RegisterObserver(observer Observer)
	RemoveObserver(observer Observer)
	NotifyObservers()
}
