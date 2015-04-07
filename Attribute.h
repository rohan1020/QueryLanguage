//
//  Attribute.h
//  QueryLanguage
//
//  Created by Rohan Raja on 08/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#ifndef __QueryLanguage__Attribute__
#define __QueryLanguage__Attribute__

#include <stdio.h>
#include <string>

using namespace std;

class Attribute {
    
    
public:
    
    Attribute();
    
    Attribute(string pname, int pindex);
    
    string name ;
    int index;
};

#endif /* defined(__QueryLanguage__Attribute__) */
