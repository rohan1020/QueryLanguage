//
//  Database.h
//  QueryLanguage
//
//  Created by Rohan Raja on 06/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __QueryLanguage__Database__
#define __QueryLanguage__Database__

#include <stdio.h>
#include "Table.h"

using namespace std;

class Database {
    
    vector<Table> tables ;
    
    
public:
    
    Database();
    
};
#endif /* defined(__QueryLanguage__Database__) */
