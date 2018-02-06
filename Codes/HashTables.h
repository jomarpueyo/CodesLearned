#include <iostream>
#include <string>

using namespace std;

class closedHash{
private:
   //string pass;
   int key;
   int value;
public:
   /*closedHash(string pass,int value){        //for testing
       for(unsigned int i=0; i<pass.size();i++)
           key+=pass[i];
       this->value=value;
       this->pass=pass;
       this->key=key
   }*/
   closedHash(int keey,int value){
       this->value=value;
       this->key=keey;
   }
   int getKey(){return key;}
   int getValue(){return value;}
};

class hashFunction{
private:
   closedHash **table;
public:
   hashFunction(){/*constructor creates new table setting all values to NULL, NOT ZERO*/
   table = new closedHash*[139];
   for(int i=0;i<139;i++)
       table[1]=NULL;
   }
   int getValue(int key){
       int index = (key%139);                                  //indexing number
       while (table[index]!=NULL&&table[index]->getKey()!=key) //if indexed is not NULL or the same key
           index = (index+1)%139;                              //reindex
       if (table[index]==NULL)
           return -1;
       else
           return table[index]->getValue();
   }
   void setValue(string pass, int value){                      //begin with converting string to ascii
       int key=0;
       for(unsigned int i=0; i<pass.size();i++)
           key+=pass[i];                                       //key is now an int
       int index = (key%139);
       while (table[index]!=NULL&&table[index]->getKey()!=key)
           index=(index+1)%139;
       if(table[index]!=NULL)
           delete table[index];
       table[index]=new closedHash(key,value);
   }
   void printAll(){
       cout<<"Index Key Value"<<endl<<endl;
       for(int i=1;i<139;i++)
           if(table[i]!=NULL)
           cout<<i<<" "<<table[i]->getKey()<<" "<<table[i]->getValue()<<endl;
   }
};

int main(){
   hashFunction hashbrowns;
   hashbrowns.setValue("John",1001);	
   hashbrowns.setValue("Bob",999);
   hashbrowns.setValue("Sue",2012);
   hashbrowns.setValue("Mary",101);
   hashbrowns.printAll();
   cout<<endl<<"2012=Sue, 1001=John, 101=Mary, 999=Bob"<<endl<<endl;
}
