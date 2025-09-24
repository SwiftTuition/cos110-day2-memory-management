#include "../src/yorozuya.h"
#include <cassert>
#include <iostream>

/*
 * 🧠 Memory Management Tests (20% of total grade)
 *
 * "Memory management is like keeping track of Sadaharu's meals -
 * miss one and everything goes horribly wrong." - Shinpachi
 */

int tests_passed = 0;
int total_tests = 0;

void test_constructor_destructor_pairs() {
    std::cout << "🔨 Testing Constructor/Destructor Memory Management..." << std::endl;

    total_tests++;
    try {
        // Test multiple creation/destruction cycles
        for (int i = 0; i < 100; i++) {
            YorozuyaManager* manager = new YorozuyaManager();
            delete manager;
        }
        std::cout << "✅ Constructor/Destructor memory test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Constructor/Destructor memory test failed" << std::endl;
    }
}

void test_rule_of_three() {
    std::cout << "📋 Testing Rule of Three Implementation..." << std::endl;

    // Test copy constructor
    total_tests++;
    try {
        YorozuyaManager original;
        original.addClient("Original Client");
        original.addJob("Original Client", "Original Job");
        original.addFoodType("Original Food");

        // Create copy using copy constructor
        YorozuyaManager copy1(original);

        // Verify independence (modify original)
        original.addClient("Modified Client");

        // Copy should be unaffected
        if (copy1.getClientCount() == 1) {  // Should still have only original client
            std::cout << "✅ Copy constructor independence test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Copy constructor independence test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Copy constructor test failed with exception" << std::endl;
    }

    // Test assignment operator
    total_tests++;
    try {
        YorozuyaManager original;
        YorozuyaManager assigned;

        original.addClient("Assigned Client");
        original.addFoodType("Assigned Food");

        // Test assignment
        assigned = original;

        // Test self-assignment (should not crash)
        assigned = assigned;

        // Verify assignment worked
        if (assigned.getClientCount() == original.getClientCount()) {
            std::cout << "✅ Assignment operator test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Assignment operator test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Assignment operator test failed with exception" << std::endl;
    }
}

void test_dynamic_allocation_cleanup() {
    std::cout << "💾 Testing Dynamic Allocation Cleanup..." << std::endl;

    total_tests++;
    try {
        YorozuyaManager manager;

        // Add many items that require dynamic allocation
        for (int i = 0; i < 50; i++) {
            char clientName[50];
            sprintf(clientName, "Client_%d", i);
            manager.addClient(clientName);

            // Add multiple jobs per client
            for (int j = 0; j < 5; j++) {
                char jobDesc[100];
                sprintf(jobDesc, "Job_%d_for_client_%d", j, i);
                manager.addJob(clientName, jobDesc);
            }
        }

        // Add food types
        for (int i = 0; i < 20; i++) {
            char foodName[50];
            sprintf(foodName, "Food_%d", i);
            manager.addFoodType(foodName);

            // Track consumption for multiple days
            for (int day = 1; day <= 10; day++) {
                manager.updateFoodConsumption(foodName, day, i * day);
            }
        }

        std::cout << "✅ Dynamic allocation stress test passed" << std::endl;
        tests_passed++;

        // Destructor will be called automatically when manager goes out of scope
        // This tests proper cleanup of all allocated memory
    } catch (...) {
        std::cout << "❌ Dynamic allocation stress test failed" << std::endl;
    }
}

void test_resize_operations() {
    std::cout << "📈 Testing Resize Operations Memory Management..." << std::endl;

    total_tests++;
    try {
        YorozuyaManager manager;

        // Force multiple resize operations by exceeding initial capacity
        for (int i = 0; i < 20; i++) {  // Should trigger multiple resizes
            char clientName[50];
            sprintf(clientName, "ResizeClient_%d", i);
            manager.addClient(clientName);

            // Add jobs to trigger job array resizes too
            for (int j = 0; j < 10; j++) {
                char jobDesc[100];
                sprintf(jobDesc, "ResizeJob_%d_%d", i, j);
                manager.addJob(clientName, jobDesc);
            }
        }

        if (manager.getClientCount() == 20) {
            std::cout << "✅ Resize operations memory test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Resize operations memory test failed" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Resize operations memory test failed with exception" << std::endl;
    }
}

void test_string_memory_management() {
    std::cout << "🔤 Testing String Memory Management..." << std::endl;

    total_tests++;
    try {
        YorozuyaManager manager;

        // Test with varying string lengths
        const char* testStrings[] = {
            "A",
            "Short",
            "Medium length string",
            "This is a much longer string that should test dynamic allocation properly",
            "🎌 Unicode and special characters: @#$%^&*()_+-=[]{}|;':\",./<>?"
        };

        for (int i = 0; i < 5; i++) {
            char clientName[200];
            sprintf(clientName, "StringTest_%s", testStrings[i]);
            manager.addClient(clientName);

            char jobDesc[300];
            sprintf(jobDesc, "Job with description: %s", testStrings[i]);
            manager.addJob(clientName, jobDesc);

            char foodName[200];
            sprintf(foodName, "Food_%s", testStrings[i]);
            manager.addFoodType(foodName);
        }

        std::cout << "✅ String memory management test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ String memory management test failed" << std::endl;
    }
}

void test_cleanup_method() {
    std::cout << "🧹 Testing Manual Cleanup Method..." << std::endl;

    total_tests++;
    try {
        YorozuyaManager manager;

        // Add some data
        manager.addClient("Cleanup Test Client");
        manager.addJob("Cleanup Test Client", "Cleanup Test Job");
        manager.addFoodType("Cleanup Test Food");

        // Call manual cleanup
        manager.cleanup();

        // Operations after cleanup should not crash (but may not work normally)
        manager.displayClients();

        std::cout << "✅ Manual cleanup test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Manual cleanup test failed" << std::endl;
    }
}

void test_deep_vs_shallow_copy() {
    std::cout << "🔄 Testing Deep vs Shallow Copy..." << std::endl;

    total_tests++;
    try {
        YorozuyaManager original;
        original.addClient("Deep Copy Test");
        original.addJob("Deep Copy Test", "Original Job");

        // Create copy
        YorozuyaManager copy(original);

        // Modify original
        original.addClient("New Client After Copy");

        // Copy should remain unchanged if deep copy is implemented correctly
        if (copy.getClientCount() == 1 && original.getClientCount() == 2) {
            std::cout << "✅ Deep copy verification test passed" << std::endl;
            tests_passed++;
        } else {
            std::cout << "❌ Deep copy verification test failed" << std::endl;
            std::cout << "   Copy has " << copy.getClientCount() << " clients" << std::endl;
            std::cout << "   Original has " << original.getClientCount() << " clients" << std::endl;
        }
    } catch (...) {
        std::cout << "❌ Deep copy verification test failed with exception" << std::endl;
    }
}

void test_exception_safety() {
    std::cout << "⚠️ Testing Exception Safety..." << std::endl;

    total_tests++;
    try {
        // Test operations with potentially problematic inputs
        YorozuyaManager manager;

        // These should handle gracefully without memory leaks
        manager.addClient(NULL);
        manager.addJob(NULL, "Test");
        manager.addJob("NonExistent", NULL);
        manager.removeClient(NULL);
        manager.updateFoodConsumption(NULL, 1, 10);
        manager.updateFoodConsumption("NonExistent", -1, 10);

        std::cout << "✅ Exception safety test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Exception safety test failed" << std::endl;
    }
}

int main() {
    std::cout << "🎌 === MEMORY MANAGEMENT TESTS ===" << std::endl;
    std::cout << "Sadaharu: 'Woof!' (Translation: 'No memory leaks allowed!')" << std::endl;
    std::cout << "" << std::endl;

    test_constructor_destructor_pairs();
    test_rule_of_three();
    test_dynamic_allocation_cleanup();
    test_resize_operations();
    test_string_memory_management();
    test_cleanup_method();
    test_deep_vs_shallow_copy();
    test_exception_safety();

    std::cout << "" << std::endl;
    std::cout << "📊 === TEST RESULTS ===" << std::endl;
    std::cout << "Tests passed: " << tests_passed << "/" << total_tests << std::endl;

    double percentage = (double)tests_passed / total_tests * 100.0;
    std::cout << "Score: " << percentage << "%" << std::endl;

    if (tests_passed == total_tests) {
        std::cout << "🎉 All memory tests passed!" << std::endl;
        std::cout << "Gintoki: 'No memory leaks? Impressive! Time for strawberry milk!'" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "💡 Pro tip: Run with Valgrind for complete memory verification:" << std::endl;
        std::cout << "   valgrind --leak-check=full ./yorozuya" << std::endl;
        return 0;
    } else {
        std::cout << "❌ Some memory tests failed." << std::endl;
        std::cout << "Shinpachi: 'Memory management is crucial! Review your new/delete pairs.'" << std::endl;
        return 1;
    }
}