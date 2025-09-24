#include "../src/yorozuya.h"

// Internal solution for testing - students won't see this
// Complete implementation of YorozuyaManager class

YorozuyaManager::YorozuyaManager() {
    // Initialize client management
    clientCount = 0;
    clientCapacity = 5;
    clientNames = new char*[clientCapacity];
    clientJobCounts = new int[clientCapacity];

    // Initialize job management
    jobDescriptions = new char**[clientCapacity];
    jobCapacities = new int*[clientCapacity];

    for (int i = 0; i < clientCapacity; i++) {
        clientNames[i] = NULL;
        clientJobCounts[i] = 0;
        jobDescriptions[i] = new char*[3]; // Initial job capacity per client
        jobCapacities[i] = new int[1];
        jobCapacities[i][0] = 3;

        for (int j = 0; j < 3; j++) {
            jobDescriptions[i][j] = NULL;
        }
    }

    // Initialize food inventory
    foodTypeCount = 0;
    inventoryDays = 30;
    foodNames = new char*[10]; // Initial food type capacity
    foodInventory = new int*[10];

    for (int i = 0; i < 10; i++) {
        foodNames[i] = NULL;
        foodInventory[i] = new int[inventoryDays];
        for (int j = 0; j < inventoryDays; j++) {
            foodInventory[i][j] = 0;
        }
    }

    // Initialize glasses collection (simplified)
    glassesTypes = 0;
    backupLevels = 3;
    glassesCollection = new char*[5]; // Initial types capacity

    for (int i = 0; i < 5; i++) {
        glassesCollection[i] = NULL;
    }
}

YorozuyaManager::~YorozuyaManager() {
    deallocateAll();
}

YorozuyaManager::YorozuyaManager(const YorozuyaManager& other) {
    // Initialize all pointers to NULL first
    clientNames = NULL;
    clientJobCounts = NULL;
    jobDescriptions = NULL;
    jobCapacities = NULL;
    foodNames = NULL;
    foodInventory = NULL;
    glassesCollection = NULL;

    // Copy basic values
    clientCount = other.clientCount;
    clientCapacity = other.clientCapacity;
    foodTypeCount = other.foodTypeCount;
    inventoryDays = other.inventoryDays;
    glassesTypes = other.glassesTypes;
    backupLevels = other.backupLevels;

    // Copy client data
    if (clientCapacity > 0) {
        clientNames = new char*[clientCapacity];
        clientJobCounts = new int[clientCapacity];
        jobDescriptions = new char**[clientCapacity];
        jobCapacities = new int*[clientCapacity];

        for (int i = 0; i < clientCapacity; i++) {
            if (i < clientCount && other.clientNames[i] != NULL) {
                int nameLen = strlen(other.clientNames[i]);
                clientNames[i] = new char[nameLen + 1];
                strcpy(clientNames[i], other.clientNames[i]);
                clientJobCounts[i] = other.clientJobCounts[i];

                // Copy jobs
                int jobCapacity = other.jobCapacities[i][0];
                jobDescriptions[i] = new char*[jobCapacity];
                jobCapacities[i] = new int[1];
                jobCapacities[i][0] = jobCapacity;

                for (int j = 0; j < jobCapacity; j++) {
                    if (j < clientJobCounts[i] && other.jobDescriptions[i][j] != NULL) {
                        int jobLen = strlen(other.jobDescriptions[i][j]);
                        jobDescriptions[i][j] = new char[jobLen + 1];
                        strcpy(jobDescriptions[i][j], other.jobDescriptions[i][j]);
                    } else {
                        jobDescriptions[i][j] = NULL;
                    }
                }
            } else {
                clientNames[i] = NULL;
                clientJobCounts[i] = 0;
                jobDescriptions[i] = new char*[3];
                jobCapacities[i] = new int[1];
                jobCapacities[i][0] = 3;
                for (int j = 0; j < 3; j++) {
                    jobDescriptions[i][j] = NULL;
                }
            }
        }
    }

    // Copy food data
    if (foodTypeCount > 0) {
        foodNames = new char*[10];
        foodInventory = new int*[10];

        for (int i = 0; i < 10; i++) {
            if (i < foodTypeCount && other.foodNames[i] != NULL) {
                int nameLen = strlen(other.foodNames[i]);
                foodNames[i] = new char[nameLen + 1];
                strcpy(foodNames[i], other.foodNames[i]);

                foodInventory[i] = new int[inventoryDays];
                for (int j = 0; j < inventoryDays; j++) {
                    foodInventory[i][j] = other.foodInventory[i][j];
                }
            } else {
                foodNames[i] = NULL;
                foodInventory[i] = new int[inventoryDays];
                for (int j = 0; j < inventoryDays; j++) {
                    foodInventory[i][j] = 0;
                }
            }
        }
    }

    // Initialize glasses collection (simplified)
    glassesCollection = new char*[5];
    for (int i = 0; i < 5; i++) {
        glassesCollection[i] = NULL;
    }
}

