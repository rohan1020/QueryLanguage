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


bool check_row(Table &table, int row, Filter &filter)
{
 
    string op1 = table.getCell(row, filter.attribute);
    string op2 = filter.operand;
    
    int op1_int, op2_int ;
    
    switch (filter.operatr) {
            
        case 0: // for '='
            return op1 == op2 ;
            break;
            
        case 1: // for '>'
            
            op1_int = stoi(op1);
            op2_int = stoi(op2);
            
            return op1_int > op2_int ;
            
            break;
        
        case 2: // for '<'
            
            op1_int = stoi(op1);
            op2_int = stoi(op2);
            
            return op1_int < op2_int ;
            
            break;
            
            
        default:
            break;
    }
    
    return false;
}

Table QueryProcessor::selector(Table table, Filter filter)
{
    Table t;
    t.clear();
    
    t.updateAttributes(table.attrs);
    
    for(int i=0 ; i < table.tuples.size(); i++)
    {
        if(check_row(table, i,  filter))
            t.tuples.push_back(table.tuples[i]);
    }
    
    
    return t;
}

Table QueryProcessor::query(Query qry)
{
    vector<Table> filtered_tables ;
    
    Table curTable = qry.tables[0];
    
    for (int i=0; i<qry.filters.size(); i++) {
        
        filtered_tables.push_back(selector(curTable, qry.filters[i]));
    }
    
    if(filtered_tables.size()>0)
    {
        curTable = filtered_tables[0] ;
    }
    
    return Projection(curTable, qry.projection_attributes);
}