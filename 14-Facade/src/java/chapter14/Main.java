package chapter14;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Facade Pattern Demo ===\n");

        // Build the subsystem components
        Projector projector = new Projector();
        Screen screen = new Screen();
        Amplifier amplifier = new Amplifier();
        TheaterLights lights = new TheaterLights();
        DvdPlayer dvdPlayer = new DvdPlayer();

        // Wrap them in a facade
        HomeTheaterFacade theater =
            new HomeTheaterFacade(projector, screen, amplifier, lights, dvdPlayer);

        // Client uses two simple calls instead of orchestrating 8 subsystem steps
        theater.watchMovie("Inception");

        System.out.println();
        theater.endMovie();

        // The subsystem is still accessible for advanced use — the facade doesn't lock it away
        System.out.println("\n--- Direct subsystem access (advanced) ---");
        projector.on();
        projector.wideScreenMode();
        projector.off();
    }
}
