//
//  QueryProcessor.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 07/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "QueryProcessor.h"
#include <string>
#include <stdlib.h>
#include <algorithm>

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
            
            transform(op1.begin(), op1.end(), op1.begin(), ::tolower);
            transform(op2.begin(), op2.end(), op2.begin(), ::tolower);
            return op1 == op2 ;
            break;
            
        case 1: // for '>'
            
            op1_int = atoi(op1.c_str());
            op2_int = atoi(op2.c_str());
            
            return op1_int > op2_int ;
            
            break;
            
        case 2: // for '<'
            
            op1_int = atoi(op1.c_str());
            op2_int = atoi(op2.c_str());
            
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

Table QueryProcessor::selectQuery(Query qry)
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


Table QueryProcessor::unionQuery(Query qry)
{
    return unionTables(qry.tables[0], qry.tables[1]);
}

Table QueryProcessor::diffQuery(Query qry)
{
    return diffTables(qry.tables[0], qry.tables[1]);
}

Table QueryProcessor::query(Query qry)
{
    switch (qry.qry_type) {
            
        case 0:
            return selectQuery(qry);
            break;
            
        case 1:
            return unionQuery(qry);
            break;
        
        case 2:
            return diffQuery(qry);
            break;
            
        default:
            break;
    }
    return selectQuery(qry);
}

bool checkEqualRow(vector<string> r1, vector<string> r2)
{
    if(r1.size() != r2.size())
        return false;
    
    for(int i=0; i<r1.size(); i++)
    {
        if(r1[i] != r2[i])
            return false;
    }
    
    return true ;
}

bool checkRowinTable(Table t, vector<string> row)
{
    for(int j=0; j <t.tuples.size(); j++)
    {
        if(checkEqualRow(t.tuples[j], row))
            return true ;
    }
    
    return false;
}

Table QueryProcessor::unionTables(Table t1, Table t2)
{
    Table t ;
    t.clear();
    
    t = t1;
    
    for(int i =0; i< t2.tuples.size(); i++)
    {
        if(! checkRowinTable(t,t2.tuples[i]))
            t.tuples.push_back(t2.tuples[i]);
            
    }
    
    return t;
}

Table QueryProcessor::diffTables(Table t1, Table t2)
{
    Table t ;
    t.clear();
    
    t = t1;
    t.tuples.clear();
    
    for(int i =0; i< t1.tuples.size(); i++)
    {
        if(!checkRowinTable(t2,t1.tuples[i]))
            t.tuples.push_back(t1.tuples[i]);
        
    }
    
    return t;
}


Table QueryProcessor::crossProductTables(Table t1, Table t2)
{
    Table t ;
    t.clear();
    
    t = t1;
    t.tuples.clear();
    
    for(int i =0; i< t1.tuples.size(); i++)
    {
        if(!checkRowinTable(t2,t1.tuples[i]))
            t.tuples.push_back(t1.tuples[i]);
        
    }
    
    return t;
}
