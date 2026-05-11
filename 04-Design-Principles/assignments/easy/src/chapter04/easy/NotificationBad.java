package chapter04.easy;

/**
 * BAD CODE — Read this, understand the violations, then refactor.
 *
 * Violations:
 *   DRY: discount logic duplicated in sendPromotion() and generateInvoice()
 *   Demeter: customer.getProfile().getPreferences().getChannel()
 *   Tell Don't Ask: pulls channel from customer, decides externally
 */
public class NotificationBad {

    // Demeter violation: reaching deep into Customer internals
    void sendPromotion(CustomerBad customer, double originalPrice) {
        // DRY violation: discount logic here...
        double discount;
        if (customer.getProfile().getMembershipLevel().equals("Gold")) {
            discount = 0.20;
        } else {
            discount = 0.10;
        }
        double finalPrice = originalPrice * (1 - discount);

        // Demeter violation: chain of calls
        String channel = customer.getProfile().getPreferences().getChannel();

        // Tell Don't Ask: deciding externally how to notify
        if (channel.equals("email")) {
            System.out.println("Sending Email to " + customer.getProfile().getEmail()
                    + ": " + (int)(discount*100) + "% off! Your price: $" + finalPrice);
        } else {
            System.out.println("Sending SMS to " + customer.getProfile().getPhone()
                    + ": " + (int)(discount*100) + "% off! Your price: $" + finalPrice);
        }
    }

    // DRY violation: same discount logic again!
    void generateInvoice(CustomerBad customer, double originalPrice) {
        double discount;
        if (customer.getProfile().getMembershipLevel().equals("Gold")) {
            discount = 0.20;
        } else {
            discount = 0.10;
        }
        double finalPrice = originalPrice * (1 - discount);
        System.out.println("Invoice for " + customer.getProfile().getEmail() + ": $" + finalPrice);
    }
}

class CustomerBad {
    private ProfileBad profile;
    CustomerBad(ProfileBad profile) { this.profile = profile; }
    ProfileBad getProfile() { return profile; }
}

class ProfileBad {
    private String email, phone, membershipLevel;
    private PreferencesBad preferences;
    ProfileBad(String email, String phone, String level, PreferencesBad prefs) {
        this.email = email; this.phone = phone; this.membershipLevel = level; this.preferences = prefs;
    }
    String getEmail() { return email; }
    String getPhone() { return phone; }
    String getMembershipLevel() { return membershipLevel; }
    PreferencesBad getPreferences() { return preferences; }
}

class PreferencesBad {
    private String channel;
    PreferencesBad(String channel) { this.channel = channel; }
    String getChannel() { return channel; }
}
