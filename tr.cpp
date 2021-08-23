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
};
int main()
{
    trie *root = new trie();
    root->val = '/';
    root->addEl("asd", root);
    root->addEl("asda", root);
    root->addEl("asdaz", root);

    cout << root->search("asda", root);

    cout << root->search("asd1", root);
    root->deleteEl("asdpz", root);
    cout << "\n";
    cout << root->search("asdz", root);
    cout << endl
         << root->search("asd", root);
    root->deleteEl("asd", root);
    cout << endl
         << root->search("asd", root);
    cout << endl
         << root->search("asda", root);
    root->deleteEl("asda", root);
    cout << endl
         << root->search("asda", root);
    cout << endl
         << root->search("asdaz", root);
    root->deleteEl("asdaz", root);
    cout << endl
         << root->search("asda", root);

    return 0;
}