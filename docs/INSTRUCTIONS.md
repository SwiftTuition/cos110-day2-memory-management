# 🎯 COS110 Day 2 Project: Technical Specifications

## 📋 Complete Implementation Requirements

### Overview
You need to implement a **Yorozuya Management System** that demonstrates mastery of dynamic memory allocation, pointer manipulation, and proper resource management in C++98.

---

## 🏗️ Class Structure Requirements

### Primary Class: `YorozuyaManager`

```cpp
class YorozuyaManager {
private:
    // Client management
    char** clientNames;          // Dynamic array of client names
    int* clientJobCounts;        // Number of jobs per client
    int clientCount;             // Current number of clients
    int clientCapacity;          // Maximum clients before resize needed

    // Job management
    char*** jobDescriptions;     // 2D array: [client][job] descriptions
    int** jobCapacities;         // Maximum jobs per client before resize

    // Sadaharu's food inventory
    int** foodInventory;         // [food_type][day] consumption
    char** foodNames;            // Names of food types
    int foodTypeCount;           // Number of different food types
    int inventoryDays;           // Number of days tracked

    // Shinpachi's glasses collection
    char*** glassesCollection;   // [backup_level][type][description]
    int glassesTypes;            // Number of glasses types
    int backupLevels;            // Number of backup levels

public:
    // Constructor & Destructor
    YorozuyaManager();
    ~YorozuyaManager();

    // Copy Constructor & Assignment Operator (Rule of Three)
    YorozuyaManager(const YorozuyaManager& other);
    YorozuyaManager& operator=(const YorozuyaManager& other);

    // Client Management
    bool addClient(const char* name);
    bool removeClient(const char* name);
    int findClient(const char* name) const;
    void displayClients() const;

    // Job Management
    bool addJob(const char* clientName, const char* jobDescription);
    bool removeJob(const char* clientName, int jobIndex);
    void displayJobs(const char* clientName) const;
    void displayAllJobs() const;

    // Food Inventory Management
    bool addFoodType(const char* foodName);
    bool updateFoodConsumption(const char* foodName, int day, int amount);
    int getTotalConsumption(const char* foodName) const;
    void displayFoodInventory() const;

    // Glasses Collection Management
    bool addGlassesType(const char* typeName, int backupLevel);
    void displayGlassesCollection() const;

    // Utility functions
    int getClientCount() const;
    int getTotalJobs() const;
    void cleanup(); // Manual cleanup for testing
};
```

---

## 🎯 Detailed Implementation Requirements

### 1. Memory Management Rules

#### Dynamic Allocation Requirements
- **All arrays must be dynamically allocated** using `new`
- **Initial capacities**:
  - Clients: 5
  - Jobs per client: 3
  - Food types: 10
  - Inventory days: 30
  - Glasses types: 5
  - Backup levels: 3

#### Resizing Logic
- **Double capacity** when full (not linear growth)
- **Preserve existing data** during resize
- **Properly deallocate** old memory
- **Update capacity** variables

#### Example Resize Pattern:
```cpp
// When adding 6th client (capacity = 5)
char** newClientNames = new char*[clientCapacity * 2];
// Copy existing data...
delete[] clientNames;
clientNames = newClientNames;
clientCapacity *= 2;
```

### 2. String Management

#### String Storage
- **Allocate exact size** needed (use `strlen()` + 1)
- **Deep copy** all strings (no shallow references)
- **Null-terminate** all strings properly

#### Example String Allocation:
```cpp
bool YorozuyaManager::addClient(const char* name) {
    // Check for resize need first...

    int nameLength = strlen(name);
    clientNames[clientCount] = new char[nameLength + 1];
    strcpy(clientNames[clientCount], name);
    clientCount++;
    return true;
}
```

### 3. Error Handling Requirements

#### Input Validation
- **Null pointer checks** for all string parameters
- **Empty string checks** (reject empty names)
- **Duplicate client** prevention
- **Invalid index** handling for removals

#### Boundary Conditions
- **Empty system** operations (no clients/jobs)
- **Maximum capacity** edge cases
- **Invalid client names** for job operations

### 4. Copy Semantics (Rule of Three)

