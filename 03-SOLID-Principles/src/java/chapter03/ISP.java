package chapter03;

/**
 * ISP — Interface Segregation Principle
 *
 * BAD:  Fat Machine interface forces all implementations to support every operation.
 * GOOD: Segregated interfaces — each machine implements only what it can do.
 */
public class ISP {

    // ===================== BAD =====================
    interface MultiFunctionDevice {
        void print(String doc);
        void scan(String doc);
        void fax(String doc);
    }

    static class AllInOnePrinter implements MultiFunctionDevice {
        public void print(String doc) { System.out.println("Printing: " + doc); }
        public void scan(String doc) { System.out.println("Scanning: " + doc); }
        public void fax(String doc) { System.out.println("Faxing: " + doc); }
    }

    // SimplePrinter is forced to implement scan and fax — methods it doesn't support!
    static class SimplePrinter implements MultiFunctionDevice {
        public void print(String doc) { System.out.println("Printing: " + doc); }
        public void scan(String doc) { /* can't scan! */ }
        public void fax(String doc) { throw new UnsupportedOperationException("No fax!"); }
    }

    // ===================== GOOD =====================
    interface Printable {
        void print(String doc);
    }

    interface Scannable {
        void scan(String doc);
    }

    interface Faxable {
        void fax(String doc);
    }

    static class AllInOnePrinterGood implements Printable, Scannable, Faxable {
        public void print(String doc) { System.out.println("Printing: " + doc); }
        public void scan(String doc) { System.out.println("Scanning: " + doc); }
        public void fax(String doc) { System.out.println("Faxing: " + doc); }
    }

    static class SimplePrinterGood implements Printable {
        public void print(String doc) { System.out.println("Printing: " + doc); }
        // No scan, no fax — only implements what it can do
    }

    static class ScannerOnly implements Scannable {
        public void scan(String doc) { System.out.println("Scanning: " + doc); }
    }

    // ===================== DEMO =====================
    public static void main(String[] args) {
        System.out.println("=== BAD (fat interface — SimplePrinter can't fax) ===");
        SimplePrinter bad = new SimplePrinter();
        bad.print("report.pdf");
        try {
            bad.fax("report.pdf");
        } catch (UnsupportedOperationException e) {
            System.out.println("ERROR: " + e.getMessage());
        }

        System.out.println("\n=== GOOD (segregated interfaces) ===");
        SimplePrinterGood printer = new SimplePrinterGood();
        printer.print("report.pdf");
        // printer.fax(...) — won't even compile! SimplePrinterGood doesn't have fax()

        AllInOnePrinterGood aio = new AllInOnePrinterGood();
        aio.print("report.pdf");
        aio.scan("photo.jpg");
        aio.fax("contract.pdf");
    }
}
