#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char,string> &codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code;

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main() {
    string text;
    cout << "Enter the string to encode: ";
    cin >> text;

    map<char,int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq) pq.push(new Node(p.first, p.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();

    map<char,string> codes;
    generateCodes(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (auto p : codes) cout << p.first << " : " << p.second << endl;

    string encoded = "";
    for (char c : text) encoded += codes[c];

    cout << "\nEncoded String:\n" << encoded << endl;

    return 0;
}
