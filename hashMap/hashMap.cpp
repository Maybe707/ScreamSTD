#include <iostream>
#include <string>

template <typename T>
struct Node
{
    std::string key_;
    T value_;
    Node* next_ = nullptr;

    Node(const char* _key) : key_(_key) {}
};

template <typename S>
class HashMap
{
    unsigned int capacity_ = 10;

public:
    Node<S>** hashMap_ = new Node<S>*[capacity_];
    
    HashMap() {
        for (int i = 0; i < capacity_; ++i) {
            hashMap_[i] = nullptr;
        }
    }

    S& operator[](const char* _key) {
        unsigned int hash = HashFunction(_key);
        std::cout << "hash: " << hash << std::endl;
        if (hash > capacity_)
            Rehash(hash);
        
        return Link(hashMap_[hash], _key);
    }

    bool Contain(const char* _key) {
        unsigned int hash = HashFunction(_key);
        
        for (int i = 0; i < capacity_; ++i) {
            Node<S>* node = hashMap_[i];

            while(node != nullptr) {
                if (node->key_ == _key)
                    return true;
                else
                    node = node->next_;
            }
        }

        return false;
    }
    
private:
    S& Link(Node<S>*& _node, const char* _key) {
        if (_node == nullptr) {
            _node = new Node<S>(_key);
            return _node->value_;
        } else {
            if (_node->key_ == _key) {
                return _node->value_;
            }
            
            return Link(_node->next_, _key);
        }
    }
    
    unsigned int HashFunction(const char* _key) {
        unsigned int sum = 0;
        unsigned int counter   = 0;
        while (_key[counter] != '\0') {
            sum += _key[counter];
            ++counter;
        }

        unsigned int reminder = sum % capacity_;
        return reminder;
    }

    void Rehash(unsigned int _hash) {
        unsigned int reminder = _hash % 10;
        capacity_ = _hash + (10 - reminder);
        
        Node<S>** temp = new Node<S>*[capacity_];

        for (int i = 0; i < capacity_; ++i)
            temp[i] = hashMap_[i];

        delete [] hashMap_;
        hashMap_ = nullptr;
        hashMap_ = temp;
    }
};

int main(int argc, char* argv[])
{
    HashMap<int> map;
    map["rev"] = 100;
    map["rev"] = 200;
    map["rev"] = 300;
    map["rew"] = 400;
    map["hev"] = 500;

    // std::cout << map["rev"] << std::endl;
    // std::cout << map["rew"] << std::endl;
    
    // std::cout << map.hashMap_[3]->key_ << std::endl;
    // std::cout << map.hashMap_[3]->value_ << std::endl;

    std::cout << map.hashMap_[3]->key_ << std::endl;
    std::cout << map.hashMap_[3]->value_ << std::endl;

    std::cout << map.hashMap_[3]->next_->key_ << std::endl;
    std::cout << map.hashMap_[3]->next_->value_ << std::endl;

    bool flag = map.Contain("rev");

    std::cout << flag << std::endl;
    
    return 0;
}
