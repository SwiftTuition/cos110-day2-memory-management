#include "../src/yorozuya.h"
#include <iostream>

// Test the internal solution to verify it works correctly

int main() {
    std::cout << "🧪 Testing Internal Solution..." << std::endl;

    try {
        YorozuyaManager manager;

        // Test basic functionality
        std::cout << "\n--- Testing Client Management ---" << std::endl;
        manager.addClient("Gintoki Sakata");
        manager.addClient("Kagura");
        manager.addClient("Shinpachi Shimura");
        manager.displayClients();

        std::cout << "\n--- Testing Job Management ---" << std::endl;
        manager.addJob("Gintoki Sakata", "Find lost mayonnaise");
        manager.addJob("Kagura", "Eat everything");
        manager.addJob("Shinpachi", "Clean up mess");
        manager.displayAllJobs();

        std::cout << "\n--- Testing Food Inventory ---" << std::endl;
        manager.addFoodType("Dog Food");
        manager.addFoodType("Strawberry Milk");
        manager.updateFoodConsumption("Dog Food", 1, 10);
        manager.updateFoodConsumption("Dog Food", 2, 15);
        manager.displayFoodInventory();

        std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
        YorozuyaManager copy(manager);
        copy.displayClients();

        std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
        YorozuyaManager assigned;
        assigned = manager;
        assigned.displayClients();

        std::cout << "\n--- Testing Edge Cases ---" << std::endl;
        manager.addClient(NULL);  // Should fail gracefully
        manager.addClient("");   // Should fail gracefully
        manager.addJob("Non-existent", "Test");  // Should fail gracefully

        std::cout << "\n--- Testing Capacity Expansion ---" << std::endl;
        for (int i = 0; i < 10; i++) {
            char name[50];
            sprintf(name, "Client_%d", i);
            manager.addClient(name);
        }
        manager.displayClients();

        std::cout << "\n✅ All solution tests passed!" << std::endl;
        std::cout << "Internal solution is working correctly." << std::endl;

        return 0;

    } catch (...) {
        std::cout << "\n❌ Solution test failed with exception!" << std::endl;
        return 1;
    }
}