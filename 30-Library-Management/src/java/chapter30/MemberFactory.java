package chapter30;

/**
 * Factory Method — creates the right Member subclass from a MemberType token.
 */
public class MemberFactory {
    public static Member create(MemberType type, String id, String name) {
        switch (type) {
            case STUDENT:
                return new StudentMember(id, name);
            case FACULTY:
                return new FacultyMember(id, name);
            default:
                throw new IllegalArgumentException("Unknown member type: " + type);
        }
    }
}
