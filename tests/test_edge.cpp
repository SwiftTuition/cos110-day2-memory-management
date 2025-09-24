#include "../src/yorozuya.h"
#include <cassert>
#include <iostream>

/*
 * 🔍 Edge Case Tests (30% of total grade)
 *
 * "Edge cases are like Gintoki's mood swings - unpredictable and potentially dangerous,
 * but you need to handle them anyway." - Shinpachi
 */

int tests_passed = 0;
int total_tests = 0;

void test_empty_system_operations() {
    std::cout << "🕳️ Testing Empty System Operations..." << std::endl;

    YorozuyaManager manager;

    // Test operations on empty system
    total_tests++;
    if (!manager.removeClient("Non-existent") &&
        manager.getClientCount() == 0 &&
        manager.getTotalJobs() == 0 &&
        manager.findClient("Anyone") == -1) {
        std::cout << "✅ Empty system operations test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Empty system operations test failed" << std::endl;
    }

    // Test display functions on empty system (should not crash)
    total_tests++;
    try {
        manager.displayClients();
        manager.displayAllJobs();
        manager.displayFoodInventory();
        manager.displayGlassesCollection();
        std::cout << "✅ Empty system display test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Empty system display test failed" << std::endl;
    }
}

void test_boundary_conditions() {
    std::cout << "🎯 Testing Boundary Conditions..." << std::endl;

    YorozuyaManager manager;

    // Test maximum capacity scenarios
    total_tests++;
    bool stress_test_passed = true;

    // Add many clients to test resizing multiple times
    for (int i = 0; i < 100; i++) {
        char clientName[50];
        sprintf(clientName, "Client_%d", i);
        if (!manager.addClient(clientName)) {
            stress_test_passed = false;
            break;
        }
    }

    if (stress_test_passed && manager.getClientCount() == 100) {
        std::cout << "✅ Stress test (100 clients) passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Stress test failed at client " << manager.getClientCount() << std::endl;
    }

    // Test adding many jobs per client
    total_tests++;
    bool job_stress_passed = true;
    for (int i = 0; i < 20; i++) {
        char jobDesc[100];
        sprintf(jobDesc, "Job_%d_for_client", i);
        if (!manager.addJob("Client_0", jobDesc)) {
            job_stress_passed = false;
            break;
        }
    }

    if (job_stress_passed) {
        std::cout << "✅ Job stress test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Job stress test failed" << std::endl;
    }
}

void test_invalid_indices_and_names() {
    std::cout << "🚫 Testing Invalid Indices and Names..." << std::endl;

    YorozuyaManager manager;
    manager.addClient("Valid Client");

    // Test removing jobs with invalid indices
    total_tests++;
    if (!manager.removeJob("Valid Client", -1) &&
        !manager.removeJob("Valid Client", 999)) {
        std::cout << "✅ Invalid job index test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Invalid job index test failed" << std::endl;
    }

    // Test operations with very long strings
    total_tests++;
    char longName[1000];
    for (int i = 0; i < 999; i++) {
        longName[i] = 'A';
    }
    longName[999] = '\0';

    bool long_string_handled = manager.addClient(longName);
    if (long_string_handled) {
        std::cout << "✅ Long string handling test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Long string handling test failed" << std::endl;
    }
}

void test_duplicate_handling() {
    std::cout << "👥 Testing Duplicate Handling..." << std::endl;

    YorozuyaManager manager;

    // Add initial items
    manager.addClient("Gintoki");
    manager.addFoodType("Dog Food");

    // Test duplicate client prevention
    total_tests++;
    if (!manager.addClient("Gintoki")) {
        std::cout << "✅ Duplicate client prevention test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Duplicate client prevention test failed" << std::endl;
    }

    // Test duplicate food type prevention
    total_tests++;
    if (!manager.addFoodType("Dog Food")) {
        std::cout << "✅ Duplicate food type prevention test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Duplicate food type prevention test failed" << std::endl;
    }

    // Test case sensitivity
    total_tests++;
    if (manager.addClient("gintoki") && manager.addClient("GINTOKI")) {
        std::cout << "✅ Case sensitivity test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Case sensitivity test failed" << std::endl;
    }
}

