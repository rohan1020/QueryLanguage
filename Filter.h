//
//  Filter.h
//  QueryLanguage
//
//  Created by Rohan Raja on 08/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __QueryLanguage__Filter__
#define __QueryLanguage__Filter__

#include <stdio.h>
#include "Attribute.h"

using namespace std;

class Filter {
    
    
public:
    
    Attribute attribute;
    string operatr ;
    string operand ;
    
    Filter();
    
    Filter(Attribute pattribute, string poperatr, string poperand);
    
};

#endif /* defined(__QueryLanguage__Filter__) */
