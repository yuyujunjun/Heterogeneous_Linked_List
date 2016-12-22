//
// Created by fcsx1 on 2016/12/22.
//
#include<iostream>
using namespace std;
#ifndef HETEROGENEOUSLINKEDLIST_LIST_H
#define HETEROGENEOUSLINKEDLIST_LIST_H
class node{
    friend class List;
protected:
    node *next;
public:
    node():next(NULL){}
    virtual node * create()const {}
    virtual void print(){}
};
class List{
private:node* root;
    int size;
public:
    List():root(NULL),size(0){}
    void insert(node* p,const int k);
    void add(const node* p);
    void remove(int k);
    void PrintList();
    void Clear();
    void combine(List *list2);
    void Reverse();
};
template <typename T>
class inf:public node{
private:  T data;
public:    inf<T>(T x):data(x){}
    virtual node* create()const{
        return new inf<T>(data);
    };
    virtual void print()
    {
        cout<<data<<" ";
    }

};
#endif //HETEROGENEOUSLINKEDLIST_LIST_H
