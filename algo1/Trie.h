//
//  Trie.h
//  algo1
//
//  Created by Iryna on 20/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#ifndef __algo1__Trie__
#define __algo1__Trie__

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>

struct Node{
  bool isWord=false;
  int count=0;
  std::unordered_map<char,std::shared_ptr<Node>> children;
};

class Trie{
  std::shared_ptr<Node> head;
public:
  Trie():head(new Node()){}
  
  void add(std::string contact);
  
  int find(std::string contact);
};
#endif /* defined(__algo1__Trie__) */
