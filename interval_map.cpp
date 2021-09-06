/**
 * @file interval_map.cpp
 * @author Ivan Mercep
 * @brief 
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <map>
#include <limits>

template<typename K, typename V>
class interval_map 
{
	std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val) into the map
    interval_map(V const& val) 
    {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign(K const& keyBegin, K const& keyEnd, V const& val) 
    {
        if( !(keyBegin < keyEnd) )
            return;
        auto l = m_map.lower_bound(keyBegin);
        auto h = m_map.upper_bound(keyEnd);
        ++h;
        if(l->second == val)
            return;
        if(h->second == val)
            return;
        for(auto i = keyBegin; i < keyEnd; i++)
            m_map[i] = val;
    }

    // look-up of the value associated with key
    V const& operator[](K const& key) const 
    {
        return ( --m_map.upper_bound(key) )->second;
    }

    void print() 
    {
        std::cout << " K -> V " << std::endl << "--------" << std::endl;
        for (const auto& kv : m_map) {
            std::cout << kv.first << " -> " << kv.second << std::endl;
        }
    }
};

int main(int argc, char** argv) 
{
    interval_map<unsigned int, char> im('A');
    im.assign(3, 5, '1');
    im.assign(6, 7, 'A');
    im.assign(7, 8, '1');

    im.print();
    std::cout << std::endl;
    
    return 0;
}
