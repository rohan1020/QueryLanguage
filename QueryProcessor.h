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
    
    Query query;
    
public:
    
    QueryProcessor();
    
    Table Projection(Table table, vector<Attribute> attrs);
    
    Table selector(Table table, Filter filter);
};

#endif /* defined(__QueryLanguage__QueryProcessor__) */
