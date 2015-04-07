//
//  Query.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 07/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Query.h"

Query::Query()
{
    
    queryText = " SELECT * FROM customers where id > 2 ; ";
    
    tables.push_back(* new Table());
    
    projection_attributes.push_back(* new Attribute("name", 1));
    
    filters.push_back(* new Filter(* new Attribute("id", 0), 1, "0"));
    
    
}

Query::Query(string qry):queryText(qry)
{
    
}