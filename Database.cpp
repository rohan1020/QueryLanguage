//
//  Database.cpp
//  QueryLanguage
//
//  Created by Rohan Raja on 06/04/15.
//  Copyright (c) 2015 Rohan Raja. All rights reserved.
//

#include "Database.h"

using namespace std;


Database::Database()
{
    tables.push_back(* new Table());
}