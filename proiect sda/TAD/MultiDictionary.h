#ifndef MULTIDICTIONARY_H
#define MULTIDICTIONARY_H


#include <vector>
#include "iostream"
using namespace std;

template<class T, class U>class MultiDictionary {
private:
    struct ListNode {
        U value;
        ListNode* next;
    };

    struct DictNode {
        T key;
        ListNode* value;
        DictNode* next;
    };

    DictNode* searchAddress(T key);
public:
    MultiDictionary();
    ~MultiDictionary();

    void add(T key, U value);
    vector<U> deletee(T key);
    void deletee(T key, U value);
    vector<U> get(T key);
    bool contains(T key, U value);


private:
    DictNode* head;
};

template<class T, class U>typename MultiDictionary<T, U>::DictNode* MultiDictionary<T, U>::searchAddress(T key) {
    DictNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T, class U>MultiDictionary<T, U>::MultiDictionary()
        : head(nullptr)
{}

template<class T, class U> MultiDictionary<T, U>::~MultiDictionary()
{
    DictNode* curr = head;
    while (curr != nullptr) {
        DictNode* next = curr->next;
        delete curr->value;
        delete curr;
        curr = next;
    }
}

template<class T, class U>void MultiDictionary<T, U>::add(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        DictNode* newNode = new DictNode;
        newNode->key = key;
        newNode->value = new ListNode;
        newNode->value->value = value;
        newNode->value->next = nullptr;
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* newNode = new ListNode;
        newNode->value = value;
        newNode->next = current->value;
        current->value = newNode;
    }
}

template<class T, class U>std::vector<U> MultiDictionary<T, U>::deletee(T key) {
    vector<U> values;
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return values;
    }
    else {
        ListNode* prev = nullptr;
        ListNode* curr = current->value;
        while (curr != nullptr) {
            values.push_back(curr->value);
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    if (current->next == nullptr) {
        delete current;
        head = nullptr;
    }

    return values;
}

template<class T, class U>void MultiDictionary<T, U>::deletee(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return;
    }
    else {
        ListNode* curr = current->value;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->value == value) {
                if (prev == nullptr) {
                    current->value = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

template<class T, class U>vector<U> MultiDictionary<T, U>::get(T key) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return std::vector<U>();
    }
    else {
        ListNode* curr = current->value;
        vector<U> result;
        while (curr != nullptr) {
            result.push_back(curr->value);
            curr = curr->next;
        }

        return result;
    }
}


template<class T, class U>bool MultiDictionary<T, U>::contains(T key, U value) {
    DictNode* currentAddres = searchAddress(key);
    if (currentAddres == nullptr)
    {
        return false;
    }
    else {
        ListNode* currnet = currentAddres->value;
        while (currnet != nullptr)
        {
            if (currnet->value == value)
            {
                return true;
            }
            currnet = currnet->next;
        }
        return false;
    }
}



#endif // MULTIDICTIONARY_H

