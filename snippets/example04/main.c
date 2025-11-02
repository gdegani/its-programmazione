/*
 * Exercise:
 * Write a C program for basic shopping cart management.
 * The program should request as input:
 *   - The number of items in the cart.
 *   - The unit price of each item.
 * The program should calculate the total cart cost:
 *   - If the number of items is greater than 10, apply a 10% discount.
 *   - Calculate the cost including 22% VAT.
 * Print to screen:
 *   - The cart details, taxable amount, VAT, and gross total.
 */

#include <stdio.h>

int main() {
    // Variable declarations
    int num_items;             // Total number of items in cart
    float unit_price;          // Price of a single item
    float taxable_amount;      // Total price without VAT
    float discount = 0;        // Applied discount (if applicable)
    float vat;                 // VAT calculated on total
    float total;               // Final total, including VAT
    // #region sample
    // Request data from user
    printf("Enter the number of items in the cart: ");
    scanf("%d", &num_items);

    printf("Enter the unit price of the items: ");
    scanf("%f", &unit_price);

    // Calculate total cost before applying discounts or VAT
    taxable_amount = num_items * unit_price;

    // #region blocco_if
    // Apply 10% discount if number of items is greater than 10
    if (num_items > 10) {
        discount = taxable_amount * 0.10;  // Calculate discount (10% of total)
        taxable_amount -= discount;         // Update taxable amount after discount
    }
    // #endregion
    // Calculate VAT (22% on taxable amount)
    vat = taxable_amount * 0.22;

    // Calculate gross total (taxable amount + VAT)
    total = taxable_amount + vat;
    // #endregion
    // Print cart details
    printf("\n===== Cart Details =====\n");
    printf("Number of items: %d\n", num_items);
    printf("Unit price: %.2f\n", unit_price);
    printf("Total before discount: %.2f\n", num_items * unit_price);
    printf("Discount applied: %.2f\n", discount);
    printf("Taxable amount (after discount): %.2f\n", taxable_amount);
    printf("VAT (22%%): %.2f\n", vat);
    printf("Gross total: %.2f\n", total);
    printf("==============================\n");

    return 0;
}
