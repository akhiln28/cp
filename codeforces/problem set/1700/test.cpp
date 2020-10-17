#include <iostream> 

using namespace std;
class human {
    private:
    int public_var;
    int public_method()
    {
        cout << "human method" << endl;
    }
    protected: 
    int protected_method()
    {
        cout << "protected method" << endl;
    }
};

class person : public human {
    int call_protected()
    {
        protected_method();
    }
};

int main() {
    void *p = malloc(16); 
    free(p); 
    free(p); 
}