# Throne Inheritance

Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 24, 2021
Last edited time: Feb 24, 2021 9:26 AM
Points: 1500
Status: ok

```cpp
class ThroneInheritance {
public:
    struct person
    {
        string name; 
        person *parent; 
        vector<person*> children; 
        bool dead; 
        person(string name, person *parent)
        {
            this->name = name; 
            this->parent = parent; 
            dead = false; 
        }
        person* addChild(string name)
        {
            person *ch = new person(name, this); 
            children.push_back(ch); 
            return ch; 
        }
    };
    unordered_map<string, person*> mp;
    unordered_set<person*> inOrder; 
    string king; 
    
    ThroneInheritance(string kingName) {
        mp[kingName] = new person(kingName, nullptr); 
        king = kingName; 
    }
    
    void birth(string parentName, string childName) {
        auto par = mp[parentName]; 
        mp[childName] = par->addChild(childName); 
    }
    
    void death(string name) {
        mp[name]->dead = true; 
    }
    
    void pre_order(person *p, vector<string> &ans)
    {
        if (p->dead == false) ans.push_back(p->name); 
        for (int i = 0; i < p->children.size(); i++)
        {
            pre_order(p->children[i], ans); 
        }
    }
    
    vector<string> getInheritanceOrder() {
        inOrder.clear(); 
        vector<string> ans; 
        pre_order(mp[king], ans); 
        return ans; 
    }};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
```