#include <iostream>
#include "List.h"
void List::add(const node *p)  {
    node *current_node=root;
    size++;
    if(current_node==NULL)
    {
        //p->create();
        root=p->create();
    }
    else{
        while(current_node->next!=NULL)
        {
            current_node=current_node->next;
        }
        p->create();
        current_node->next=p->create();
    }

}
void List::Clear() {
    while(size>0)
    {
        remove(0);
    }
}
void List::Reverse() {
        if(root==NULL||root->next==NULL);
    else {

            node* a = root;
            node* b = a->next;
            node* p = a;
            while (b != NULL) {
                a->next = b->next;
                b->next = p;
                p = b;
                b = a->next;
            }
            a->next = NULL;
            root = p;
        }
}
void List::insert(node *p, const int k) {
    if(k>size||k<0)cout<<"************ list don't have enough nodes. ************"<<endl;
    else if(k==0){
        node *temp=p->create();
        temp->next=root;
        root=temp;
        size++;
    }else{
        size++;
        int id=0;
        node *current_node=root;
        node *previous_node=root;
        for(id=0;current_node&&id<k;id++,current_node=current_node->next)
        {
            previous_node=current_node;
        }
        node *temp=p->create();
        previous_node->next=temp;
        temp->next=current_node;
    }
}
void List::remove(int k) {
    if(k>size||k<0)cout<<"************list don't have enough nodes************"<<endl;
    else if(k==0)
    {
        node *tmp=root;
        root=root->next;
        delete(tmp);
        size--;
    }else
    {
        int id=0;
        node *current_node=root;
        node *previous_node=root;
        for(;current_node&&id<k;id++,current_node=current_node->next)
        {
            previous_node=current_node;
        }
        previous_node->next=current_node->next;
        size--;
        delete(current_node);
    }
}
void List::combine(List *list2) {
    node *current_node=root;
    if(current_node==NULL) {
        root = list2->root;

    }else
    {
        for(;current_node->next; current_node=current_node->next);
        current_node->next=list2->root;
    }
}
void List::PrintList() {
    node *current_node=root;
    if(current_node==NULL)cout<<"there isn't any node"<<endl;
    else {
        while (current_node->next) {
            current_node->print();
            cout << "->" ;
            current_node = current_node->next;
        }
        current_node->print();
        cout << endl;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    List a,b;
    inf<double> t(1);
    a.add(&t);
    inf<int> t1(2);
    a.add(&t1);

    b.add(&t);
    a.add(&t);
    b.add(&t);
    a.add(&t);
    a.add(&t);
    a.PrintList();
    b.insert(&t1,2);
    a.PrintList();
    a.insert(&t1,7);
    a.PrintList();
    a.remove(0);
    a.PrintList();
    a.Reverse();
    a.PrintList();
    b.PrintList();
    a.combine(&b);
    a.PrintList();
    return 0;
}