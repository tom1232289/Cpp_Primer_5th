#pragma once

#include <iostream>
#include "TextQuery.h"

QueryResult operator~(const QueryResult &qr);
QueryResult operator&(const QueryResult &lhs, const QueryResult &rhs);
QueryResult operator|(const QueryResult &lhs, const QueryResult &rhs);