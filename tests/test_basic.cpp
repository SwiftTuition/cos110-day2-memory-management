#include "../src/yorozuya.h"
#include <cassert>
#include <iostream>

/*
 * 🧪 Basic Functionality Tests (40% of total grade)
 *
 * "Testing basic functionality is like testing if Gintoki can be lazy -
 * it should be obvious, but we need to make sure anyway." - Shinpachi
 */

int tests_passed = 0;
int total_tests = 0;

void test_constructor_destructor() {
    std::cout << "🔨 Testing Constructor/Destructor..." << std::endl;
    total_tests++;

    try {
        YorozuyaManager* manager = new YorozuyaManager();
        delete manager;
        std::cout << "✅ Constructor/Destructor test passed" << std::endl;
        tests_passed++;
    } catch (...) {
        std::cout << "❌ Constructor/Destructor test failed" << std::endl;
    }
}

void test_client_management() {
    std::cout << "👥 Testing Client Management..." << std::endl;

    YorozuyaManager manager;

    // Test adding clients
    total_tests++;
    if (manager.addClient("Gintoki Sakata") &&
        manager.addClient("Kagura") &&
        manager.addClient("Shinpachi Shimura")) {
        std::cout << "✅ Adding clients test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Adding clients test failed" << std::endl;
    }

    // Test client count
    total_tests++;
    if (manager.getClientCount() == 3) {
        std::cout << "✅ Client count test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Client count test failed (expected 3, got "
                  << manager.getClientCount() << ")" << std::endl;
    }

    // Test finding clients
    total_tests++;
    if (manager.findClient("Gintoki Sakata") >= 0 &&
        manager.findClient("Kagura") >= 0 &&
        manager.findClient("Non-existent") == -1) {
        std::cout << "✅ Finding clients test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Finding clients test failed" << std::endl;
    }

    // Test duplicate prevention
    total_tests++;
    if (!manager.addClient("Gintoki Sakata")) {
        std::cout << "✅ Duplicate prevention test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Duplicate prevention test failed" << std::endl;
    }
}

void test_job_management() {
    std::cout << "💼 Testing Job Management..." << std::endl;

    YorozuyaManager manager;
    manager.addClient("Gintoki Sakata");
    manager.addClient("Kagura");

    // Test adding jobs
    total_tests++;
    if (manager.addJob("Gintoki Sakata", "Find lost mayonnaise") &&
        manager.addJob("Kagura", "Eat everything in fridge")) {
        std::cout << "✅ Adding jobs test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Adding jobs test failed" << std::endl;
    }

    // Test total job count
    total_tests++;
    if (manager.getTotalJobs() == 2) {
        std::cout << "✅ Total jobs count test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Total jobs count test failed (expected 2, got "
                  << manager.getTotalJobs() << ")" << std::endl;
    }

    // Test adding job for non-existent client
    total_tests++;
    if (!manager.addJob("Non-existent", "Impossible task")) {
        std::cout << "✅ Non-existent client job test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Non-existent client job test failed" << std::endl;
    }
}

void test_food_inventory() {
    std::cout << "🍖 Testing Food Inventory..." << std::endl;

    YorozuyaManager manager;

    // Test adding food types
    total_tests++;
    if (manager.addFoodType("Dog Food") &&
        manager.addFoodType("Strawberry Milk") &&
        manager.addFoodType("Sukonbu")) {
        std::cout << "✅ Adding food types test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Adding food types test failed" << std::endl;
    }

    // Test updating consumption
    total_tests++;
    if (manager.updateFoodConsumption("Dog Food", 1, 10) &&
        manager.updateFoodConsumption("Dog Food", 2, 15)) {
        std::cout << "✅ Updating consumption test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Updating consumption test failed" << std::endl;
    }

    // Test total consumption
    total_tests++;
    if (manager.getTotalConsumption("Dog Food") == 25) {
        std::cout << "✅ Total consumption test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Total consumption test failed (expected 25, got "
                  << manager.getTotalConsumption("Dog Food") << ")" << std::endl;
    }
}

void test_input_validation() {
    std::cout << "🔍 Testing Input Validation..." << std::endl;

    YorozuyaManager manager;

    // Test null pointer handling
    total_tests++;
    if (!manager.addClient(NULL) &&
        !manager.addJob(NULL, "Some job") &&
        !manager.addFoodType(NULL)) {
        std::cout << "✅ Null pointer handling test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Null pointer handling test failed" << std::endl;
    }

    // Test empty string handling
    total_tests++;
    if (!manager.addClient("") &&
        !manager.addFoodType("")) {
        std::cout << "✅ Empty string handling test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Empty string handling test failed" << std::endl;
    }
}

void test_capacity_expansion() {
    std::cout << "📈 Testing Capacity Expansion..." << std::endl;

    YorozuyaManager manager;

    // Add more clients than initial capacity (should be 5)
    const char* clients[] = {
        "Client1", "Client2", "Client3", "Client4", "Client5",
        "Client6", "Client7", "Client8", "Client9", "Client10"
    };

    total_tests++;
    bool all_added = true;
    for (int i = 0; i < 10; i++) {
        if (!manager.addClient(clients[i])) {
            all_added = false;
            break;
        }
    }

    if (all_added && manager.getClientCount() == 10) {
        std::cout << "✅ Capacity expansion test passed" << std::endl;
        tests_passed++;
    } else {
        std::cout << "❌ Capacity expansion test failed" << std::endl;
    }
}

int main() {
    std::cout << "🎌 === BASIC FUNCTIONALITY TESTS ===" << std::endl;
    std::cout << "Shinpachi: 'Let's make sure the fundamentals work!'" << std::endl;
    std::cout << "" << std::endl;

    test_constructor_destructor();
    test_client_management();
    test_job_management();
    test_food_inventory();
    test_input_validation();
    test_capacity_expansion();

    std::cout << "" << std::endl;
    std::cout << "📊 === TEST RESULTS ===" << std::endl;
    std::cout << "Tests passed: " << tests_passed << "/" << total_tests << std::endl;

    double percentage = (double)tests_passed / total_tests * 100.0;
    std::cout << "Score: " << percentage << "%" << std::endl;

    if (tests_passed == total_tests) {
        std::cout << "🎉 All basic tests passed!" << std::endl;
        std::cout << "Gintoki: 'Not bad! Maybe this system actually works.'" << std::endl;
        return 0;
    } else {
        std::cout << "❌ Some tests failed. Keep working!" << std::endl;
        std::cout << "Kagura: 'More work needed, aru!'" << std::endl;
        return 1;
    }
}