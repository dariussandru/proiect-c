#include <cassert>
#include <iostream>

#include "Tests.h"
#include "TAD/MultiDictionary.h"
#include "Set.h"

void test_multi_dictionary() {
    MultiDictionary<int, int> multi_dictionary;

    multi_dictionary.add(1, 1);
    assert(multi_dictionary.get(1)[0] == 1);

    multi_dictionary.add(1, 2);
    assert(multi_dictionary.get(1)[0] == 2);
    assert(multi_dictionary.get(1)[1] == 1);

    assert(multi_dictionary.get(2) == std::vector<int>());

    multi_dictionary.deletee(1, 1);
    assert(multi_dictionary.get(1)[0] == 2);

    multi_dictionary.deletee(1);
    assert(multi_dictionary.get(1) == std::vector<int>());


}


void test_set() {
    Set<int> set;

    set.add(1);
    assert(set.contains(1));

    set.add(2);
    assert(set.contains(2));

    set.add(1);
    assert(set.contains(1));

    set.remove(5);
    assert(!set.contains(5));

    set.remove(1);
    assert(!set.contains(1));

    assert(set.size() == 1);

}

void tests() {
    test_multi_dictionary();
    test_set();

}
