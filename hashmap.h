// Simple Hash Map - Maps an unsigned int to an object pointer 
// from: http://frankforce.com/?p=3755

#ifndef _HASHMAP_H
#define _HASHMAP_H

template < struct T, unsigned maxMapSize >
struct HashMap 
{
    HashMap() { clear(); }

    void clear()
    {
        mapSize = 0;
        for (unsigned i = 0; i < maxMapSize; ++i)
        {
            map[i].key = 0;
            map[i].value = NULL;
        }
    }

    T find(unsigned key)
    {
        if (!key)
            return NULL; // invalid key always returns NULL

        // check every key until we find a match
        unsigned i = hashKey(key) % maxMapSize;
        const unsigned iStart = i;
        do
        {
            if (map[i].key == key)
                return map[i].value;
            i = (i + 1) % maxMapSize;
        }
        while (i != iStart);

        return NULL;
    }

    void insert(unsigned key, T value)
    {
        ASSERT(key && value && !full() && !find(key));

        unsigned i = hashKey(key) % maxMapSize;
        while (map[i].value)
            i = (i + 1) % maxMapSize;

        map[i].key = key;
        map[i].value = value;
        ++mapSize;
    }

    void erase(unsigned key)
    {
        ASSERT(key && find(key));

        unsigned i = hashKey(key) % maxMapSize;
        while (map[i].key != key)
            i = (i + 1) % maxMapSize;

        map[i].key = 0;
        map[i].value = NULL;
        --mapSize;
    }

    unsigned size()     const { return mapSize; }
    unsigned max_size() const { return maxMapSize; }
    bool empty()        const { return size() == 0; }
    bool full()         const { return size() == max_size(); }

private:

    // rehash the key so we make more efficient use of the map
    unsigned hashKey(unsigned key) { return key*2654435761; }

    struct HashEntry { unsigned key; T value; };
    HashEntry map[maxMapSize];
    unsigned mapSize;
};

#endif