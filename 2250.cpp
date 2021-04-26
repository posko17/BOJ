#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
class node
{
public:
    int n;
    int depth;
    node *parent;
    node *left;
    node *right;
    int order;
};

class tree
{
public:
    node *root;
};
vector<node *> ext[10001];
void in(node *, int);
void find(node *);
int n, a, b, c;
bool found;
tree *temp_tree;
node *temp_node;
list<tree *> l;
int count = 0;
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        found = false;
        temp_node = NULL;
        temp_tree = NULL;
        if (i == 0)
        {
            temp_tree = new tree;
            temp_tree->root = new node;
            temp_node = temp_tree->root;
            temp_tree->root->n = a;
            temp_tree->root->depth = 0;
            temp_tree->root->parent = NULL;
            l.push_back(temp_tree);
        }
        else
        {
            //should find some nodes that matches a
            for (list<tree *>::iterator it = l.begin(); it != l.end(); it++)
            {
                if (temp_node != NULL)
                    break;
                find((*it)->root);
            }
            if (temp_node == NULL)
            {
                //no match
                temp_tree = new tree;
                temp_tree->root = new node;
                temp_node = temp_tree->root;
                temp_tree->root->n = a;
                temp_tree->root->depth = 0;
                temp_tree->root->parent = NULL;
                l.push_back(temp_tree);
            }
        }
        //just continue when matched
        if (b == -1)
        {
            temp_node->left = NULL;
        }
        else
        {
            //need to find the root of the list l
            temp_node->left = new node;
            temp_node->left->n = b;
            temp_node->left->left = NULL;
            temp_node->left->right = NULL;
            temp_node->left->parent = temp_node;
            for (list<tree *>::iterator it = l.begin(); it != l.end(); it++)
            {
                if ((*it)->root->n == b)
                {
                    temp_node->left = (*it)->root;
                    (*it)->root->parent = temp_node;
                    l.erase(it);
                    break;
                }
            }
        }
        if (c == -1)
        {
            temp_node->right = NULL;
        }
        else
        {
            temp_node->right = new node;
            temp_node->right->n = c;
            temp_node->right->left = NULL;
            temp_node->right->right = NULL;
            temp_node->right->parent = temp_node;
            for (list<tree *>::iterator it = l.begin(); it != l.end(); it++)
            {
                if ((*it)->root->n == c)
                {
                    temp_node->right = (*it)->root;
                    (*it)->root->parent = temp_node;
                    l.erase(it);
                    break;
                }
            }
        }
    }
    if (l.size() != 1)
    {
        cout << "not merged!\n";
        return 0;
    }
    in(l.front()->root, 0);
    int max_level = -1, max_width = -1;
    for (int i = 0; i < 10000; i++)
    {
        if (ext[i].size() == 0)
            continue;
        else
        {
            if (ext[i][ext[i].size() - 1]->order - ext[i][0]->order + 1 > max_width)
            {
                max_width = ext[i][ext[i].size() - 1]->order - ext[i][0]->order + 1;
                max_level = i + 1;
            }
        }
    }
    if (max_level == -1 || max_width == -1)
    {
        cout << "width cal error\n";
    }
    else
    {
        cout << max_level << ' ' << max_width;
    }
    return 0;
}
void find(node *t)
{
    if (t == NULL || temp_node != NULL)
        return;
    if (t->n == a)
    {
        temp_node = t;
        return;
    }
    else
    {
        find(t->right);
        find(t->left);
    }
    return;
}
void in(node *cur, int d)
{
    if (cur == NULL)
        return;
    in(cur->left, d + 1);
    count++;
    cur->depth = d;
    cur->order = count;
    ext[d].push_back(cur);
    in(cur->right, d + 1);
    return;
}