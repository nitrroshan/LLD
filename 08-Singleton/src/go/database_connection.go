package main

import (
	"fmt"
	"sync"
)

type DatabaseConnection struct {
	host      string
	port      int
	connected bool
}

var (
	dbInstance *DatabaseConnection
	dbOnce     sync.Once
)

// GetDatabaseInstance returns the singleton DatabaseConnection.
// sync.Once guarantees the init function runs exactly once,
// even with concurrent goroutines.
func GetDatabaseInstance() *DatabaseConnection {
	dbOnce.Do(func() {
		dbInstance = &DatabaseConnection{
			host:      "localhost",
			port:      5432,
			connected: false,
		}
	})
	return dbInstance
}

func (db *DatabaseConnection) Connect() {
	if !db.connected {
		db.connected = true
		fmt.Printf("Connected to %s:%d\n", db.host, db.port)
	} else {
		fmt.Printf("Already connected to %s:%d\n", db.host, db.port)
	}
}

func (db *DatabaseConnection) Disconnect() {
	if db.connected {
		db.connected = false
		fmt.Printf("Disconnected from %s:%d\n", db.host, db.port)
	}
}

func (db *DatabaseConnection) Query(sql string) string {
	if !db.connected {
		panic("Not connected — call Connect() first")
	}
	return "Result of: " + sql
}

func (db *DatabaseConnection) IsConnected() bool {
	return db.connected
}

func (db DatabaseConnection) String() string {
	return fmt.Sprintf("DatabaseConnection[%s:%d, connected=%t]", db.host, db.port, db.connected)
}
