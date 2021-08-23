#include <bits/stdc++.h>
using namespace std;
struct trie
{
    char val;
    int end = 0;
    trie *child[26] = {nullptr};
    int count = 0;

    void addEl(string s, trie *root)
    {
        for (char x : s)
        {
            int i = x - 'a';
            if (!root->child[i])
            {
                trie *newN = new trie();
                root->child[i] = newN;
                newN->val = x;
            }
            root->child[i]->count++;
            root = root->child[i];
        }
        root->end++;
    }
    bool search(string s, trie *root)
    {
        for (char x : s)
        {
            int i = x - 'a';
            if (!root->child[i])
                return false;
            root = root->child[i];
        }
        if (root->end > 0)
            return true;
        return false;
    }
    void deleteEl(string s, trie *root)
    {
        trie *curr = root;
        for (char x : s)
        {
            int i = x - 'a';
            if (!curr->child[i] || curr->child[i]->count <= 0)
            {
                cout << "\nNo such Element Present";
                return;
            }
            curr = curr->child[i];
        }
        if (curr->end <= 0)
        {
            cout << "\nNo such Element Present";
            return;
        }
        for (char x : s)
        {
            int i = x - 'a';
            root->child[i]->count--;
            root = root->child[i];
        }
        root->end--;
    }
    bool prefix(string s, trie *root)
    {
        for (char x : s)
        {
            int i = x - 'a';
            if (!root->child[i] || root->child[i]->count == 0)
                return false;
            root = root->child[i];
        }
        return (root->count > 0);
    }
};
int main()
{
    trie *root = new trie();
    root->val = '/';
    root->addEl("asd", root);
    cout << root->prefix("as", root);
    cout << endl
         << root->search("asd", root);
    root->deleteEl("asd", root);
    cout << endl
         << root->prefix("as", root);
    cout << endl
         << root->search("asd", root);
    root->addEl("asdp", root);
    cout << endl
         << root->prefix("as", root);
    cout << endl
         << root->search("asd", root);
    cout << endl
         << root->prefix("asdp", root);
    cout << endl
         << root->search("asdp", root);

    return 0;
}
