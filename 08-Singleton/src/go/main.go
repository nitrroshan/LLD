package main

import "fmt"

func main() {
	fmt.Println("=== Singleton Pattern Demo (Go) ===")
	fmt.Println()

	// 1. DatabaseConnection Singleton
	fmt.Println("--- DatabaseConnection Singleton ---")
	db1 := GetDatabaseInstance()
	db2 := GetDatabaseInstance()
	fmt.Printf("Same instance? %t\n", db1 == db2)

	db1.Connect()
	db2.Connect() // Already connected — same instance!
	fmt.Println(db1.Query("SELECT * FROM users"))
	db1.Disconnect()
	fmt.Println()

	// 2. ConfigManager Singleton
	fmt.Println("--- ConfigManager Singleton ---")
	config1 := GetConfigInstance()
	config2 := GetConfigInstance()
	fmt.Printf("Same instance? %t\n", config1 == config2)
	fmt.Printf("app.name = %s\n", config1.Get("app.name"))
	config1.Set("app.name", "Updated App")
	fmt.Printf("app.name (via config2) = %s\n", config2.Get("app.name"))
	// Both pointers see the change — they're the same object
}
