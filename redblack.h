//
// Created by user on 12/13/2021.
//

#ifndef UNTITLED_REDBLACK_H
#define UNTITLED_REDBLACK_H
using namespace std;
#endif //UNTITLED_REDBLACK_H

struct NODE
{
    int Key;
    NODE *parent;
    char Color;
    NODE *left;
    NODE *right;
};
class rbTree
{
    NODE *root;
    NODE *q;
public :
    rbTree()
    {
        q=NULL;
        root=NULL;
    }
    void insert();
    void insertfix(NODE *);
    void leftrotate(NODE *);
    void rightrotate(NODE *);
    void del();
    NODE* successor(NODE *);
    void delfix(NODE *);
    void disp();
    void display( NODE *);
    void search();
};
void rbTree::insert()
{
    int i=0;
    std::cout<<"\nEnter key of the node to be removed: ";
    std::cin>>i;
    NODE *p,*q;
    NODE *t=new NODE;
    t->Key=i;
    t->left=NULL;
    t->right=NULL;
    t->Color='r';
    p=root;
    q=NULL;
    if(root==NULL)
    {
        root=t;
        t->parent=NULL;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(p->Key<t->Key)
                p=p->right;
            else
                p=p->left;
        }
        t->parent=q;
        if(q->Key<t->Key)
            q->right=t;
        else
            q->left=t;
    }
    insertfix(t);
}
void rbTree::insertfix(NODE *t)
{
    NODE *u;
    if(root==t)
    {
        t->Color='b';
        return;
    }
    while(t->parent!=NULL&&t->parent->Color=='r')
    {
        NODE *g=t->parent->parent;
        if(g->left==t->parent)
        {
            if(g->right!=NULL)
            {
                u=g->right;
                if(u->Color=='r')
                {
                    t->parent->Color='b';
                    u->Color='b';
                    g->Color='r';
                    t=g;
                }
            }
            else
            {
                if(t->parent->right==t)
                {
                    t=t->parent;
                    leftrotate(t);
                }
                t->parent->Color='b';
                g->Color='r';
                rightrotate(g);
            }
        }
        else
        {
            if(g->left!=NULL)
            {
                u=g->left;
                if(u->Color=='r')
                {
                    t->parent->Color='b';
                    u->Color='b';
                    g->Color='r';
                    t=g;
                }
            }
            else
            {
                if(t->parent->left==t)
                {
                    t=t->parent;
                    rightrotate(t);
                }
                t->parent->Color='b';
                g->Color='r';
                leftrotate(g);
            }
        }
        root->Color='b';
    }
}

void rbTree::del()
{
    if(root==NULL)
    {
        std::cout<<"Replace the deleted connector point's script with the this program:\n" ;
        return ;
    }
    int x;
    cout<<"Input this same code of the removed connection point: \n";
    cin>>x;
    NODE *p;
    p=root;
    NODE *y=NULL;
    NODE *q=NULL;
    int found=0;
    while(p!=NULL&&found==0)
    {
        if(p->Key==x)
            found=1;
        if(found==0)
        {
            if(p->Key<x)
                p=p->right;
            else
                p=p->left;
        }
    }
    if(found==0)
    {
        cout<<"No element found.\n.";
        return ;
    }
    else
    {
        cout<<"This component has indeed been removed.:\n"<<p->Key;
        cout<<"\nthe colour: ";
        if(p->Color=='b')
            cout<<"Black\n";
        else
            cout<<"Red\n";

        if(p->parent!=NULL)
            cout<<"The PARENT:\n "<<p->parent->Key;
        else
            cout<<"\nHere they isn't any PARENT existing in this NODE. ";
        if(p->right!=NULL)
            cout<<"\nThe right child: "<<p->right->Key;
        else
            cout<<"\nThere exist non of the parents in the child in the NODE.  ";
        if(p->left!=NULL)
            cout<<"\nThe left child: "<<p->left->Key;
        else
            cout<<"\nThere exist non of the parents in the child in the NODE.  ";
        cout<<"\nThis contains deleted node.";
        if(p->left==NULL||p->right==NULL)
            y=p;
        else
            y=successor(p);
        if(y->left!=NULL)
            q=y->left;
        else
        {
            if(y->right!=NULL)
                q=y->right;
            else
                q=NULL;
        }
        if(q!=NULL)
            q->parent=y->parent;
        if(y->parent==NULL)
            root=q;
        else
        {
            if(y==y->parent->left)
                y->parent->left=q;
            else
                y->parent->right=q;
        }
        if(y!=p)
        {
            p->Color=y->Color;
            p->Key=y->Key;
        }
        if(y->Color=='b')
            delfix(q);
    }
}