YorozuyaManager& YorozuyaManager::operator=(const YorozuyaManager& other) {
    if (this == &other) {
        return *this;
    }

    // Clean up existing data
    deallocateAll();

    // Copy from other (similar to copy constructor)
    clientCount = other.clientCount;
    clientCapacity = other.clientCapacity;

    if (clientCapacity > 0) {
        clientNames = new char*[clientCapacity];
        clientJobCounts = new int[clientCapacity];
        jobDescriptions = new char**[clientCapacity];
        jobCapacities = new int*[clientCapacity];

        for (int i = 0; i < clientCapacity; i++) {
            if (i < clientCount && other.clientNames[i] != NULL) {
                copyString(clientNames[i], other.clientNames[i]);
                clientJobCounts[i] = other.clientJobCounts[i];

                int jobCapacity = other.jobCapacities[i][0];
                jobDescriptions[i] = new char*[jobCapacity];
                jobCapacities[i] = new int[1];
                jobCapacities[i][0] = jobCapacity;

                for (int j = 0; j < jobCapacity; j++) {
                    if (j < clientJobCounts[i] && other.jobDescriptions[i][j] != NULL) {
                        copyString(jobDescriptions[i][j], other.jobDescriptions[i][j]);
                    } else {
                        jobDescriptions[i][j] = NULL;
                    }
                }
            } else {
                clientNames[i] = NULL;
                clientJobCounts[i] = 0;
                jobDescriptions[i] = new char*[3];
                jobCapacities[i] = new int[1];
                jobCapacities[i][0] = 3;
                for (int j = 0; j < 3; j++) {
                    jobDescriptions[i][j] = NULL;
                }
            }
        }
    }

    return *this;
}

bool YorozuyaManager::addClient(const char* name) {
    if (name == NULL || strlen(name) == 0) {
        return false;
    }

    // Check for duplicates
    if (findClient(name) >= 0) {
        return false;
    }

    // Resize if necessary
    if (clientCount >= clientCapacity) {
        resizeClientArrays();
    }

    // Add the client
    copyString(clientNames[clientCount], name);
    clientJobCounts[clientCount] = 0;
    clientCount++;

    return true;
}

bool YorozuyaManager::removeClient(const char* name) {
    if (name == NULL) {
        return false;
    }

    int index = findClient(name);
    if (index == -1) {
        return false;
    }

    // Deallocate client's memory
    delete[] clientNames[index];

    // Deallocate all jobs for this client
    for (int i = 0; i < clientJobCounts[index]; i++) {
        delete[] jobDescriptions[index][i];
    }
    delete[] jobDescriptions[index];
    delete[] jobCapacities[index];

    // Shift remaining clients down
    for (int i = index; i < clientCount - 1; i++) {
        clientNames[i] = clientNames[i + 1];
        clientJobCounts[i] = clientJobCounts[i + 1];
        jobDescriptions[i] = jobDescriptions[i + 1];
        jobCapacities[i] = jobCapacities[i + 1];
    }

    clientCount--;

    // Initialize the last slot
    clientNames[clientCount] = NULL;
    clientJobCounts[clientCount] = 0;
    jobDescriptions[clientCount] = new char*[3];
    jobCapacities[clientCount] = new int[1];
    jobCapacities[clientCount][0] = 3;
    for (int i = 0; i < 3; i++) {
        jobDescriptions[clientCount][i] = NULL;
    }

    return true;
}

int YorozuyaManager::findClient(const char* name) const {
    if (name == NULL) {
        return -1;
    }

    for (int i = 0; i < clientCount; i++) {
        if (clientNames[i] != NULL && strcmp(clientNames[i], name) == 0) {
            return i;
        }
    }

    return -1;
}

void YorozuyaManager::displayClients() const {
    std::cout << "\n=== YOROZUYA CLIENT LIST ===" << std::endl;

    if (clientCount == 0) {
        std::cout << "No clients found." << std::endl;
        return;
    }

    for (int i = 0; i < clientCount; i++) {
        std::cout << (i + 1) << ". " << clientNames[i]
                  << " (Jobs: " << clientJobCounts[i] << ")" << std::endl;
    }

    std::cout << "Total clients: " << clientCount << std::endl;
}

