package main

import "fmt"

func main() {
	fmt.Println("=== Bridge Pattern Demo (Go) ===")
	fmt.Println()

	// 1. Basic Remote + TV
	fmt.Println("--- Basic Remote + TV ---")
	tv := NewTv()
	basicRemote := NewRemote(tv)
	basicRemote.TogglePower()
	basicRemote.VolumeUp()
	basicRemote.ChannelUp()
	basicRemote.TogglePower()
	fmt.Println()

	// 2. Advanced Remote + Radio
	fmt.Println("--- Advanced Remote + Radio ---")
	radio := NewRadio()
	advRemote := NewAdvancedRemote(radio)
	advRemote.TogglePower()
	advRemote.SetChannelDirect(95)
	advRemote.VolumeUp()
	advRemote.PrintStatus()
	advRemote.Mute()
	advRemote.PrintStatus()
	fmt.Println()

	// 3. Advanced Remote + TV
	fmt.Println("--- Advanced Remote + TV ---")
	tv2 := NewTv()
	advTv := NewAdvancedRemote(tv2)
	advTv.TogglePower()
	advTv.SetChannelDirect(42)
	advTv.VolumeUp()
	advTv.VolumeUp()
	advTv.PrintStatus()
}
