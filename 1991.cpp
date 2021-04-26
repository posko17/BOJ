#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class node
{
public:
    char n;
    int depth;
    node *parent;
    node *left;
    node *right;
};
class tree
{
public:
    node *root;
    vector<node *> v[26];
};
void pre(node *);
void post(node *);
void in(node *);

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n;
    char a, b, c;
    cin >> n;
    tree t;
    node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        temp = NULL;
        if (i == 0)
        {
            t.root = new node;
            temp = t.root;
            t.root->depth = 0;
            t.root->parent = NULL;
            t.root->n = a;
            t.v[t.root->depth].push_back(t.root);
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                //find a
                for (int k = 0; k < t.v[j].size(); k++)
                {
                    if (t.v[j][k]->n == a)
                    {
                        temp = t.v[j][k];
                        break;
                    }
                }
                if (temp != NULL)
                    break;
            }
        }
        if (temp == NULL)
        {
            cout << "no matching error\n";
            cout << a << ' ' << b << ' ' << c;
            return 0;
        }
        //insert b and c
        if (b == '.')
        {
            temp->left = NULL;
        }
        else
        {
            temp->left = new node;
            temp->left->parent = temp;
            temp->left->depth = temp->depth + 1;
            temp->left->n = b;
            temp->left->left = NULL;
            temp->left->right = NULL;
            t.v[temp->left->depth].push_back(temp->left);
        }
        if (c == '.')
        {
            temp->right = NULL;
        }
        else
        {
            temp->right = new node;
            temp->right->parent = temp;
            temp->right->depth = temp->depth + 1;
            temp->right->n = c;
            temp->right->left = NULL;
            temp->right->right = NULL;
            t.v[temp->right->depth].push_back(temp->right);
        }
    }
    //pre
    pre(t.root);
    cout << '\n';
    //in
    in(t.root);
    cout << '\n';
    //post
    post(t.root);
    return 0;
}
void pre(node *cur)
{
    if (cur == NULL)
        return;
    cout << cur->n;
    pre(cur->left);
    pre(cur->right);
    return;
}
void in(node *cur)
{
    if (cur == NULL)
        return;
    in(cur->left);
    cout << cur->n;
    in(cur->right);
    return;
}
void post(node *cur)
{
    if (cur == NULL)
        return;
    post(cur->left);
    post(cur->right);
    cout << cur->n;
    return;
}