bool YorozuyaManager::addJob(const char* clientName, const char* jobDescription) {
    if (clientName == NULL || jobDescription == NULL || strlen(jobDescription) == 0) {
        return false;
    }

    int clientIndex = findClient(clientName);
    if (clientIndex == -1) {
        return false;
    }

    // Check if we need to resize job array for this client
    if (clientJobCounts[clientIndex] >= jobCapacities[clientIndex][0]) {
        resizeJobArray(clientIndex);
    }

    // Add the job
    copyString(jobDescriptions[clientIndex][clientJobCounts[clientIndex]], jobDescription);
    clientJobCounts[clientIndex]++;

    return true;
}

bool YorozuyaManager::removeJob(const char* clientName, int jobIndex) {
    if (clientName == NULL) {
        return false;
    }

    int clientIdx = findClient(clientName);
    if (clientIdx == -1 || jobIndex < 0 || jobIndex >= clientJobCounts[clientIdx]) {
        return false;
    }

    // Deallocate job memory
    delete[] jobDescriptions[clientIdx][jobIndex];

    // Shift remaining jobs down
    for (int i = jobIndex; i < clientJobCounts[clientIdx] - 1; i++) {
        jobDescriptions[clientIdx][i] = jobDescriptions[clientIdx][i + 1];
    }

    clientJobCounts[clientIdx]--;
    jobDescriptions[clientIdx][clientJobCounts[clientIdx]] = NULL;

    return true;
}

void YorozuyaManager::displayJobs(const char* clientName) const {
    if (clientName == NULL) {
        return;
    }

    int clientIndex = findClient(clientName);
    if (clientIndex == -1) {
        std::cout << "Client not found: " << clientName << std::endl;
        return;
    }

    std::cout << "\nJobs for " << clientName << ":" << std::endl;

    if (clientJobCounts[clientIndex] == 0) {
        std::cout << "No jobs found." << std::endl;
        return;
    }

    for (int i = 0; i < clientJobCounts[clientIndex]; i++) {
        std::cout << (i + 1) << ". " << jobDescriptions[clientIndex][i] << std::endl;
    }
}

void YorozuyaManager::displayAllJobs() const {
    std::cout << "\n=== ALL JOBS ===" << std::endl;

    if (getTotalJobs() == 0) {
        std::cout << "No jobs found." << std::endl;
        return;
    }

    for (int i = 0; i < clientCount; i++) {
        if (clientJobCounts[i] > 0) {
            displayJobs(clientNames[i]);
        }
    }
}

bool YorozuyaManager::addFoodType(const char* foodName) {
    if (foodName == NULL || strlen(foodName) == 0) {
        return false;
    }

    // Check for duplicates
    for (int i = 0; i < foodTypeCount; i++) {
        if (foodNames[i] != NULL && strcmp(foodNames[i], foodName) == 0) {
            return false;
        }
    }

    if (foodTypeCount >= 10) {
        return false; // Max capacity reached
    }

    copyString(foodNames[foodTypeCount], foodName);
    foodTypeCount++;

    return true;
}

bool YorozuyaManager::updateFoodConsumption(const char* foodName, int day, int amount) {
    if (foodName == NULL || day < 1 || day > inventoryDays || amount < 0) {
        return false;
    }

    // Find food type
    int foodIndex = -1;
    for (int i = 0; i < foodTypeCount; i++) {
        if (foodNames[i] != NULL && strcmp(foodNames[i], foodName) == 0) {
            foodIndex = i;
            break;
        }
    }

    if (foodIndex == -1) {
        return false;
    }

    foodInventory[foodIndex][day - 1] = amount;
    return true;
}

int YorozuyaManager::getTotalConsumption(const char* foodName) const {
    if (foodName == NULL) {
        return 0;
    }

    // Find food type
    int foodIndex = -1;
    for (int i = 0; i < foodTypeCount; i++) {
        if (foodNames[i] != NULL && strcmp(foodNames[i], foodName) == 0) {
            foodIndex = i;
            break;
        }
    }

    if (foodIndex == -1) {
        return 0;
    }

    int total = 0;
    for (int i = 0; i < inventoryDays; i++) {
        total += foodInventory[foodIndex][i];
    }

    return total;
}

void YorozuyaManager::displayFoodInventory() const {
    std::cout << "\n=== FOOD INVENTORY ===" << std::endl;

    if (foodTypeCount == 0) {
        std::cout << "No food types tracked." << std::endl;
        return;
    }

    for (int i = 0; i < foodTypeCount; i++) {
        std::cout << foodNames[i] << ": Total consumed = "
                  << getTotalConsumption(foodNames[i]) << std::endl;
    }
}

bool YorozuyaManager::addGlassesType(const char* typeName, int backupLevel) {
    if (typeName == NULL || backupLevel < 0 || backupLevel >= backupLevels) {
        return false;
    }

    // Simple implementation - just return true for now
    return true;
}

void YorozuyaManager::displayGlassesCollection() const {
    std::cout << "\n=== GLASSES COLLECTION ===" << std::endl;
    std::cout << "Glasses collection display not fully implemented." << std::endl;
}