#### Deep Copy Implementation
```cpp
YorozuyaManager::YorozuyaManager(const YorozuyaManager& other) {
    // Initialize all members to safe values first
    clientNames = NULL;
    clientJobCounts = NULL;
    // ... initialize all members

    // Copy capacity information
    clientCapacity = other.clientCapacity;
    clientCount = other.clientCount;

    // Allocate and copy client data
    if (clientCapacity > 0) {
        clientNames = new char*[clientCapacity];
        clientJobCounts = new int[clientCapacity];

        for (int i = 0; i < clientCount; i++) {
            // Deep copy each string
            int nameLen = strlen(other.clientNames[i]);
            clientNames[i] = new char[nameLen + 1];
            strcpy(clientNames[i], other.clientNames[i]);
            clientJobCounts[i] = other.clientJobCounts[i];
        }
    }
    // Continue for all other dynamic members...
}
```

---

## 📊 Testing Requirements

### Basic Functionality Tests (40%)
1. **Constructor/Destructor**: No crashes, proper initialization
2. **Add Client**: Successfully adds clients, handles duplicates
3. **Remove Client**: Removes existing clients, handles non-existent
4. **Add Job**: Links jobs to clients correctly
5. **Food Management**: Tracks consumption properly
6. **Display Functions**: Show data correctly

### Edge Case Tests (30%)
1. **Empty System**: All operations on empty system
2. **Capacity Limits**: Adding beyond initial capacity
3. **Invalid Inputs**: Null pointers, empty strings
4. **Boundary Values**: First/last clients, jobs
5. **Large Datasets**: Stress testing with many items

### Memory Tests (20%)
1. **No Memory Leaks**: Valgrind clean execution
2. **Proper Deallocation**: All `new` matched with `delete`
3. **Deep Copy Verification**: Changes to copy don't affect original
4. **Destructor Testing**: Cleanup after exceptions

### Implementation Quality (10%)
1. **Code Structure**: Following class specification
2. **Const Correctness**: Proper use of const methods
3. **Error Handling**: Appropriate return values
4. **Comments**: Meaningful documentation

---

## 🎪 Gintama-Style Requirements

### Required Client Names (for testing)
- "Gintoki Sakata"
- "Kagura"
- "Shinpachi Shimura"
- "Sadaharu"
- "Hasegawa" (Madao)
- "Kotaro Katsura" (Zura)
- "Elizabeth"

### Required Job Types
- "Find my lost mayonnaise collection"
- "Fight space pirates (again)"
- "Walk Sadaharu without getting eaten"
- "Clean up after Kagura's food fights"
- "Organize Shinpachi's glasses backup collection"
- "Pretend to pay rent"
- "Avoid Otae's cooking"

### Required Food Types for Sadaharu
- "Dog Food (Premium)"
- "Random Household Items"
- "Furniture"
- "Gintoki's Strawberry Milk"
- "Kagura's Sukonbu"
- "Anything Edible (and Inedible)"

---

## 🔧 Implementation Tips

### Memory Debugging
```bash
# Compile with debugging info
g++ -g -Wall -Wextra -std=c++98 -o yorozuya main.cpp yorozuya.cpp

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./yorozuya
```

### Common Pitfalls to Avoid
1. **Shallow Copy**: Don't just copy pointers
2. **Memory Leaks**: Match every `new` with `delete`
3. **Dangling Pointers**: Set pointers to NULL after deletion
4. **Buffer Overruns**: Always check array bounds
5. **Uninitialized Memory**: Initialize all variables

### Recommended Development Order
1. Basic constructor/destructor
2. Client management (add/remove/find)
3. Simple job management
4. Food inventory basics
5. Copy constructor/assignment
6. Edge case handling
7. Memory optimization

---

## 🎯 Success Criteria

Your implementation will be considered successful when:
- ✅ All basic functionality tests pass
- ✅ No memory leaks detected by Valgrind
- ✅ Handles edge cases gracefully
- ✅ Follows C++98 standards
- ✅ Implements complete Rule of Three
- ✅ Code is well-structured and readable

**Target completion time**: 30 minutes (for experienced students)

---

*Remember: This isn't just about getting it to work - it's about understanding memory management deeply enough to avoid the common pitfalls that plague C++ programmers. Make Gintoki proud! 🎌*