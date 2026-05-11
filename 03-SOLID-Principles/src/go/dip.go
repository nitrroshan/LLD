package main

import "fmt"

// DIP — Dependency Inversion Principle
// OrderService depends on Database interface, not a concrete type

type Database interface {
	Save(data string)
}

type MySQLDB struct{}
func (MySQLDB) Save(data string) { fmt.Println("[MySQL] Saved:", data) }

type PostgreSQLDB struct{}
func (PostgreSQLDB) Save(data string) { fmt.Println("[PostgreSQL] Saved:", data) }

type InMemoryDB struct{}
func (InMemoryDB) Save(data string) { fmt.Println("[InMemory] Saved:", data) }

type OrderService struct {
	DB Database // depends on abstraction
}

func (o *OrderService) PlaceOrder(order string) {
	fmt.Println("Placing order:", order)
	o.DB.Save(order)
}