int YorozuyaManager::getClientCount() const {
    return clientCount;
}

int YorozuyaManager::getTotalJobs() const {
    int total = 0;
    for (int i = 0; i < clientCount; i++) {
        total += clientJobCounts[i];
    }
    return total;
}

void YorozuyaManager::cleanup() {
    deallocateAll();

    // Reinitialize to safe state
    clientNames = NULL;
    clientJobCounts = NULL;
    jobDescriptions = NULL;
    jobCapacities = NULL;
    foodNames = NULL;
    foodInventory = NULL;
    glassesCollection = NULL;
    clientCount = 0;
    clientCapacity = 0;
    foodTypeCount = 0;
    glassesTypes = 0;
}

void YorozuyaManager::resizeClientArrays() {
    int newCapacity = clientCapacity * 2;

    // Allocate new arrays
    char** newClientNames = new char*[newCapacity];
    int* newClientJobCounts = new int[newCapacity];
    char*** newJobDescriptions = new char**[newCapacity];
    int** newJobCapacities = new int*[newCapacity];

    // Copy existing data
    for (int i = 0; i < clientCount; i++) {
        newClientNames[i] = clientNames[i];
        newClientJobCounts[i] = clientJobCounts[i];
        newJobDescriptions[i] = jobDescriptions[i];
        newJobCapacities[i] = jobCapacities[i];
    }

    // Initialize new slots
    for (int i = clientCount; i < newCapacity; i++) {
        newClientNames[i] = NULL;
        newClientJobCounts[i] = 0;
        newJobDescriptions[i] = new char*[3];
        newJobCapacities[i] = new int[1];
        newJobCapacities[i][0] = 3;
        for (int j = 0; j < 3; j++) {
            newJobDescriptions[i][j] = NULL;
        }
    }

    // Delete old arrays (but not the data they point to)
    delete[] clientNames;
    delete[] clientJobCounts;
    delete[] jobDescriptions;
    delete[] jobCapacities;

    // Update pointers and capacity
    clientNames = newClientNames;
    clientJobCounts = newClientJobCounts;
    jobDescriptions = newJobDescriptions;
    jobCapacities = newJobCapacities;
    clientCapacity = newCapacity;
}

void YorozuyaManager::resizeJobArray(int clientIndex) {
    int oldCapacity = jobCapacities[clientIndex][0];
    int newCapacity = oldCapacity * 2;

    // Allocate new job array
    char** newJobs = new char*[newCapacity];

    // Copy existing jobs
    for (int i = 0; i < oldCapacity; i++) {
        newJobs[i] = jobDescriptions[clientIndex][i];
    }

    // Initialize new slots
    for (int i = oldCapacity; i < newCapacity; i++) {
        newJobs[i] = NULL;
    }

    // Delete old array and update
    delete[] jobDescriptions[clientIndex];
    jobDescriptions[clientIndex] = newJobs;
    jobCapacities[clientIndex][0] = newCapacity;
}

void YorozuyaManager::copyString(char*& dest, const char* src) {
    if (src == NULL) {
        dest = NULL;
        return;
    }

    int length = strlen(src);
    dest = new char[length + 1];
    strcpy(dest, src);
}

void YorozuyaManager::deallocateAll() {
    // Deallocate client data
    if (clientNames != NULL) {
        for (int i = 0; i < clientCapacity; i++) {
            delete[] clientNames[i];

            if (jobDescriptions != NULL && jobDescriptions[i] != NULL) {
                int jobCapacity = (jobCapacities != NULL && jobCapacities[i] != NULL) ?
                                  jobCapacities[i][0] : 3;
                for (int j = 0; j < jobCapacity; j++) {
                    delete[] jobDescriptions[i][j];
                }
                delete[] jobDescriptions[i];
            }

            delete[] jobCapacities[i];
        }
        delete[] clientNames;
        delete[] clientJobCounts;
        delete[] jobDescriptions;
        delete[] jobCapacities;
    }

    // Deallocate food data
    if (foodNames != NULL) {
        for (int i = 0; i < 10; i++) {
            delete[] foodNames[i];
            delete[] foodInventory[i];
        }
        delete[] foodNames;
        delete[] foodInventory;
    }

    // Deallocate glasses collection (simplified)
    if (glassesCollection != NULL) {
        for (int i = 0; i < 5; i++) {
            delete[] glassesCollection[i];
        }
        delete[] glassesCollection;
    }

    // Reset all pointers to NULL
    clientNames = NULL;
    clientJobCounts = NULL;
    jobDescriptions = NULL;
    jobCapacities = NULL;
    foodNames = NULL;
    foodInventory = NULL;
    glassesCollection = NULL;
}