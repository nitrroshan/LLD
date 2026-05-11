package main

import (
	"fmt"
	"sync"
)

type ConfigManager struct {
	properties map[string]string
}

var (
	configInstance *ConfigManager
	configOnce     sync.Once
)

func GetConfigInstance() *ConfigManager {
	configOnce.Do(func() {
		configInstance = &ConfigManager{
			properties: make(map[string]string),
		}
		configInstance.loadDefaults()
	})
	return configInstance
}

func (cm *ConfigManager) loadDefaults() {
	cm.properties["app.name"] = "LLD Learning App"
	cm.properties["app.version"] = "1.0"
	cm.properties["db.host"] = "localhost"
	cm.properties["db.port"] = "5432"
	cm.properties["log.level"] = "INFO"
}

func (cm *ConfigManager) Get(key string) string {
	return cm.properties[key]
}

func (cm *ConfigManager) Set(key, value string) {
	cm.properties[key] = value
}

func (cm *ConfigManager) Size() int {
	return len(cm.properties)
}

func (cm ConfigManager) String() string {
	return fmt.Sprintf("ConfigManager[%d properties]", len(cm.properties))
}