void test_memory_edge_cases() {
    std::cout << "🧠 Testing Memory Edge Cases..." << std::endl;

    // Test creating and destroying many managers
    total_tests++;
    try {
        for (int i = 0; i < 50; i++) {
            YorozuyaManager* manager = new YorozuyaManager();
            manager->addClient("Test Client");
            manager->addJob("Test Client", "Test Job");
            manager->addFoodType("Test Food");
            delete manager;
        }
        std::cout << "✅ Multiple manager lifecycle test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Multiple manager lifecycle test failed" << std::endl;
    }

    // Test operations after cleanup
    total_tests++;
    try {
        YorozuyaManager manager;
        manager.addClient("Test");
        manager.cleanup();

        // These should not crash, but may not work normally
        manager.displayClients();
        bool result = manager.addClient("After Cleanup");

        std::cout << "✅ Post-cleanup operations test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Post-cleanup operations test failed" << std::endl;
    }
}

void test_string_operations() {
    std::cout << "🔤 Testing String Operations..." << std::endl;

    YorozuyaManager manager;

    // Test strings with special characters
    total_tests++;
    if (manager.addClient("Gintoki™") &&
        manager.addClient("Kagura-chan 🥟") &&
        manager.addJob("Gintoki™", "Find my @#$%^& mayonnaise!")) {
        std::cout << "✅ Special character handling test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Special character handling test failed" << std::endl;
    }

    // Test very short strings (single character)
    total_tests++;
    if (manager.addClient("A") &&
        manager.addFoodType("B")) {
        std::cout << "✅ Single character string test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Single character string test failed" << std::endl;
    }

    // Test strings with spaces and tabs
    total_tests++;
    if (manager.addClient("  Spaced Client  ") &&
        manager.addJob("A", "Job\twith\ttabs")) {
        std::cout << "✅ Whitespace handling test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Whitespace handling test failed" << std::endl;
    }
}

void test_resource_exhaustion() {
    std::cout << "💾 Testing Resource Exhaustion Scenarios..." << std::endl;

    // Test extreme capacity scenarios
    total_tests++;
    try {
        YorozuyaManager manager;

        // Add many food types with many days of tracking
        for (int i = 0; i < 50; i++) {
            char foodName[50];
            sprintf(foodName, "Food_Type_%d", i);
            manager.addFoodType(foodName);

            // Update consumption for multiple days
            for (int day = 1; day <= 30; day++) {
                manager.updateFoodConsumption(foodName, day, i + day);
            }
        }

        std::cout << "✅ Resource exhaustion test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Resource exhaustion test failed" << std::endl;
    }
}

int main() {
    std::cout << "🎌 === EDGE CASE TESTS ===" << std::endl;
    std::cout << "Gintoki: 'Time to push this system to its limits!'" << std::endl;
    std::cout << "" << std::endl;

    test_empty_system_operations();
    test_boundary_conditions();
    test_invalid_indices_and_names();
    test_duplicate_handling();
    test_memory_edge_cases();
    test_string_operations();
    test_resource_exhaustion();

    std::cout << "" << std::endl;
    std::cout << "📊 === TEST RESULTS ===" << std::endl;
    std::cout << "Tests passed: " << tests_passed << "/" << total_tests << std::endl;

    double percentage = (double)tests_passed / total_tests * 100.0;
    std::cout << "Score: " << percentage << "%" << std::endl;

    if (tests_passed == total_tests) {
        std::cout << "🎉 All edge case tests passed!" << std::endl;
        std::cout << "Kagura: 'This system is tougher than Gin-chan's hair, aru!'" << std::endl;
        return 0;
    } else {
        std::cout << "❌ Some edge case tests failed." << std::endl;
        std::cout << "Shinpachi: 'Edge cases are tricky! Keep refining your implementation.'" << std::endl;
        return 1;
    }
}