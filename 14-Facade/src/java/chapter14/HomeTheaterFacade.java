package chapter14;

/**
 * Facade — provides a simple interface over the home theater subsystem.
 * It knows the right components and the right order; the client does not.
 */
public class HomeTheaterFacade {
    private final Projector projector;
    private final Screen screen;
    private final Amplifier amplifier;
    private final TheaterLights lights;
    private final DvdPlayer dvdPlayer;

    public HomeTheaterFacade(Projector projector, Screen screen, Amplifier amplifier,
                             TheaterLights lights, DvdPlayer dvdPlayer) {
        this.projector = projector;
        this.screen = screen;
        this.amplifier = amplifier;
        this.lights = lights;
        this.dvdPlayer = dvdPlayer;
    }

    public void watchMovie(String movie) {
        System.out.println("Get ready to watch a movie...");
        lights.dim(10);
        screen.down();
        projector.on();
        projector.wideScreenMode();
        amplifier.on();
        amplifier.setVolume(8);
        dvdPlayer.on();
        dvdPlayer.play(movie);
    }

    public void endMovie() {
        System.out.println("Shutting movie theater down...");
        dvdPlayer.stop();
        dvdPlayer.off();
        amplifier.off();
        projector.off();
        screen.up();
        lights.on();
    }
}
