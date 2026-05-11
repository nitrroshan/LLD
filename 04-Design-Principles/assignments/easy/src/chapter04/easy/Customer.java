package chapter04.easy;

// TODO (Tell Don't Ask + Demeter):
// Customer should know how to send its own notification.
// Constructor takes: name, email, phone, membershipLevel, preferredChannel
//
// Method: void sendPromotion(String message)
//   → Customer decides internally whether to use email or SMS
//   → No external code should ask for channel and decide
//
// Method: String getMembershipLevel()
//   → Needed by DiscountCalculator
//
// Method: double getDiscountedPrice(double originalPrice)
//   → Uses DiscountCalculator internally (Tell, Don't Ask)

public class Customer {

}
