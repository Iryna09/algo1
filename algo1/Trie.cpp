//
//  Trie.cpp
//  algo1
//
//  Created by Iryna on 20/04/2018.
//  Copyright (c) 2018 Iryna. All rights reserved.
//

#include "Trie.h"

void Trie::add(std::string contact){
  std::shared_ptr<Node> cur(head);
  for(char c: contact){
    if(cur->children.find(c) == cur->children.end()){
      std::shared_ptr<Node> next (new Node());
      cur->children.insert({c,next});
      cur = next;
    }
    else
      cur = cur->children[c];
    cur->count++;
  }
}

int Trie::find(std::string contact){
  std::shared_ptr<Node> cur (head);
  for(char c: contact){
    if(cur->children.find(c) != cur->children.end())
      cur = cur->children[c];
      else
        return 0;
  }
  return cur->count;
}