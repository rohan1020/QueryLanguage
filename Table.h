//
//  Table.h
//  QueryLanguage
//
//  Created by Rohan Raja on 06/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __QueryLanguage__Table__
#define __QueryLanguage__Table__

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Attribute.h"

using namespace std ;


class Table {
    
    public:
    
    vector<string> attributes ;
    vector<vector<string> > tuples;
    
    vector < Attribute > attrs ;
    
    Table();
    
    void print();
    
    void clear();
    
    void updateAttributes(vector<Attribute> pattrs);
    
    string getCell(int row, Attribute attribute);
    
};

#endif /* defined(__QueryLanguage__Table__) */
