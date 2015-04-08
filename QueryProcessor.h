//
//  QueryProcessor.h
//  QueryLanguage
//
//  Created by Rohan Raja on 07/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __QueryLanguage__QueryProcessor__
#define __QueryLanguage__QueryProcessor__

#include <stdio.h>
#include "Database.h"
#include "Query.h"
#include "Filter.h"

using namespace std;

class QueryProcessor {
    
    
public:
    
    QueryProcessor();
    
    Table Projection(Table table, vector<Attribute> attrs);
    
    Table selector(Table table, Filter filter);
    
    Table unionTables(Table t1, Table t2);
    
    Table diffTables(Table t1, Table t2);
    
    Table crossProductTables(Table t1, Table t2);
    
    Table query(Query qry);
    
    Table selectQuery(Query qry);
    
    Table unionQuery(Query qry) ;
    
    Table diffQuery(Query qry) ;
    
    Table crossQuery(Query qry) ;
};

#endif /* defined(__QueryLanguage__QueryProcessor__) */
