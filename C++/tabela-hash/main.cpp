#include<iostream> 
#include <list> 
using namespace std; 
  
class Hash 
{ 
    int No;    // No. of Nos 
  
    list<int> *tabela; 
public: 
    Hash(int V);
   
    void insert(int x); 
  
    int index(int x) { 
        return (x % No); 
    } 
  
    void print(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->No = b; 
    tabela = new list<int>[No]; 
} 
  
void Hash::insert(int key) 
{ 
    int index = this->index(key); 
    tabela[index].push_back(key);  
} 

  
void Hash::print() { 
  for (int i = 0; i < No; i++) { 
    cout << i; 
    for (auto x : tabela[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 
  
 
int main() 
{ 
 
  int a[] = {12, 5, 78, 0, 7}; 
  int n = sizeof(a)/sizeof(a[0]); 
  

  Hash h(7); 

  for (int i = 0; i < n; i++)  
    h.insert(a[i]);   
  
  h.print(); 
  
  return 0; 
} 