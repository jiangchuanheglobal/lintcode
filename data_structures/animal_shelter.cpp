class Animal {
  public:
  Animal(string name, int type) {
      this->name = name;
      this->type = type;
  }
  string name;
  int type;
};

class AnimalShelter {
public:
    AnimalShelter() {
        // do initialization if necessary
    }

    /**
     * @param name a string
     * @param type an integer, 1 if Animal is dog or 0
     * @return void
     */
    void enqueue(string &name, int type) {
        // Write your code here
        deq.push_back(Animal(name, type));
    }

    string dequeueAny() {
        // Write your code here
        Animal first = deq.front();
        deq.pop_front();
        return first.name;
    }

    string dequeueDog() {
        // Write your code here
        while (deq.front().type != 1) {
            stk.push(deq.front());
            deq.pop_front();
        }
        Animal dog = deq.front();
        deq.pop_front();
        
        while (!stk.empty()) {
            deq.push_front(stk.top());
            stk.pop();
        }
        
        return dog.name;
    }
    
    string dequeueCat() {
        // Write your code here
        while (deq.front().type != 0) {
            stk.push(deq.front());
            deq.pop_front();
        }
        Animal cat = deq.front();
        deq.pop_front();
        
        while (!stk.empty()) {
            deq.push_front(stk.top());
            stk.pop();
        }
        
        return cat.name;
    }
    
    stack<Animal> stk;
    deque<Animal> deq;
};

