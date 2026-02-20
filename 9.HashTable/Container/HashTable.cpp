#include "HashTable.h"


#include <iostream>


// Hash Function.
// By some process, transform a key to a number.
// 외부 로직이 여기에 접근할 필요가 없기 때문에 cpp에서만 선언.
// "static" in here means "private."
static int GenerateHash(const std::string& keyString)
{
    // delclare a value to print.
    int hash = 0;

    // Create hash using string as a char array.
    const int length = static_cast<int> (keyString.length());
    for (int ix = 0; ix < length; ++ix)
    {
        // Logic creates hash.
        //hash += keyString[ix] * (ix + 1); // 성능이 좋지는 않음.
        hash = (hash * 31) + keyString[ix]; // Java's. Horner's method.
    }

    return std::abs(hash);
}


HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
    // Generate Hash value, and transform it into bucket index.
    int bucketIndex = GenerateHash(key) % bucketCount; // MOD.

    // Select a dynamic array to save (secondary data structure)
    std::vector<Entry>& position = table[bucketIndex];

    // Check if the duplicated key exists.
    // Sequential Search.(Sequently Search from the start to the end.)
    const int length = static_cast<int> (position.size());
    for (int ix = 0; ix < length; ++ix)
    {
        // check duplicated key.
        if (position[ix].key == key)
        {
            // return error.
            return false;
        }
    }
   
    // Add data if duplicated data is not found.
    position.emplace_back(Entry(key, value));
    return true;
}

bool HashTable::Delete(const std::string& key)
{
    // Generate Hash value, and transform it into bucket index.
    int bucketIndex = GenerateHash(key) % bucketCount; // MOD.

    // Select a dynamic array to save (secondary data structure)
    std::vector<Entry>& position = table[bucketIndex];

    // Check if the duplicated key exists.
    // Sequential Search.(Sequently Search from the start to the end.)
    const int length = static_cast<int> (position.size());
    for (int ix = 0; ix < length; ++ix)
    {
        // check duplicated key.
        if (position[ix].key == key)
        {
            // Delete the data of the duplicated key from the secondary data structure.
            position.erase(position.begin() + ix);
            return true;
        }
    }
   
    // Failed to find the data.
    return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
    // Generate Hash value, and transform it into bucket index.
    int bucketIndex = GenerateHash(key) % bucketCount; // MOD.

    // Select a dynamic array to save (secondary data structure)
    std::vector<Entry>& position = table[bucketIndex];

    // Exception Handling: if the data structrue is empty.
    if (position.size() == 0)
    {
        return false;
    }

    // Check if the duplicated key exists.
    // Sequential Search.(Sequently Search from the start to the end.)
    const int length = static_cast<int> (position.size());
    for (int ix = 0; ix < length; ++ix)
    {
        // check duplicated key.
        if (position[ix].key == key)
        {
            // Delete the data of the duplicated key from the secondary data structure.
            outEntry = position[ix];
            return true;
        }
    }

    // Failed to search to find the data.
    return false;
}

// 출력.
void HashTable::Print()
{
    // Print all data.
    for (const auto& container : table)
    {
        // if the container has no data: continue.
        if (container.size() == 0)
        {
            continue;
        }

        // if the container has data: print all.
        for (const auto& item : container)
        {
            std::cout
                << "Key: " << item.key
                << "| Value: " << item.value
                << "\n";
        }
    }
}

// Getter.
bool HashTable::IsEmpty() const
{
    // Check if the entire secondary data structures have no data.
    int sum = 0;
    for (const auto& container : table)
    {
        // Add the secondary data structures' data count.
        sum += static_cast<int>(container.size());
    }

    // Compare the sum is zero.
    return sum == 0;
}