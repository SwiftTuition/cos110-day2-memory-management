#include "../src/yorozuya.h"
#include <cassert>
#include <iostream>
#include <fstream>

/*
 * 📝 Implementation Quality Tests (10% of total grade)
 *
 * "Code quality is like Shinpachi's glasses - essential for seeing clearly,
 * but often overlooked until something goes horribly wrong." - Gintoki
 */

int tests_passed = 0;
int total_tests = 0;

void test_const_correctness() {
    std::cout << "🔒 Testing Const Correctness..." << std::endl;

    total_tests++;
    try {
        const YorozuyaManager manager;

        // These methods should work on const objects
        int clientCount = manager.getClientCount();
        int totalJobs = manager.getTotalJobs();
        int clientIndex = manager.findClient("Anyone");
        int consumption = manager.getTotalConsumption("Anything");

        // These should not modify the object (const methods)
        manager.displayClients();
        manager.displayAllJobs();
        manager.displayFoodInventory();
        manager.displayGlassesCollection();
        manager.displayJobs("Anyone");

        std::cout << "✅ Const correctness test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Const correctness test failed" << std::endl;
    }
}

void test_return_value_consistency() {
    std::cout << "🔄 Testing Return Value Consistency..." << std::endl;

    YorozuyaManager manager;

    // Test consistent return values for add operations
    total_tests++;
    bool add_results_consistent = true;

    // Adding valid items should return true
    if (!manager.addClient("Valid Client") ||
        !manager.addFoodType("Valid Food")) {
        add_results_consistent = false;
    }

    // Adding invalid items should return false
    if (manager.addClient(NULL) ||
        manager.addClient("") ||
        manager.addClient("Valid Client") ||  // Duplicate
        manager.addFoodType(NULL) ||
        manager.addFoodType("Valid Food")) {  // Duplicate
        add_results_consistent = false;
    }

    if (add_results_consistent) {
        std::cout << "✅ Return value consistency test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Return value consistency test failed" << std::endl;
    }
}

void test_error_handling_gracefully() {
    std::cout << "⚠️ Testing Graceful Error Handling..." << std::endl;

    YorozuyaManager manager;

    // Test that invalid operations don't crash the program
    total_tests++;
    try {
        // All of these should handle gracefully
        manager.removeClient("Non-existent");
        manager.removeJob("Non-existent", 0);
        manager.removeJob("Non-existent", -1);
        manager.displayJobs("Non-existent");
        manager.updateFoodConsumption("Non-existent", 1, 10);
        manager.updateFoodConsumption("Valid Food", -1, 10);
        manager.updateFoodConsumption("Valid Food", 50, 10);  // Out of range day

        std::cout << "✅ Graceful error handling test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Graceful error handling test failed (crashed)" << std::endl;
    }
}

