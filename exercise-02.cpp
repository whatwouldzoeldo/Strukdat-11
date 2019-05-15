#include <iostream>
using namespace std;

struct simpul {
    int info;
    simpul* left;
    simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void CreateSimpul (pointer& pBaru) {
    pBaru = new simpul;
    cout << "Masukkan angka : ";
    cin >> pBaru -> info;
    pBaru -> left = NULL;
    pBaru -> right = NULL;
}

void insertBST (tree& root, pointer pBaru) {
    if (root == NULL)
        root = pBaru;
    else if (pBaru -> info < root -> info)
        insertBST (root -> left,pBaru);
    else if (pBaru -> info >= root -> info)
        insertBST (root -> right,pBaru);
    else
        cout<<"Sudah ada";
}

void preOrder (tree Root) {
    if (Root != NULL){
        cout<< Root->info<<" "<<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info<<" "<<endl;
        inOrder(Root->right);
    }
}

void postOrder (tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info<<" "<<endl;

    }
}

int height (tree Root) {
    if (Root==NULL) return 0;
    else {
        int lHeight=height(Root->left);
        int rHeight=height(Root->right);

    if (lHeight>rHeight) return (lHeight+1);
    else return (rHeight+1);
    }
}

void givenLevel (tree Root, int level) {
    if (Root==NULL)
        return;
    if (level==1)
        cout<<Root->info<<" ";
    else if (level>1) {
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void depth (tree Root) {
    int h=height(Root);
    for (int i=1;i<=h;i++) {
        cout<<i-1<<": "<<" [ ";
        givenLevel(Root,i);
        cout<<"]"<<endl;
    }
}

void levelOrder (tree Root) {
    int h=height(Root);
    for (int i=1;i<=h;i++) {
        cout<<i<<": "<<" [ ";
        givenLevel(Root,i);
        cout<<"]"<<endl;
    }
}

void child (tree Root, pointer pBaru) {
    pBaru=Root;
    if (pBaru!=NULL) {
        cout<<"Parent node = "<<pBaru->info<<endl;

        if (pBaru->left==NULL)
            cout<<"Left child = NULL"<<endl;
        else
            cout<<"Left child = "<<pBaru->left->info<<endl;

        if (pBaru->right==NULL)
            cout<<"Right child = NULL"<<endl;
        else
            cout<<"Right child = "<<pBaru->right->info<<endl;

        cout<<endl;

        child(Root->left,pBaru);
        child(Root->right,pBaru);
    }
}

int main () {
    tree Root=NULL;
    pointer p;
    int pil,n;
    char jwb;

    cout<<"Masukkan banyak data : ";cin>>n;
    for (int i=0;i<n;i++) {
        CreateSimpul(p);
        insertBST(Root,p);
    }

    do {
        system("CLS");
        cout<<"1. Insert BST\n";
        cout<<"2. PreOrder\n";
        cout<<"3. InOrder\n";
        cout<<"4. PostOrder\n";
        cout<<"5. Kedalaman\n";
        cout<<"6. Level\n";
        cout<<"7. Anak\n";
        cout<<"8. Exit\n";
        cout<<endl;
        cout<<"Masukkan pilihan : "; cin>>pil;

    switch(pil) {
        case 1 :
            cout<<"\nInsert BST\n";
            CreateSimpul(p);
            insertBST(Root,p);
            break;

        case 2 :
            cout<<"\nPreOrder\n";
            preOrder(Root);
            break;

        case 3 :
            cout<<"\nInOrder\n";
            inOrder(Root);
            break;

        case 4 :
            cout<<"\nPostOrder\n";
            postOrder(Root);
            break;

        case 5 :
            cout<<"\nKedalaman\n";
            depth(Root);
            break;

        case 6 :
            cout<<"\nLevel\n";
            levelOrder(Root);
            break;

        case 7 :
            cout<<"\nAnak\n";
            child(Root,p);
            break;

        case 8 :
            cout<<endl;
            return 0;
            break;

        default :
            cout<<"Maaf anda salah input\n";
            break;
        }
        cout<<"Kembali ke menu?(Y/N)"; cin>>jwb;
    }
    while (jwb=='y'||jwb=='Y');
}

