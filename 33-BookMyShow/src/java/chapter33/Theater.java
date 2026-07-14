package chapter33;

import java.util.ArrayList;
import java.util.List;

/**
 * A venue with one or more screens.
 */
public class Theater {
    private final String id;
    private final String name;
    private final List<Screen> screens = new ArrayList<>();

    public Theater(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() { return id; }
    public String getName() { return name; }

    public void addScreen(Screen screen) {
        screens.add(screen);
    }

    public List<Screen> getScreens() {
        return screens;
    }
}
