package chapter41;

/**
 * Structured (JSON) formatter — same appenders can emit JSON just by swapping this in.
 */
public class JsonFormatter implements Formatter {
    @Override
    public String format(LogRecord record) {
        return "{\"ts\":" + record.timestamp()
                + ",\"level\":\"" + record.level() + "\""
                + ",\"msg\":\"" + record.message() + "\"}";
    }
}
