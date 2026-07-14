package chapter26;

/**
 * Visitor — one visit method per concrete element type. A new operation is a
 * new implementation of this interface; the element classes never change.
 */
public interface Visitor {
    void visitNumber(NumberExpr number);
    void visitAddition(Addition addition);
    void visitMultiplication(Multiplication multiplication);
}
