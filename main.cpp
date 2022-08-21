#include <iostream>
#include <list>

using namespace std;

//generally Hash Table is array of linked lists
//we hash the item to get its index in th array, then put in the linked list of that index

//this is unordered map built by hash table
//if we use single value not a pair, it will be unordered set

class HashT
{
private:
    int buckets;
    list<pair<string, int>>* table;

    int hashFunction(string s)  //O(1)
    {
        int hashValue = 0;
        for(size_t i = 0; i < s.size(); i++)
            hashValue += s[i];

        hashValue = hashValue % buckets;
        return hashValue;
    }

public:
    HashT(int x)     //O(1)
    {
        buckets = x;
        table = new list<pair<string, int>>[buckets];
    }

    void add(string s, int val)    //O(1)
    {
        int index = hashFunction(s);

        for(auto i:table[index])
            if(i.first == s)
                return;

        table[index].push_back(make_pair(s, val));
    }


    int getValue(string s)       //O(1)
    {
        int index = hashFunction(s);

        for(auto i:table[index])
        {
            if(i.first == s)
            {
                cout << i.second;
                return i.second;
            }
        }
        cout << "no such key!\n";
        return -1;
    }


    void traverse()     //O(n)
    {
        for(int i = 0; i < buckets; i++)
        {
            //if(!table[i].empty())
            cout << "bucket no: " << i << " ";
            for(auto x:table[i])
                cout << x.first << ":" << x.second << " =>";
            cout << "\n";
        }
    }

    /*
    void deletion(string s)
    {
        int index = hashFunction(s);
        if(table[index].empty())
            return;

        for(auto i:table[index])
        {
            if(i.first == s)
            {
                table[index].remove(make_pair(i.first, i.second));
            }
        }
    }
    */
};
//--------------------------------------------------//

const int buckets = 10;

class HashTable
{
private:
    list<string> table[buckets];
    int hashFunction(string s)
    {
        int hashValue = 0;
        for(size_t i = 0; i < s.size(); i++)
            hashValue += s[i];
        return hashValue % buckets;
    }
public:
    void addItem(string n)
    {
        int index = hashFunction(n);
        table[index].push_back(n);
    }

    void removeItem(string x)
    {
        int index = hashFunction(x);
        table[index].remove(x);
    }

    void display()
    {
        for(int i = 0; i < buckets; i++)
        {
            cout << "bucket: " << i << " ";
            for(auto x:table[i])
                cout << x << " => ";
            cout << "\n";
        }
    }
};

int main()
{
    HashT ht(10);
    ht.add("grapes", 12);
    ht.add("peach", 10);
    ht.add("apple", 15);
    ht.add("banana", 20);
    ht.add("grapes", 24);
    ht.add("Grapes", 7);
    ht.add("orange", 4);

    ht.traverse();
    cout << "\n \n";

    HashTable hat;
    hat.addItem("ahmed");
    hat.addItem("wael");
    hat.addItem("maher");
    hat.addItem("malek");
    hat.addItem("tamer");
    hat.addItem("ahmed");

    hat.display();
    cout << "\n";

    hat.removeItem("maher");
    hat.display();


    return 0;
}
