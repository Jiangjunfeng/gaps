/* Include file for the GAPS map class */

#ifndef __RN__MAP__H__
#define __RN__MAP__H__



/* Dependency include files */

#include <string>
#include <map>



/* Library initialization functions */

int RNInitMap();
void RNStopMap();



/* Support class  */

template <class KeyType>
struct RNMapComparator {
    public:
        RNMapComparator(int (*compare_function)(KeyType, KeyType) = NULL) : compare_function(compare_function) {};
        bool operator()(KeyType a, KeyType b) {
            if (compare_function) { return ((*compare_function)(a, b) < 0) ? true: false; }
            else { return a < b; }
        };
    private:
        int (*compare_function)(KeyType, KeyType);  
};



/* Class definition */

template <class KeyType, class ValueType>
class RNMap {
    public:
        // Constructor/destructor functions
        RNMap(void);
        RNMap(int (*compare)(KeyType, KeyType));
        RNMap(const RNMap<KeyType,ValueType>& map);
        ~RNMap(void);

        // Property functions/operations
        int NEntries(void) const;
  
        // Data access functions/operators
        ValueType Value(KeyType key) const;
        ValueType Find(KeyType key) const { return Value(key); };

        // Manipulation functions/operators
        void Empty(void);
        void Insert(KeyType key, ValueType value);
        void Replace(KeyType key, ValueType value);
        void Remove(KeyType key);

    private:
        std::map<KeyType, ValueType, RNMapComparator<KeyType> > *m;
};




/* Templated member functions */

#include "RNMap.I"



/* A useful derived class definition */

template <class ValueType>
class RNSymbolTable : public RNMap<std::string, ValueType> {
    public:
        // Constructor/destructor functions
        RNSymbolTable(void) : RNMap<std::string, ValueType>() {};
};



#endif





