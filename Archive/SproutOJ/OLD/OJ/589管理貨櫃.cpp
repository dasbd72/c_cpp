#include <iostream>
#include <string>
using namespace std;

struct Container {
    int index; // ³fÂd½s¸¹
    int weight; // ³fÂd­«¶q
    Container *next; 
};
Container* insert(Container* head, int index, int weight);
Container* remove(Container* head, int max_weight);

// your code will be put here

int main() {

    Container *head = nullptr;
    int N;
    cin>>N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int index, weight;
            cin >> index >> weight;
            head = insert(head, index, weight);
        } else if (cmd == "remove") {
            int max_weight;
            cin >> max_weight;
            head = remove(head, max_weight);
        }
    }

    // list all
    Container *cur = head;
    while (cur!=nullptr) {
        cout << cur->index << " " << cur->weight << endl;
        cur = cur->next; 
    }
}
Container* insert(Container* head, int index, int weight){
    if(head == nullptr){
        head = new Container();
        head->index = index;
        head->weight = weight;
        head->next = nullptr;
    }
    else{
        Container *cur = head;
        if(index < cur->index){
            head = new Container();
            head->next = cur;
            head->index = index;
            head->weight = weight;
        }
        else{
            while(cur->next != nullptr && cur->next->index < index) cur = cur->next;
            Container *to_add = new Container();
            to_add->next = cur->next;
            to_add->index = index;
            to_add->weight = weight;
            cur->next = to_add;
        }
    }
    return head;
}
Container* remove(Container* head, int max_weight){
    if(head == nullptr) return head;
    else if(head->weight == max_weight) head = head->next;
    else{
        Container *cur = head;
        while(cur->next != nullptr){
            if(cur->next->weight == max_weight){
                cur->next = cur->next->next;
                break;
            }
            else cur = cur->next;
        }
    }
    return head;
}