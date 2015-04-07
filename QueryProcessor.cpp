//
//  QueryProcessor.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 07/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "QueryProcessor.h"

using namespace std;

QueryProcessor::QueryProcessor(){
 
    
    
}


Table QueryProcessor::Projection(Table table, vector<Attribute> attrs){
    
    Table t;
    t.clear();
    
    t.updateAttributes(attrs);
    
    for(int i=0; i<table.tuples.size(); i++)
    {
        vector<string> row;
        
        for(int j=0; j<attrs.size(); j++)
        {
            row.push_back(table.getCell(i, attrs[j]));
        }
        
        t.tuples.push_back(row);
    }
    
    return t;
}


Table QueryProcessor::selector(Table table, Filter filter)
{
    Table t;
    t.clear();
    
    
    return t;
}

