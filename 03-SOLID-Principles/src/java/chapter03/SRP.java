package chapter03;

/**
 * SRP — Single Responsibility Principle
 *
 * BAD:  Invoice does calculation, printing, AND persistence.
 * GOOD: Each responsibility is in its own class.
 */
public class SRP {

    // ===================== BAD =====================
    static class InvoiceBad {
        private String product;
        private int quantity;
        private double pricePerUnit;

        InvoiceBad(String product, int quantity, double pricePerUnit) {
            this.product = product;
            this.quantity = quantity;
            this.pricePerUnit = pricePerUnit;
        }

        double calculateTotal() {
            return quantity * pricePerUnit;  // responsibility 1: business logic
        }

        void printInvoice() {  // responsibility 2: presentation
            System.out.println("Invoice: " + product + " x" + quantity + " = $" + calculateTotal());
        }

        void saveToDatabase() {  // responsibility 3: persistence
            System.out.println("[DB] Saving invoice for " + product);
        }
    }

    // ===================== GOOD =====================
    static class Invoice {
        private String product;
        private int quantity;
        private double pricePerUnit;

        Invoice(String product, int quantity, double pricePerUnit) {
            this.product = product;
            this.quantity = quantity;
            this.pricePerUnit = pricePerUnit;
        }

        String getProduct() { return product; }
        int getQuantity() { return quantity; }
        double getTotal() { return quantity * pricePerUnit; }
    }

    static class InvoicePrinter {
        void print(Invoice invoice) {
            System.out.println("Invoice: " + invoice.getProduct()
                    + " x" + invoice.getQuantity() + " = $" + invoice.getTotal());
        }
    }

    static class InvoiceRepository {
        void save(Invoice invoice) {
            System.out.println("[DB] Saving invoice for " + invoice.getProduct());
        }
    }

    // ===================== DEMO =====================
    public static void main(String[] args) {
        System.out.println("=== BAD (one class, three responsibilities) ===");
        InvoiceBad bad = new InvoiceBad("Keyboard", 2, 49.99);
        bad.calculateTotal();
        bad.printInvoice();
        bad.saveToDatabase();

        System.out.println("\n=== GOOD (one class per responsibility) ===");
        Invoice invoice = new Invoice("Keyboard", 2, 49.99);
        new InvoicePrinter().print(invoice);
        new InvoiceRepository().save(invoice);
    }
}