void test_memory_initialization() {
    std::cout << "🧠 Testing Proper Memory Initialization..." << std::endl;

    total_tests++;
    try {
        // Create manager and immediately query values
        YorozuyaManager manager;

        // All counts should be properly initialized to 0
        if (manager.getClientCount() == 0 &&
            manager.getTotalJobs() == 0 &&
            manager.findClient("Anyone") == -1 &&
            manager.getTotalConsumption("Anything") == 0) {
            std::cout << "✅ Memory initialization test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Memory initialization test failed" << std::endl;
            std::cout << "   Client count: " << manager.getClientCount() << std::endl;
            std::cout << "   Total jobs: " << manager.getTotalJobs() << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Memory initialization test failed with exception" << std::endl;
    }
}

void test_string_handling_correctness() {
    std::cout << "🔤 Testing String Handling Correctness..." << std::endl;

    YorozuyaManager manager;

    total_tests++;
    try {
        // Test that strings are properly copied and stored
        const char* testClient = "Test Client";
        const char* testJob = "Test Job Description";
        const char* testFood = "Test Food Type";

        manager.addClient(testClient);
        manager.addJob(testClient, testJob);
        manager.addFoodType(testFood);

        // Verify that find operations work correctly
        if (manager.findClient(testClient) >= 0 &&
            manager.findClient("Non-existent") == -1 &&
            manager.getTotalConsumption(testFood) == 0) {
            std::cout << "✅ String handling correctness test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ String handling correctness test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ String handling correctness test failed with exception" << std::endl;
    }
}

void test_capacity_management() {
    std::cout << "📊 Testing Capacity Management Logic..." << std::endl;

    YorozuyaManager manager;

    total_tests++;
    try {
        // Add items one by one and verify system grows appropriately
        int previous_count = 0;
        bool capacity_growth_correct = true;

        for (int i = 1; i <= 15; i++) {  // Should trigger at least one resize
            char clientName[50];
            sprintf(clientName, "CapacityClient_%d", i);

            if (!manager.addClient(clientName)) {
                capacity_growth_correct = false;
                break;
            }

            int current_count = manager.getClientCount();
            if (current_count != i) {
                capacity_growth_correct = false;
                break;
            }
        }

        if (capacity_growth_correct && manager.getClientCount() == 15) {
            std::cout << "✅ Capacity management test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Capacity management test failed" << std::endl;
            std::cout << "   Final count: " << manager.getClientCount() << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Capacity management test failed with exception" << std::endl;
    }
}

void test_boundary_value_handling() {
    std::cout << "🎯 Testing Boundary Value Handling..." << std::endl;

    YorozuyaManager manager;
    manager.addFoodType("Boundary Test Food");

    total_tests++;
    try {
        bool boundary_handling_correct = true;

        // Test day boundaries (assuming 30-day tracking)
        if (!manager.updateFoodConsumption("Boundary Test Food", 1, 10) ||
            !manager.updateFoodConsumption("Boundary Test Food", 30, 10)) {
            boundary_handling_correct = false;
        }

        // Test invalid day values
        if (manager.updateFoodConsumption("Boundary Test Food", 0, 10) ||
            manager.updateFoodConsumption("Boundary Test Food", 31, 10) ||
            manager.updateFoodConsumption("Boundary Test Food", -1, 10)) {
            boundary_handling_correct = false;
        }

        if (boundary_handling_correct) {
            std::cout << "✅ Boundary value handling test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Boundary value handling test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Boundary value handling test failed with exception" << std::endl;
    }
}

void test_data_integrity() {
    std::cout << "🔐 Testing Data Integrity..." << std::endl;

    YorozuyaManager manager;

    total_tests++;
    try {
        // Add data in specific order
        manager.addClient("First Client");
        manager.addClient("Second Client");
        manager.addJob("First Client", "First Job");
        manager.addJob("Second Client", "Second Job");

        // Verify data relationships are maintained
        if (manager.getClientCount() == 2 &&
            manager.getTotalJobs() == 2 &&
            manager.findClient("First Client") >= 0 &&
            manager.findClient("Second Client") >= 0) {
            std::cout << "✅ Data integrity test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Data integrity test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Data integrity test failed with exception" << std::endl;
    }
}

int main() {
    std::cout << "🎌 === IMPLEMENTATION QUALITY TESTS ===" << std::endl;
    std::cout << "Kagura: 'Time to see if this code is as good as my appetite, aru!'" << std::endl;
    std::cout << "" << std::endl;

    test_const_correctness();
    test_return_value_consistency();
    test_error_handling_gracefully();
    test_memory_initialization();
    test_string_handling_correctness();
    test_capacity_management();
    test_boundary_value_handling();
    test_data_integrity();

    std::cout << "" << std::endl;
    std::cout << "📊 === TEST RESULTS ===" << std::endl;
    std::cout << "Tests passed: " << tests_passed << "/" << total_tests << std::endl;

    double percentage = (double)tests_passed / total_tests * 100.0;
    std::cout << "Score: " << percentage << "%" << std::endl;

    if (tests_passed == total_tests) {
        std::cout << "🎉 All implementation quality tests passed!" << std::endl;
        std::cout << "Shinpachi: 'Excellent code quality! This is professional-grade work!'" << std::endl;
        return 0;
    } else {
        std::cout << "❌ Some implementation quality tests failed." << std::endl;
        std::cout << "Gintoki: 'Good enough isn't good enough. Polish it up!'" << std::endl;
        return 1;
    }
}