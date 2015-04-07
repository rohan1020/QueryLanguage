//
//  Query.h
//  QueryLanguage
//
//  Created by Rohan Raja on 08/04/14.
//  Copyright (c) 2015 All rights reserved.
//

#ifndef __QueryLanguage__Query__
#define __QueryLanguage__Query__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Table.h"
#include "Filter.h"

using namespace std;

class Query {
    
    string queryText ;
    
public:
    
    int type ; // SELECT or INSERT
    
    vector<Attribute> projection_attributes ;
    vector<Table> tables;
    vector<Filter> filters;
    vector<int> filter_joints ; // with AND or OR
    
    Query();
    
    Query(string qry);
    
};
#endif /* defined(__QueryLanguage__Query__) */
