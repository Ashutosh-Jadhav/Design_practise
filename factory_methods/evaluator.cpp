// first Design

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Questions {
    public:
    string type;
    string q;
    string ans;

    public:
    Questions(string t,string question , string answer) {
        this->type = t;
        this->q = question;
        this->ans = answer;
    }
    void display(string q, string ans) {
        cout << "Question : " << q << endl;
        cout << "Answer : " << ans <<endl;
    }
    // virtual void display_type(string type);
};

class Fillin : public Questions {

};

class Mcq : public Questions {
    
};

class Essay : public Questions {

};

class TrueOrFalse : public Questions {

};

class Evaluator {
    public:
    Questions *p;

    public:
    Evaluator(Questions *p) {
        this->p = p;
    }
    void eval(Questions *p) {
        if (p->type == "mcq") {
            cout << "Evaluated " << p->ans << " as per JEE main MCQ question." << endl;
        }
        else if(p->type == "fillin") {
            cout << "Evaluated " << p->ans << " as per JEE main Fillin question." << endl;  
        }
        else if(p->type == "essay") {
            cout << "Evaluated " << p->ans << " as per JEE main Eassy question." << endl;  
        }
        else if(p->type == "trueorfalse") {
            cout << "Evaluated " << p->ans << " as per JEE main T/F question." << endl;  
        }
    }
};

int main(){
    vector<string> types = {"mcq","fillin","essay","trueorfalse"};
    vector<string> q_s = {"Which Option is correct ?","Which Jargon suits here?","Write an Eassay?","True Or False?"};
    vector<string> answers = {"Option A","Brown Field","Big Esaay soon...","True"};
    Questions *q1; Evaluator *e1;
    for (int i = 0 ; i < 4 ; i++) {
        cout << "-------------------------------------------------" << endl;
        q1 = new Questions(types[i],q_s[i],answers[i]);
        e1 = new Evaluator(q1);
        e1->eval(q1);
        delete q1;
        delete e1;
    }
    return 0;
}