//
//  Query.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 07/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Query.h"
#include <sstream>
#include <algorithm>

vector<string> createListofStrings(string line)
{
    vector<string> listOfStrings ;
    
    int i = 0;
    stringstream ssin(line);
    while (ssin.good()){
        
        string tmp ;
        ssin >> tmp;
        
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        listOfStrings.push_back(tmp);
    }
    
    listOfStrings.push_back(";");
    
    return listOfStrings ;
    
}

Query::Query()
{
    
    queryText = " SELECT name , id FROM customers where name > 2 ; ";
    
    tables.push_back(* new Table());
    
    projection_attributes.push_back(* new Attribute("name", 1));
    
    filters.push_back(* new Filter(* new Attribute("id", 0), 1, "2"));
    
    //parseString(queryText);
    
}

Filter getFilter(vector<string> filts, Table t)
{
    string oprt = filts[1];
    int opVal = 0;
    
    if(oprt == "=")
        opVal = 0;
    if(oprt == ">")
        opVal = 1;
    if(oprt == "<")
        opVal = 2;
    
    Attribute attr(filts[0], t.getAttrIdx(filts[0])) ;
    
    return * new Filter(attr, opVal, filts[2]) ;
}

void Query::parseString(string str)
{
    
    vector<string> listOfWords = createListofStrings(str);
    
    vector<string> proj_attrs ;
    vector<string> tables_str ;
    
    vector<string> filter_str ;
    
    
    for(int i = 0; i < listOfWords.size(); i++){
        
        
        
        if(listOfWords[i] == "select")
        {
            while(listOfWords[i+1] != "from")
            {
                i++;
                if(listOfWords[i] != ",")
                    proj_attrs.push_back(listOfWords[i]);
            }
            
        }
        
        if(listOfWords[i] == "from")
        {
            
            while(listOfWords[i+1] != "where" and listOfWords[i+1] != ";")
            {
                i++;
                if(listOfWords[i] != ",")
                    tables_str.push_back(listOfWords[i]);
            }
            
        }
        
        if(listOfWords[i] == "where")
        {
            
            while(listOfWords[i+1] != "and" and listOfWords[i+1] != "or" and listOfWords[i+1] != ";")
            {
                i++;
                if(listOfWords[i] != ",")
                    filter_str.push_back(listOfWords[i]);
            }
            
        }
        
        
        
        
    }
    
    
    tables.push_back(* new Table());
    
    
    if(filter_str.size() > 0)
    {
        Filter f = getFilter(filter_str, tables[0]);
    
        filters.push_back(f);
    }
    
    if(proj_attrs[0] == "*")
        proj_attrs = tables[0].attributes ;
    
    for(int i=0; i<proj_attrs.size(); i++)
    {
        projection_attributes.push_back(* new Attribute(proj_attrs[i], tables[0].getAttrIdx(proj_attrs[i])));
    }
    
    
    
}


Query::Query(string qry):queryText(qry)
{
    parseString(queryText);
    
}
