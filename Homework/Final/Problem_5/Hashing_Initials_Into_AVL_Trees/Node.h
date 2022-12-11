/* 
 * File:   Node.h
 * Author: Aamir Khan
 * Created: Dec. 10, 2022, 3:15 PM
 */

#ifndef NODE_H
#define NODE_H

//String Library.
#include <string>
using namespace std;

struct Node{
    //Our data.
    string data;
    //Our left child.
    Node *left;
    //Our right child.
    Node *right;
};

#endif /* NODE_H */

