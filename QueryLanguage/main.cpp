#include <iostream>

#include "Table.h"
#include "QueryProcessor.h"


using namespace std;

int main()
{
    Table t;
    
    cout << "\nThe given table is : \n\n" ;
    t.print();
    
    cout << "\n\nPlease enter your SQL query : " ;
    
    QueryProcessor qp ;
    
    string qrytt ;
    
    getline (cin,qrytt);
    
    Query q(qrytt) ;
    
    Table t2 = qp.query(q);
    
    cout << "\nThe query result is : \n\n" ;
    
    t2.print();
    
    cout << "\n\nThank You\n\n";
}
