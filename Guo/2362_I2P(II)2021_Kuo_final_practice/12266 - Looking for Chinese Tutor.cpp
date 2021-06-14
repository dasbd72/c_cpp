#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> _poke;
    _poke["Wa"] = "Waninoko";
    _poke["Mi"] = "Milotic";
    _poke["Ma"] = "Magikarp";
    _poke["Va"] = "Vaporeon";
    _poke["Sh"] = "Sharpedo";
    _poke["Tapu"] = "Tapu Fini";
    _poke["Em"] = "Empoleon";
    _poke["La"] = "Lapras";
    _poke["Pi"] = "Pikachu";
    _poke["Pe"] = "Pikachu";
    _poke["Me"] = "Mega Gyarados";

    int n;
    string name, school;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> school;
        if (name.length() >= 2 && _poke.find(name.substr(0, 2)) != _poke.end()) {
            cout << name + " the " + school + " " + _poke[name.substr(0, 2)] + "\n";
        } else if (name.length() >= 4 && _poke.find(name.substr(0, 4)) != _poke.end()) {
            cout << name + " the " + school + " " + _poke[name.substr(0, 4)] + "\n";
        } else {
            cout << name + " is looking for a Chinese tutor, too!\n";
        }
    }
}