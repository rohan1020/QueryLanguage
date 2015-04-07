//
//  main.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 06/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include <iostream>
#include "Table.h"
#include "QueryProcessor.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Table t;
    
    
    t.print();
    
    QueryProcessor qp ;
    vector<Attribute> atrs ;
        
    atrs.push_back(* new Attribute("id", 0));
    
    Table t2 = qp.Projection(t, atrs);
    
    cout <<"\n\n";
    
    t2.print();
    
    cout << "\n";
}
