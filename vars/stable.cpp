#include "stable.h"
#include <iostream>


void Variable::saveData() {
    if (bound()) {
        cout << "Saved Data!" << endl;
    }
}

bool Variable::bound() {
    return !_handle.empty();
}

void Variable::bind(const string &handle) {
    _handle = handle;
}

void Variable::unbind() {
    _handle = "";
}

double Variable::get() {
    return _val;
}

void Variable::update(double val) {
    _val = val;
}

void Variable::set(double val) {
    _val = val;
    saveData();
}

bool SymbolTable::exists(const string &name) {
    return _vars.find(name) != _vars.end();
}

void SymbolTable::bind(const string &var, const string &handle) {
    _vars[var].bind(handle);
}

void SymbolTable::unbind(const string &var) {
    _vars[var].unbind();
}

void SymbolTable::update(const string &var, double newVal) {
    _vars[var].update(newVal);
}

void SymbolTable::set(const string &var, double val) {
    _vars[var].set(val);
}

double SymbolTable::get(const string &name) {
    return _vars[name].get();
}

unordered_map<string, double> SymbolTable::asMap() {
    unordered_map<string, double> m;

    for (pair<string, Variable> pair : _vars) {
        m.insert({ pair.first, pair.second.get() });
    }

    return m;
}