void rbTree::delfix(NODE *p)
{
    NODE *s;
    while(p!=root&&p->Color=='b')
    {
        if(p->parent->left==p)
        {
            s=p->parent->right;
            if(s->Color=='r')
            {
                s->Color='b';
                p->parent->Color='r';
                leftrotate(p->parent);
                s=p->parent->right;
            }
            if(s->right->Color=='b'&&s->left->Color=='b')
            {
                s->Color='r';
                p=p->parent;
            }
            else
            {
                if(s->right->Color=='b')
                {
                    s->left->Color=='b';
                    s->Color='r';
                    rightrotate(s);
                    s=p->parent->right;
                }
                s->Color=p->parent->Color;
                p->parent->Color='b';
                s->right->Color='b';
                leftrotate(p->parent);
                p=root;
            }
        }
        else
        {
            s=p->parent->left;
            if(s->Color=='r')
            {
                s->Color='b';
                p->parent->Color='r';
                rightrotate(p->parent);
                s=p->parent->left;
            }
            if(s->left->Color=='b'&&s->right->Color=='b')
            {
                s->Color='r';
                p=p->parent;
            }
            else
            {
                if(s->left->Color=='b')
                {
                    s->right->Color='b';
                    s->Color='r';
                    leftrotate(s);
                    s=p->parent->left;
                }
                s->Color=p->parent->Color;
                p->parent->Color='b';
                s->left->Color='b';
                rightrotate(p->parent);
                p=root;
            }
        }
        p->Color='b';
        root->Color='b';
    }
}

void rbTree::leftrotate(NODE *p)
{
    if(p->right==NULL)
        return ;
    else
    {
        NODE *y=p->right;
        if(y->left!=NULL)
        {
            p->right=y->left;
            y->left->parent=p;
        }
        else
            p->right=NULL;
        if(p->parent!=NULL)
            y->parent=p->parent;
        if(p->parent==NULL)
            root=y;
        else
        {
            if(p==p->parent->left)
                p->parent->left=y;
            else
                p->parent->right=y;
        }
        y->left=p;
        p->parent=y;
    }
}
void rbTree::rightrotate(NODE *p)
{
    if(p->left==NULL)
        return ;
    else
    {
        NODE *y=p->left;
        if(y->right!=NULL)
        {
            p->left=y->right;
            y->right->parent=p;
        }
        else
            p->left=NULL;
        if(p->parent!=NULL)
            y->parent=p->parent;
        if(p->parent==NULL)
            root=y;
        else
        {
            if(p==p->parent->left)
                p->parent->left=y;
            else
                p->parent->right=y;
        }
        y->right=p;
        p->parent=y;
    }
}

NODE* rbTree::successor(NODE *p)
{
    NODE *y=NULL;
    if(p->left!=NULL)
    {
        y=p->left;
        while(y->right!=NULL)
            y=y->right;
    }
    else
    {
        y=p->right;
        while(y->left!=NULL)
            y=y->left;
    }
    return y;
}

void rbTree::disp()
{
    display(root);
}
void rbTree::display(NODE *p)
{
    if(root==NULL)
    {
        cout<<"\nEmpty Tree.";
        return ;
    }
    if(p!=NULL)
    {
        cout<<"\n\t NODE: ";
        cout<<"\n Key: "<<p->Key;
        cout<<"\n Colour: ";
        if(p->Color=='b')
            cout<<"Black";
        else
            cout<<"Red";
        if(p->parent!=NULL)
            cout<<"\n Parent: "<<p->parent->Key;
        else
            cout<<"\n There is no parent of the node.  ";
        if(p->right!=NULL)
            cout<<"\n Right Child: "<<p->right->Key;
        else
            cout<<"\n There is no right child of the node.  ";
        if(p->left!=NULL)
            cout<<"\n Left Child: "<<p->left->Key;
        else
            cout<<"\n There is no left child of the node.  ";
        cout<<endl;
        if(p->left)
        {
            cout<<"\nLeft:\n";
            display(p->left);
        }
        /*else
         cout<<"\nNo Left Child.\n";*/
        if(p->right)
        {
            cout<<"\nRight:\n";
            display(p->right);
        }
        /*else
         cout<<"\nNo Right Child.\n"*/
    }
}
void rbTree::search()
{
    if(root==NULL)
    {
        cout<<"\nA null/empty Tree\n" ;
        return  ;
    }
    int y;
    cout<<"\n Enter key of the node to be searched: ";
    cin>>y;
    NODE *p=root;
    int Found=0;
    while(p!=NULL&& Found==0)
    {
        if(p->Key==y)
            Found=1;
        if(Found==0)
        {
            if(p->Key<y)
                p=p->right;
            else
                p=p->left;
        }
    }
    if(Found==0)
        cout<<"\nElement Not Found.";
    else
    {
        cout<<"\n\t FOUND NODE: ";
        cout<<"\n Key: "<<p->Key;
        cout<<"\n Colour: ";
        if(p->Color=='b')
            cout<<"Black";
        else
            cout<<"Red";
        if(p->parent!=NULL)
            cout<<"\n PARENT: "<<p->parent->Key;
        else
            cout<<"\n The node seems to have no PARENT.  ";
        if(p->right!=NULL)
            cout<<"\n Right Child: "<<p->right->Key;
        else
            cout<<"\n The node seems to have no right children..  ";
        if(p->left!=NULL)
            cout<<"\n Left Child: "<<p->left->Key;
        else
            cout<<"\n The node seems to have no left children.  ";
        cout<<endl;

    }
}