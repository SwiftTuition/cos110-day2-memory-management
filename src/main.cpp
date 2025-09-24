#include "yorozuya.h"

/*
 * 🍭 Main Program - The Yorozuya Adventure Begins!
 *
 * "Welcome to the Yorozuya, where we solve all your problems...
 * for a reasonable fee... and by 'solve' we mean 'probably make worse'."
 * - Gintoki Sakata
 */

void displayWelcome() {
    std::cout << "\n🎌===============================================🎌" << std::endl;
    std::cout << "    Welcome to the Yorozuya Management System!" << std::endl;
    std::cout << "🎌===============================================🎌" << std::endl;
    std::cout << "\nGintoki: 'Alright, let's see if this thing actually works...'" << std::endl;
    std::cout << "Kagura: 'It better work, or I'm eating all the code, aru!'" << std::endl;
    std::cout << "Shinpachi: 'Please don't break anything...'" << std::endl;
    std::cout << "Sadaharu: 'Woof!' (Translation: 'I'm hungry!')" << std::endl;
    std::cout << "\n" << std::endl;
}

void testBasicFunctionality() {
    std::cout << "🧪 === BASIC FUNCTIONALITY TEST ===" << std::endl;
    std::cout << "Shinpachi: 'Let's start with something simple...'" << std::endl;

    YorozuyaManager manager;

    // Test adding clients
    std::cout << "\n--- Testing Client Management ---" << std::endl;
    manager.addClient("Gintoki Sakata");
    manager.addClient("Kagura");
    manager.addClient("Shinpachi Shimura");
    manager.addClient("Sadaharu");

    manager.displayClients();

    // Test adding jobs
    std::cout << "\n--- Testing Job Management ---" << std::endl;
    manager.addJob("Gintoki Sakata", "Find my lost mayonnaise collection");
    manager.addJob("Kagura", "Eat everything in the fridge");
    manager.addJob("Shinpachi", "Clean up after everyone");

    manager.displayAllJobs();

    // Test food inventory
    std::cout << "\n--- Testing Food Inventory ---" << std::endl;
    manager.addFoodType("Dog Food (Premium)");
    manager.addFoodType("Gintoki's Strawberry Milk");
    manager.addFoodType("Random Household Items");

    manager.updateFoodConsumption("Dog Food (Premium)", 1, 5);
    manager.updateFoodConsumption("Random Household Items", 1, 12);

    manager.displayFoodInventory();

    std::cout << "\nTotal clients: " << manager.getClientCount() << std::endl;
    std::cout << "Total jobs: " << manager.getTotalJobs() << std::endl;
}

void testEdgeCases() {
    std::cout << "\n🔍 === EDGE CASE TESTING ===" << std::endl;
    std::cout << "Gintoki: 'Time to break things! I mean... test thoroughly.'" << std::endl;

    YorozuyaManager manager;

    // Test empty system operations
    std::cout << "\n--- Testing Empty System ---" << std::endl;
    manager.displayClients();
    manager.displayAllJobs();
    manager.removeClient("Non-existent Client");

    // Test invalid inputs
    std::cout << "\n--- Testing Invalid Inputs ---" << std::endl;
    manager.addClient(NULL);           // Null pointer
    manager.addClient("");             // Empty string
    manager.addJob("Nobody", "Impossible task");  // Non-existent client

    // Test capacity limits (add many clients)
    std::cout << "\n--- Testing Capacity Expansion ---" << std::endl;
    const char* manyClients[] = {
        "Elizabeth", "Hasegawa", "Otae", "Kondou", "Hijikata",
        "Okita", "Yamazaki", "Zura", "Takasugi", "Sakamoto"
    };

    for (int i = 0; i < 10; i++) {
        manager.addClient(manyClients[i]);
    }

    manager.displayClients();
}

void testCopySemantics() {
    std::cout << "\n📋 === COPY SEMANTICS TEST ===" << std::endl;
    std::cout << "Shinpachi: 'Testing the Rule of Three is serious business!'" << std::endl;

    YorozuyaManager original;
    original.addClient("Test Client");
    original.addJob("Test Client", "Test Job");

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    YorozuyaManager copy1(original);
    copy1.displayClients();

    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    YorozuyaManager copy2;
    copy2 = original;
    copy2.displayClients();

    // Test that copies are independent
    std::cout << "\n--- Testing Independence ---" << std::endl;
    copy1.addClient("Copy1 Exclusive");
    copy2.addClient("Copy2 Exclusive");

    std::cout << "Original:" << std::endl;
    original.displayClients();
    std::cout << "Copy 1:" << std::endl;
    copy1.displayClients();
    std::cout << "Copy 2:" << std::endl;
    copy2.displayClients();
}

int main() {
    displayWelcome();

    try {
        // Run basic functionality tests
        testBasicFunctionality();

        // Run edge case tests
        testEdgeCases();

        // Run copy semantics tests
        testCopySemantics();

        std::cout << "\n🎉 === ALL TESTS COMPLETED ===" << std::endl;
        std::cout << "Gintoki: 'Not bad! Maybe we can actually run a business after all.'" << std::endl;
        std::cout << "Kagura: 'Does this mean we get paid now, aru?'" << std::endl;
        std::cout << "Shinpachi: 'Let's not get ahead of ourselves...'" << std::endl;

    } catch (...) {
        std::cout << "\n💥 === SOMETHING WENT WRONG ===" << std::endl;
        std::cout << "Gintoki: 'Well, that escalated quickly...'" << std::endl;
        std::cout << "Kagura: 'I blame Gin-chan!'" << std::endl;
        std::cout << "Shinpachi: 'Why does everything always go wrong?!'" << std::endl;
        return 1;
    }

    std::cout << "\n🎌 Thanks for using the Yorozuya Management System!" << std::endl;
    std::cout << "Remember: 'We may not be the heroes you need, but we're definitely" << std::endl;
    std::cout << "the heroes you can afford!' - Yorozuya Motto (probably)" << std::endl;

    return 0;
}

/*
 * 🎯 MAIN PROGRAM NOTES:
 *
 * This main function provides a comprehensive test of your implementation:
 * - Basic functionality (adding clients, jobs, food types)
 * - Edge cases (empty system, invalid inputs, capacity limits)
 * - Copy semantics (Rule of Three verification)
 *
 * Your implementation should handle all these tests gracefully.
 * If something crashes or behaves unexpectedly, that's where you need to focus!
 *
 * Good luck, and may the memory management force be with you! 🚀
 */